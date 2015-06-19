#ifndef OPTIONF_H
#define OPTIONF_H

#include "optionf_global.h"

#include <math.h>
#include <map>
#include <list>

class OPTIONFSHARED_EXPORT optionf
{

public:
    optionf();
    void set_vol(long second,double price);
    double get_vol();

private:
    std::list <double> vol_list;
    std::map<long,double> vol_map;
};

#endif // OPTIONF_H
