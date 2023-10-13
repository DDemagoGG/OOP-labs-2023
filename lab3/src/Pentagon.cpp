#include "Pentagon.hpp"

Pentagon::Pentagon(const Point& newUpAngle, const Point& newRightUpAngle, const Point& newRightDownAngle, const Point& newLeftDownAngle,
  const Point& newLeftUpAngle) : leftUpAngle(newLeftUpAngle), leftDownAngle(newLeftDownAngle), rightDownAngle(newRightDownAngle), 
    rightUpAngle(newRightUpAngle), upAngle(newUpAngle){

}

Pentagon::~Pentagon(){

}

Point Pentagon::getCenter(){
    double a = sqrt((upAngle.getX() - leftUpAngle.getX()) * (upAngle.getX() - leftUpAngle.getX()) + (upAngle.getY() - leftUpAngle.getY()) *  (upAngle.getY() - leftUpAngle.getY()));
    double R = a / (2 * sin(M_PI / 5));
    return Point{upAngle.getX(), (upAngle.getY() - R)};
}

std::ostream& operator << (std::ostream &os, const Pentagon& pentagon){
    return os << pentagon.leftDownAngle << ' ' << pentagon.leftUpAngle << ' ' << pentagon.rightDownAngle << ' ' << pentagon.rightUpAngle << ' ' << pentagon.upAngle;
}

std::istream& operator >> (std::istream& is, Pentagon& pentagon){
    is >> pentagon.leftDownAngle >> pentagon.leftUpAngle >> pentagon.rightDownAngle >> pentagon.rightUpAngle >> pentagon.upAngle;
    return is;
}

Pentagon::operator double(){
    double a = sqrt((upAngle.getX() - leftUpAngle.getX()) * (upAngle.getX() - leftUpAngle.getX()) + (upAngle.getY() - leftUpAngle.getY()) *  (upAngle.getY() - leftUpAngle.getY()));
    double s = 5 * a * a / (tan(M_PI / 5) * 4);
    return s; 
}