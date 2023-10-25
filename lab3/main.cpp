#include "List.hpp"
#include "Trapezoid.hpp"
#include "Rhombus.hpp"

int main(){
    Trapezoid trap{Point{2, 3}, Point{5, 3}, Point{0, 0}, Point{7, 0}};
    Trapezoid * t1 = new Trapezoid(Point{2, 3}, Point{5, 3}, Point{0, 0}, Point{7, 0});
    ListFigure l{t1};
    return 0;
}