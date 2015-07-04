#include "optionf.h"
#include"math.h"
#include "../../gpp_qt/wfunction/wmath.h"

using namespace std;\

optionf::optionf()
{
}

void optionf::set_vol(long second,double price)
{
    vol_map[second]=price;
    vol_list.push_front(price);


    map <long,map<long,double>*>::iterator iter=vol_snap_map.begin();
    while(iter!=vol_snap_map.end())
    {
        if((*(iter->second)).find(second/iter->first)==(*(iter->second)).end())
        {
            (*iter->second)[second/iter->first]=price;
            vol_snap_list.find(iter->first)->second->push_front(price);
        }
    }
}
double optionf::get_vol()
{   
    return wmath::stdev(&vol_list);
}
double optionf::get_vol_adjust()
{
    map<long,double>::iterator it1=vol_map.begin();
    map<long,double>::iterator it2=it1;it2++;
    if(it2==vol_map.end())
    {
        return 0;
    }
    long time_length=0;
    double sum_vol=0;
    double sum_ave=0;
    while(it1!=vol_map.end())
    {
        if(it2!=vol_map.end())
        {
            long time_dur=it2->first-it1->first;
            sum_vol+=(time_dur-1)*(it2->second+it1->second)*(it2->second+it1->second)/4 + it1->second*it1->second;
            sum_ave+=it1->second+(time_dur-1)*(it2->second+it1->second)/2;
            time_length+=time_dur;
        }
        else
        {
            sum_vol+=it1->second*it1->second;
            sum_ave+=it1->second;
        }
        it1++;
        it2++;
    }
    return sqrt((sum_vol-sum_ave*sum_ave/(time_length+1))/time_length);
}
double optionf::get_vol(long seconds)
{
    map <long,map<long,double>*>::iterator iter=vol_snap_map.find(seconds);
    if(iter!=vol_snap_map.end())
    {
        return wmath::stdev(vol_snap_list.find(seconds)->second);
    }
    else
    {
        map<long,double> * new_map=new map<long,double>;
        list<double> * new_list=new list<double>;
        vol_snap_map[seconds]=new_map;
        vol_snap_list[seconds]=new_list;
        map<long,double>::iterator it=vol_map.begin();
        while(it!=vol_map.end())
        {
            long sec=it->first;
            double value=it->second;
            if(new_map->find(sec/seconds)==new_map->end())
            {
                (*new_map)[sec/seconds]=value;
                new_list->push_back(value);
            }
            it++;
        }
    }
    return wmath::stdev(vol_snap_list.find(seconds)->second);
}

