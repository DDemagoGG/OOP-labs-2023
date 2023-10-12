#include "Figure.hpp"

class Rhombus : public Figure{
    friend std::ostream& operator << (std::ostream &os, const Rhombus& trapezoid);
    friend std::istream& operator >> (std::istream& is, Rhombus& trapezoid);
    Point upAngle;
    Point rightAngle;
    Point downAngle;
    Point leftAngle;
public:
    Rhombus() = default;
    Rhombus(const Point& newUpAngle, const Point& newRightAngle, const Point& newLeftAngle, const Point& newDownAngle);
    ~Rhombus();
    virtual Point getCenter();
    virtual operator double();
};