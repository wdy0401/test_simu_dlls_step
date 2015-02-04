#ifndef ORDER_H
#define ORDER_H
#include<string>

struct order
{
    std::string ordername;

    std::string symbol;
    std::string openclose;
    std::string buysell;
    double price;
    long size;

    long size_to_fill;
    long size_filled;
};

#endif // ORDER_H
