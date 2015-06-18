#ifndef OPTIONF_H
#define OPTIONF_H

#include "optionf_global.h"

#include <math.h>
#include <map>

class OPTIONFSHARED_EXPORT optionf
{

public:
    optionf();
    void set_vol(long second,double price);
    double get_vol();

private:
    std::map<long,double> vol_list;
};

#endif // OPTIONF_H
