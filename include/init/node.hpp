#ifndef node_h
#define node_h

#include <vector>
#include <init/enum.hpp>
#include <init/edge.hpp>

class Node {
private:
    double x, y;
    std::vector<Edge> anchor;
    std::vector<Edge> neighbor;
    Type type;
public:
    Node (double x, double y, Type t) {this->x = x; this->y = y; this->type = t; }
    ~Node () {};
    double get (Axis a);
    Type getType ();
    void newPos (double x, double y);
    void setType(Type t);
    void addEdge (Node * b, double dist);
};

#endif
