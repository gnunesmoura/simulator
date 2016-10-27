#ifndef physics_h
#define physics_h

#include <node.hpp>

class Force{
private:
    Node * a;
    Node * b;
    double speed_up;
public:
    Force (Node * a, Node * b) {this->a = a; this->b = b, this->speed_up = 0.05; }
    ~Force () {}
    void speedUp (double multiplier);
    void slowDown (double divider);
}

#endif
