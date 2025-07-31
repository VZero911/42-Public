#include <iostream>
#include "Point.hpp"

int main(void) {
    std::cout << "=== BSP Triangle Test ===" << std::endl;
    
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    
    std::cout << "\nTriangle vertices:" << std::endl;
    std::cout << "A(" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "B(" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "C(" << c.getX() << ", " << c.getY() << ")" << std::endl;
    
    std::cout << "\n=== Test Cases ===" << std::endl;
    
    Point inside(2.5f, 2.0f);
    std::cout << "Point (" << inside.getX() << ", " << inside.getY() << ") is ";
    std::cout << (bsp(a, b, c, inside) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
    
    Point outside(6.0f, 3.0f);
    std::cout << "Point (" << outside.getX() << ", " << outside.getY() << ") is ";
    std::cout << (bsp(a, b, c, outside) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
    
    Point vertex(0.0f, 0.0f);
    std::cout << "Point (" << vertex.getX() << ", " << vertex.getY() << ") is ";
    std::cout << (bsp(a, b, c, vertex) ? "INSIDE" : "OUTSIDE") << " the triangle (vertex test)" << std::endl;

    Point edge(2.5f, 0.0f);
    std::cout << "Point (" << edge.getX() << ", " << edge.getY() << ") is ";
    std::cout << (bsp(a, b, c, edge) ? "INSIDE" : "OUTSIDE") << " the triangle (edge test)" << std::endl;
    
    Point inside2(1.5f, 1.0f);
    std::cout << "Point (" << inside2.getX() << ", " << inside2.getY() << ") is ";
    std::cout << (bsp(a, b, c, inside2) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
    
    Point outside2(-1.0f, -1.0f);
    std::cout << "Point (" << outside2.getX() << ", " << outside2.getY() << ") is ";
    std::cout << (bsp(a, b, c, outside2) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}