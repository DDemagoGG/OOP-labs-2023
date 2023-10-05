#pragma once

#include <iostream>
#include <exception>
#include <algorithm>

class Five{
    size_t size;
    unsigned char* num;
public:
    Five();
    Five(const std::string &t);
    Five(const std::initializer_list<unsigned char> &l);
    Five(const Five& other);
    ~Five();
    void print() const;
    unsigned char* getNumber() const;
    int getSize() const;
    Five operator + (const Five& other) const;
    Five& operator = (const Five& other);
    int operator == (const Five& other) const;
    int operator != (const Five& other) const;
    Five operator - (const Five& other) const;
    int operator < (const Five& other) const;
    int operator > (const Five& other) const;
    int operator >= (const Five& other) const;
    int operator <= (const Five& other) const;
};
