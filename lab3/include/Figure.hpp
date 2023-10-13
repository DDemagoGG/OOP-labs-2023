#pragma once

#include "Point.hpp"

class Figure{
public:
    Figure() = default;
    ~Figure();
    virtual Point getCenter() = 0;
    virtual operator double() = 0;
};