#include <init/node.hpp>

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

void Node::addEdge (Node * b, double dist) {
    Edge e(b, dist);
    if(b->getType() == Type::anchor) anchor.push_back(e);
    else neighbor.push_back(e);
}

size_t Node::getNAnchors () {
    return anchor.size();
}

size_t Node::getNNeighbors () {
    return neighbor.size();
}
