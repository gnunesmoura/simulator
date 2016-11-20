#include <init/movement.hpp>

double Movement::move (bool neighbor) {
    std::vector<Edge> * anchors = node->getAnchors();
    int nAnchors = anchors->size();
    Vector move;
    Edge e;
    for (int i = 0; i < nAnchors; ++i) {
        e = anchors->at(i);
        Vector sum (e.b, node, e.dist);
        Vector sub (node, e.b);
        move = move + sum;
        move = move + sub;
    }

    move = move * (1/(double)nAnchors);
    node->newPos (move.get(Axis::x)+node->get(Axis::x), move.get(Axis::y)+node->get(Axis::y));

    return move.getNorm();
}