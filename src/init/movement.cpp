#include <init/movement.hpp>

Movement::Movement (Node * node, double noise, double range) {
    this->node = node;
    this->noise = noise;
    this->range = range;
    Vector v;
    this->biggerStress = v;
    this->acceptableError = noise*range;
    if(this->acceptableError < 0.000000001) this->acceptableError = 0.000000001;
    this->newPos(this->largerVector());
}

double Movement::move (bool placed) {
    if(node->getType() == Type::anchor) return 0; //se for ancora não move
    std::vector<Edge> * anchors = node->getAnchors();
    std::vector<Edge> * placeds = node->getPlaceds();
    int nAnchors = anchors->size();
    int nPlaceds = placeds->size();
    Vector move;
    Edge e;
    if (nAnchors != 0) { //se não tiver nenhum ancora não calcula o movimento.
        for (int i = 0; i < nAnchors; ++i) {
            move = move + this->movement(anchors->at(i));
        }
    }
    if (placed) {
        if(placeds->size() > 0) {
            for (int i = 0; i < nPlaceds; ++i) {
                move = move + this->movement(placeds->at(i));
            } 
        }
    }

    double mult = nAnchors + nPlaceds;

    if(mult != 0) {
        move = move * (1/mult);
    }
    

    this->newPos(move);
    return move.getNorm();
}

void Movement::releaseStress () {
    Edge e = strongestEdge ();
    if(e.b != NULL) {
        newPos(movement(e));
        Vector sub (node, e.b, e.dist*2);
        newPos(sub);
    }
} 

bool Movement::stress () {
    this->biggerStress = this->largerVector();
    if (biggerStress.getNorm() > acceptableError) {
        return true;
    }
    // std::vector<Edge> * e = node->getAnchors();
    // for (int i = 0; i < e->size(); ++i) {
        
    // }
    return false;
}

inline void Movement::newPos (Vector move) {
    double x = node->get(Axis::x) + move.get(Axis::x);
    double y = node->get(Axis::y) + move.get(Axis::y);
    node->newPos(x, y);
}

inline Vector Movement::movement (Edge e) {
    Vector move;
    Vector sum (e.b, node, e.dist);
    Vector sub (node, e.b);
    move = move + sum;
    move = move + sub;
    return move;
}

Vector Movement::largerVector () {
    std::vector<Edge> * e = node->getAnchors();
    Vector larger;
    Vector v;
    int size = e->size();
    for(int i = 0; i < size; ++i) {
        v = movement(e->at(i));
        if(v.getNorm() > larger.getNorm()) larger = v;
    }
    if(size == 0) {
         e = node->getPlaceds(); 
        size = e->size();
        for(int i = 0; i < size; ++i) {
            v = movement(e->at(i));
            if(v.getNorm() > larger.getNorm()) larger = v;
        }
    }
    return larger;
}

Edge Movement::strongestEdge (){
    std::vector<Edge> * e = node->getAnchors();
    Edge strongest;
    int size = e->size();
    if(size != 0) {
        strongest = (*e)[0];
    }
    for(int i = 0; i < size; ++i) {
        if((*e)[i].dist < strongest.dist){ 
            strongest = e->at(i);
        }
    }
    if(size == 0) {
        e = node->getPlaceds(); 
        size = e->size();
        if(size != 0) {
            strongest = (*e)[0];
        }
        for(int i = 0; i < size; ++i) {
             if((*e)[i].dist < strongest.dist){ 
                strongest = e->at(i);
            }
        }
    }
    return strongest;
}

int Movement::nVectors () {
    return node->getNPlaceds() + node->getNAnchors();
}