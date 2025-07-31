#include "Point.hpp"

static Fixed sign(Point const p1, Point const p2, Point const p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - 
           (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;
    Fixed ref(0);
    bool has_neg, has_pos;
    
    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);
    
    if (d1 == ref || d2 == ref || d3 == ref)
        return false;
    
    has_neg = (d1 < ref) || (d2 < ref) || (d3 < ref);
    has_pos = (d1 > ref) || (d2 > ref) || (d3 > ref);
    
    return !(has_neg && has_pos);
}