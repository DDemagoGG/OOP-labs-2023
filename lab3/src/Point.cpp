#include "Point.hpp"

Point::Point(double newX, double newY) : x(newX), y(newY){

}

Point::~Point(){

}

Point::Point(const Point& other){
    x = other.x;
    y = other.y;
}

double Point::getX(){
    return x;
}

double Point::getY(){
    return y;
}

std::ostream& operator << (std::ostream &os, const Point& point){
    return os << point.x << ' ' << point.y;
}

std::istream& operator >> (std::istream& is, Point& point){
    is >> point.x;
    is >> point.y;
    return is;
}

int Point::operator==(const Point& other) const{
    if ((x == other.x) and (y == other.y)){
        return 1;
    }
    return 0;
}

Point& Point::operator=(const Point& other){
    x = other.x;
    y = other.y;
    return *this;
}