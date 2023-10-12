#include "Figure.hpp"

class Trapezoid : public Figure{
    friend std::ostream& operator << (std::ostream &os, const Trapezoid& trapezoid);
    friend std::istream& operator >> (std::istream& is, Trapezoid& trapezoid);
    Point leftUpAngle;
    Point rightUpAngle;
    Point leftDownAngle;
    Point rightDownAngle;
public:
    Trapezoid() = default;
    Trapezoid(const Point& newLeftUpAngle, const Point& newRightUpAngle, const Point& newLeftDownAngle, const Point& newRightDownAngle);
    ~Trapezoid();
    virtual Point getCenter();
    virtual operator double();
};