#include <init/system.hpp>

System::System  (Instance instance) {
    this->instance = instance;
    this->nodes = instance.getNodes();
}

void System::solve () {
    sortPriority();
    
    int size = nodes.size();

    for (int i = 0; i < size; ++i) {
        findPlace(nodes[i]);
    }

    for (int j = 0; j < 100; j++) {
        sortPriority();
        int msize = moves.size();
        for (int i = msize-1; i >=0 ; --i) {
            if (moves[i].stress()) {
                moves[i].releaseStress();
            }
            moveNode(moves[i], true, 0.00000000001);
        }

        for (int i = 0; i < size; ++i) {
            if (nodes[i]->getType() == Type::not_placed) {
                findPlace(nodes[i]);
            }
        } 
    }

}

void System::moveNode (Movement m, bool placed, double var) {
    while (m.move(placed) > var) {

    }
}

void System::findPlace (Node * node) {
    if (node->getType() == Type::anchor) return;
    Movement m(node, instance.getNoise(), instance.getRadioRange());
    
    if (node->getNAnchors() >= 3) {
        moveNode(m, false, 0.00000000001);
    } else if (node->getNAnchors() + node->getNPlaceds() >= 3) {
        moveNode(m, true, 0.00000000001);
    } else return;

    if (!m.stress()) {
        node->setType(Type::placed);
        moves.push_back(m);
    } else {
        m.releaseStress();
    }
}

void System::sortPriority () {
    int size = nodes.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (!nodes[i]->biggerThen(nodes[j])) {
                Node * aux;
                aux = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = aux;
            }
        }
    }
    size = moves.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (moves[i].nVectors() > moves[j].nVectors()) {
                Movement aux;
                aux = moves[i];
                moves[i] = moves[j];
                moves[j] = aux;
            }
        }
    }
}