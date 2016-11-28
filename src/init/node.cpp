#include <init/node.hpp>

int Node::getId () {
    return id;
}

double Node::get (Axis a) {
    if(a == Axis::x) return this->x;
    else return this->y;
}

Type Node::getType () {
    return this->type;
}

void Node::newPos (double x, double y) {
    // std::cout << "Old:\n";
    // this->print();
    this->x = x;
    this->y = y;
    // std::cout << "New:\n";
    // this->print();
    // wait;
}

void Node::setType (Type a) {
    if(this->type == a) return;
    this->type = a;
    if(a == Type::placed) {
        int size = neighbor.size();
        for(int i = 0; i < size; ++i) {
            neighbor[i].b->notifyPlacement(this);
        }
        size = anchor.size();
        for(int i = 0; i < size; ++i) {
            anchor[i].b->notifyPlacement(this);
        }
    }
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

size_t Node::getNPlaceds() {
    return placed.size();
}

std::vector<Edge> * Node::getAnchors () {
    return &anchor;
}

std::vector<Edge> * Node::getNeighbors () {
    return &neighbor;
}

std::vector<Edge> * Node::getPlaceds () {
    return &placed;
}

void Node::print () {
    std::cout << id;
    std::cout << "\tx = " << this->x;
    std::cout << "\ty = " << this->y;
    std::cout << "\ttype = " << type << std::endl;
}

void Node::printPlaceds () {
    int size = placed.size();
    for(int i = 0; i < size; ++i) {
        std::cout << " " << placed[i].b->getId() << " " << placed[i].dist;
    }
    std::cout << " -1 0\n";

    for(int i = 0; i < size; ++i) {
       placed[i].b->print();
    }
    std::cout << "\n";
}


void Node::printNeighbors () {
    int size = neighbor.size();
    for(int i = 0; i < size; ++i) {
        std::cout << " " << neighbor[i].b->getId() << " " << neighbor[i].dist;
    }
    std::cout << " -1 0\n";
}

void Node::printAnchors () {
    int size = anchor.size();
    for(int i = 0; i < size; ++i) {
        std::cout << " " << anchor[i].b->getId() << " " << anchor[i].dist;
    }
    std::cout << " -1 0\n";
}

void Node::printEdges (Type a) {
    std::cout << id;
    if(a == Type::anchor) printAnchors();
    else if (a == Type::placed) printPlaceds();
    else printNeighbors();
}

void Node::notifyPlacement (Node * node) {
    for(int i = 0; i < neighbor.size(); ++i) {
        if(node->getId() == neighbor[i].b->getId()) {
            Edge e(node, neighbor[i].dist);
            placed.push_back(e);
            break;
        }
    }
}

bool Node::biggerThen (Node * node) {
    if (anchor.size() > node->getNAnchors()) {
        return true;
    } else if (anchor.size() == node->getNAnchors()) {
        if (placed.size() > node->getNPlaceds()) {
            return true;
        } else if (placed.size() == node->getNPlaceds()) {
            if (neighbor.size() > node->getNNeighbors()) {
                return true;
            } else return false;
        } else return false;
    } else return false;
}

void Node::printGeo () {
    if(type == Type::anchor) {
        printf("A_{%d} = (%.5lf, %.5lf)\n", this->id, this->x, this->y);
    } else printf("N_{%d} = (%.5lf, %.5lf)\n", this->id, this->x, this->y);
}

void Node::printEdgesGeo () {
    this->printGeo();
    std::cout << "\n";

    int size = anchor.size();
    for(int i = 0; i < size; ++i) {
        anchor[i].b->printGeo();
        anchor[i].printGeo(this->id);
    }
    size = placed.size();
    for(int i = 0; i < size; ++i) {
        placed[i].b->printGeo();
        placed[i].printGeo(this->id);
    }

    printf("F_{%d} = Vector[N_{%d}, ", this->id, this->id);
    size = anchor.size();
    for(int i = 0; i < size; ++i) {
        printf(" F_{%d,%d} ", this->id, anchor[i].b->getId());
        if(i != size - 1) std::cout << "+";
    }
    size = placed.size();
    for(int i = 0; i < size; ++i) {
        printf(" F_{%d,%d} ", this->id, placed[i].b->getId());
        if(i != size - 1) std::cout << "+";
    }
    printf(" + N_{%d}]", this->id);
    std::cout << "\n\n";
}

bool Node::isNeighbor (Node * n) {
    for(int i = 0; i < anchor.size(); ++i) {
        if(anchor[i].b == n) return true;
    }
    for(int i = 0; i < neighbor.size(); ++i) {
        if(neighbor[i].b == n) return true;
    }
    return false;
} 

bool Node::inRange (Node * n, double range) {
    for (int i = 0; i < anchor.size(); ++i) {
        if (!anchor[i].b->isNeighbor(n)) {
            Vector v(n, anchor[i].b);
            if(v.getNorm() < range) return true;
        } 
    }
    for (int i = 0; i < placed.size(); ++i) {
        if (!placed[i].b->isNeighbor(n)) {
            Vector v(n, placed[i].b);
            if(v.getNorm() < range) return true;
        } 
    }
    return false;
}