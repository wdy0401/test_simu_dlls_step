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

