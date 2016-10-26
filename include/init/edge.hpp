// #ifndef edge_h
// #define edge_h

#include <init/enum.hpp>
// #include <init/node.hpp>

class Edge {
public:
    void * b;
    double dist;
    Edge (void * b, double dist) {this->b = b; this->dist = dist; }
    ~Edge () {}
};


// #endif
