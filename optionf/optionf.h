#if defined(OPTIONF_LIBRARY)
#  define OPTIONFSHARED_EXPORT Q_DECL_EXPORT
#else
#  define OPTIONFSHARED_EXPORT Q_DECL_IMPORT
#endif

#ifndef OPTIONF_H
#define OPTIONF_H

#include <QtCore/qglobal.h>

class OPTIONFSHARED_EXPORT optionf
{

public:
    optionf();
    double cal_delta(double uprice,double sprice,double vol,double lt,double interest,double divident);
    double cal_gamma(double uprice,double sprice,double vol,double lt,double interest,double divident);
    double cal_vega(double uprice,double sprice,double vol,double lt,double interest,double divident);
    double cal_theta(double uprice,double sprice,double vol,double lt,double interest,double divident);
    double cal_rho(double uprice,double sprice,double vol,double lt,double interest,double divident);

    double cal_delta(double uprice,double sprice,double vol,double lt,double interest){return cal_delta(uprice, sprice, vol, lt, interest,0);}
    double cal_delta(double uprice,double sprice,double vol,double lt){return cal_delta(uprice, sprice, vol, lt, 0,0);}
    double cal_gamma(double uprice,double sprice,double vol,double lt,double interest){return cal_gamma(uprice, sprice, vol, lt, interest,0);}
    double cal_gamma(double uprice,double sprice,double vol,double lt){return cal_gamma(uprice, sprice, vol, lt, 0,0);}
    double cal_vega(double uprice,double sprice,double vol,double lt,double interest){return cal_vega(uprice, sprice, vol, lt, interest,0);}
    double cal_vega(double uprice,double sprice,double vol,double lt){return cal_vega(uprice, sprice, vol, lt, 0,0);}
    double cal_theta(double uprice,double sprice,double vol,double lt,double interest){return cal_theta(uprice, sprice, vol, lt, interest,0);}
    double cal_theta(double uprice,double sprice,double vol,double lt){return cal_theta(uprice, sprice, vol, lt, 0,0);}
    double cal_rho(double uprice,double sprice,double vol,double lt,double interest){return cal_rho(uprice, sprice, vol, lt, interest,0);}
    double cal_rho(double uprice,double sprice,double vol,double lt){return cal_rho(uprice, sprice, vol, lt, 0,0);}

};

#endif // OPTIONF_H
