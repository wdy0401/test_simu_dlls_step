#if defined(TACTIC_LIBRARY)
#define TACTIC_EXPORT Q_DECL_EXPORT
#else
#define TACTIC_EXPORT Q_DECL_IMPORT
#endif

#ifndef TACTIC_H
#define TACTIC_H

#include <QtCore/qglobal.h>
#include<QObject>
#include<string>
#include "../parameter.h"
#include"../../gpp_qt/wtimer/wtimer.h"

//############################################################
//simu mode
#ifdef SIMU
#include"../snapshot/snapshot.h"
#include"../match_engine/match_engine.h"
#define ctp_order_manager match_engine
#define CThostFtdcDepthMarketDataField snapshot
#else
#include"../libs/ctp/ThostFtdcMdApi.h"
#endif
//############################################################

class ctp_order_manager;
class TACTIC_EXPORT tactic: public QObject
{
    Q_OBJECT
public:
#ifdef SIMU
    void set_match_engine(ctp_order_manager * p){om=p;}
#else
    void set_ctp_order_manager(ctp_order_manager * p){om=p;}
#endif
    tactic *genp(){return new tactic;}
    void init();
    void send_order();
    void set_timer(wtimer * p){timer=p;}
signals:
    void tactic_info(const std::string & info);
public slots:
    virtual void book(const CThostFtdcDepthMarketDataField *p);
    virtual void quote(const std::string & symbol, const std::string & ba, long level, double price, long quotesize);
    virtual void ack(const std::string & ordername,const std::string & type,const std::string & info);
    virtual void done(const std::string & ordername,const std::string & type,const std::string & info);
    virtual void rej(const std::string & ordername,const std::string & type,const std::string & info);
    virtual void fill(const std::string & ordername,const std::string & symbol,const std::string & buysell,double price, long size);
 private:
    ctp_order_manager * om;
    wtimer * timer;
};

#endif // TACTIC_H
