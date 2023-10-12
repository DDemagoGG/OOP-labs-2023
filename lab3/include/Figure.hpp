#include "Point.hpp"

enum class FigureType{
        Trapezoid,
        Rhombus,
        Pentagon
};

class Figure{
public:
    Figure() = default;
    Figure(FigureType newType);
    ~Figure();
    virtual Point getCenter() = 0;
    virtual operator double() = 0;
protected:
    FigureType type;
};