#include <init/edge.hpp>
#include <init/node.hpp>

void Edge::printGeo (int id){
    int idB = b->getId();
    if(b->getType() == Type::anchor) {
        printf("C_{%d,%d} = Circle[A_{%d}, %.5lf]\n", idB, id, idB, dist);
        printf("L_{%d,%d} = Ray[A_{%d}, N_{%d}]\n", idB, id, idB, id);
        printf("P_{%d,%d} = Intersect[C_{%d,%d}, L_{%d,%d}]\n", idB, id, idB, id, idB, id);
        printf("F_{%d,%d} = Vector[N_{%d}, P_{%d,%d}]\n", id, idB, id, idB, id);
    } else {
        printf("C_{%d,%d} = Circle[N_{%d}, %.5lf]\n", idB, id, idB, dist);
        printf("L_{%d,%d} = Ray[N_{%d}, N_{%d}]\n", idB, id, idB, id);
        printf("P_{%d,%d} = Intersect[C_{%d,%d}, L_{%d,%d}]\n", idB, id, idB, id, idB, id);
        printf("F_{%d,%d} = Vector[N_{%d}, P_{%d,%d}]\n", id, idB, id, idB, id);
    }
}