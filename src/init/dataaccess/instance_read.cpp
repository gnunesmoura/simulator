#include <init/dataaccess/instance_read.hpp>

Instance readInstance (const char * arqName) {
    std::ifstream arq;
    arq.open(arqName);
    int nAncoras, nNodos, i;
    double start, end, alcance, ruido, tam;
    double x, y;
    arq >> start;
    arq >> end;
    arq >> nNodos;
    arq >> nAncoras;
    arq >> alcance;
    arq >> ruido;
    
    tam = nNodos + nAncoras;

    std::vector<Node*> nodes;

    //Colocando os ancoras no vetor.
    for (i = 0; i < nAncoras; ++i) {
        arq >> x >> y;
        Node * anchor = new Node(i ,x, y, Type::anchor);
        nodes.push_back(anchor);
    }

    for (; i < tam; ++i) {
        Node * node = new Node(i, -1, -1, Type::not_placed);
        nodes.push_back(node);
    }


    int indice, real;
    double dist;
    for(i = 0; i < nAncoras; ++i){
        arq >> indice;
        while(arq >> indice && indice != -1) {
            arq >> dist;
            real = indice+nAncoras;
            nodes[i]->addEdge(nodes[real], dist);
            nodes[real]->addEdge(nodes[i], dist);
        }
        arq >> indice;
    }

    for(i = nAncoras; i < tam; ++i){
        arq >> indice;
        while(arq >> indice && indice != -1) {
            arq >> dist;
            real = indice+nAncoras;
            nodes[i]->addEdge(nodes[real], dist);
            nodes[real]->addEdge(nodes[i], dist);
        }
        arq >> indice;
    }

    std::vector<Node*> commons;
    std::vector<Node*> anchors;

    for(i = 0; i < nAncoras; ++i) {
        anchors.push_back(nodes[i]);
    }

    for(; i < tam; ++i) {
        commons.push_back(nodes[i]);
    }

    Instance instance(commons, anchors, alcance, ruido, start, end);
    return instance;
}

std::vector<Node> readResult (const char * arqName) {
    std::ifstream arq;
    arq.open(arqName);
    std::vector<Node> result;
    double x, y;
    int id = 0;
    while (!arq.eof()) {
        arq >> x;
        arq >> y;
        Node n(id, x, y, Type::placed);
        result.push_back(n);
        id++;
    }
    return result;
}

void printResult (std::vector<Node*> nodes, const char * arqName) {
    std::ofstream arq;
    arq.open (arqName);
    int size = nodes.size();
    for(int i = 0; i < size; i++) {
        if(nodes[i]->getType() != Type::anchor) {
            arq << nodes[i]->get(Axis::x) << " " << nodes[i]->get(Axis::y) << "\n";
        }
    }
    arq.close();
}
