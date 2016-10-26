#include <init/node/node.hpp>

double Node::get (Axis a) {
    if(a == Axis::x) return this->x;
    else return this->y;
}

Type Node::getType () {
    return this->type;
}

void Node::newPos (double x, double y) {
    this->x = x;
    this->y = y;
}

void Node::setType (Type a) {
    this->type = a;
}
