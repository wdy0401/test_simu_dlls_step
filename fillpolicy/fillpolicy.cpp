#include "fillpolicy.h"
#include<QDebug>
#include<QPluginLoader>
#include<QFileInfo>
#include"../../gpp_qt/wfunction/qtfunction.h"
using namespace std;

fillpolicy::fillpolicy(QObject *parent) :
    QObject(parent)
{
    fpnames.push_front("cross_fill");
    fpnames.push_front("queue_fill");
}
void fillpolicy::init()
{
}
void fillpolicy::rec_quote(const std::string & symbol,const std::string & bidask,long level,double price,long size)
{
    static std::map<std::string,orderbook * >::iterator iter;
    iter=ob.find(symbol);
    if(iter!=ob.end())
    {
        iter->second->updateorderbook(bidask,level,price,size);
    }
    else
    {

        orderbook * tob= ((orderbook *)(qtfunction::load_dll("orderbook")))->genp();

       // orderbook * tob=new orderbook;
        ob[symbol]=tob;
        tob->updateorderbook(bidask,level,price,size);
    }
    check_fill(symbol);
}

void fillpolicy::rec_new_order(const std::string ordername,const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size)
{
    qDebug()<<"fillpolicy rec_new_order\n";
    order * tmporder=new order;
    tmporder->ordername=ordername;
    tmporder->symbol=symbol;
    tmporder->buysell=buysell;
    tmporder->openclose=openclose;
    tmporder->price=price;
    tmporder->size=size;
    tmporder->size_to_fill=size;
    tmporder->size_filled=0;
    tmporder->queue_position=-1;
    _pend_order[ordername]=tmporder;
}

void fillpolicy::check_fill(const string & symbol)
{
    check_fill(symbol,this->fpname);
}

void fillpolicy::check_fill(const string & symbol,const string &fpn)
{
    if(fpn=="cross_fill")
    {
        //消息fill					检测run上有哪些order可成交 成交之
        //转区fill					将成交完成的移入done list
        //消息change ack rej done	检测run done这两个list中的change tag 并处理之
        //转区						将pend区转换到run区

        //消息fill
        //转区fill

       orderbook * now_ob=ob[symbol];
        if(now_ob->init_done()==false)
        {
            return;
        }
        for(map<string,order *>::iterator iter=_run_order.begin(); iter!=_run_order.end();)
        {
            qDebug()<<"orderprice"                        <<"\t"<<iter->second->price                      <<"\t"<< iter->second->buysell.c_str()                          <<"\t"<<now_ob->getaskprice()                        <<"\t"<< now_ob->getbidprice()                        <<endl;
            if(iter->second->price>=now_ob->getaskprice() && iter->second->buysell=="BUY")
            {
                emit fill(iter->first,symbol,"BUY",now_ob->getaskprice(),iter->second->size_to_fill);
                _done_order[iter->first]=iter->second;
                _run_order.erase(iter++);
            }
            else if(iter->second->price<=now_ob->getbidprice() &&iter->second->buysell=="SELL")
            {
                emit fill(iter->first,symbol,"SELL",now_ob->getbidprice(),iter->second->size_to_fill);
                _done_order[iter->first]=iter->second;
                _run_order.erase(iter++);
            }
            else
            {
                ++iter;
            }
        }

        //消息change
        //成功部分
        /*
        for(map<string,order *>::iterator iter=_run_order.begin(); iter!=_run_order.end();)
        {
            if(iter->second->_tag_cancel)
            {
                iter->second->changeack("cancel");
                _done_order[iter->first]=iter->second;
                iter->second->changedone("cancel");
                _run_order.erase(iter++);
                continue;
            }
            else
            {
                ++iter;
                continue;
            }
            if(iter->second->_tag_changeprice)
            {
                iter->second->changeack("price");
                iter->second->price=iter->second->_tag_changeprice;
                iter->second->changedone("price");
            }
            if(iter->second->_tag_changesize)
            {

                iter->second->changeack("size");
                iter->second->price=iter->second->_tag_changesize;
                iter->second->changedone("size");
            }
            ++iter;
        }
        //失败部分
        for(map<string,order *>::iterator iter=_done_order.begin();iter!=_done_order.end();iter++)
        {
            if(iter->second->_tag_cancel)
            {
                iter->second->changeack("cancel");
                iter->second->changerej("cancel");
            }
            if(iter->second->_tag_changeprice)
            {
                iter->second->changeack("price");
                iter->second->changerej("price");
            }
            if(iter->second->_tag_changesize)
            {
                iter->second->changeack("size");
                iter->second->changerej("size");
            }
        }
        */
        //转区pend 并清空
        for(map<string,order *>::iterator iter=_pend_order.begin();iter!=_pend_order.end();iter++)
        {
            _run_order[iter->first]=iter->second;
        }
        _pend_order.clear();

        return;
    }
    if(fpn=="queue_fill")
    {

    }

}

