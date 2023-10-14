#pragma once

#include "Figure.hpp"

class ListFigure{
    Figure ** data;
    int size;
public:
    ListFigure();
    ListFigure(const std::initializer_list<Figure *> &l);
    void push(Figure * fig);
    virtual operator double();
    void deleteFigure(int i);
};