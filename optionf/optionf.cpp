#include "optionf.h"
#include "../../gpp_qt/wfunction/wmath.h"

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

