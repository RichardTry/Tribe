#ifndef DSQ_H_INCLUDED
#define DSQ_H_INCLUDED

#include "map.h"
#include <unordered_map>

struct DiamondSquare
{
    std::unordered_map<long long, bool> data_exists;
    std::unordered_map<long long, uint8_t> data;
    uint8_t getHeight(int a, int b);
};

#endif // DSQ_H_INCLUDED
