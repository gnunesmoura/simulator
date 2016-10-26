#ifndef node_h
#define node_h

#include <vector>
#include <init/enum/enum.hpp>

class Node {
private:
    double x, y;
    // Adicionar arestas.
    // std::vector<Node*> anchor;
    // std::vector<Node*> neighbor;
    Type type;
public:

    Node (double x, double y, Type t) {this->x = x; this->y = y; this->type = t; }
    ~Node () {};
    double get (Axis a);
    Type getType ();
    void newPos (double x, double y);
    void setType(Type t);
};

#endif
