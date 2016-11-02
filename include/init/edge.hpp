#pragma once

#include <init/enum.hpp>


class Node;

class Edge {
public:
    Node * b;
    double dist;
    Edge (Node * b, double dist) {this->b = b; this->dist = dist; }
    ~Edge () {}
};
