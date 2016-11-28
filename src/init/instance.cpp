#include <init/instance.hpp>

Instance::Instance (std::vector<Node*> nodes, std::vector<Node*> anchors, double radioRange, double noise, double start, double end) {
    this->nodes = nodes;
    this->anchors = anchors;
    this->radioRange = radioRange;
    this->noise = noise;
    this->start = start;
    this->end = end;
}

Instance::~Instance () {
    int size = nodes.size();
    for(int i = 0; i < size; i++) {
        nodes.pop_back();
    }
    size = anchors.size();
    for(int i = 0; i < size; i++) {
        anchors.pop_back();
    }
}

std::vector<Node*> Instance::getNodes () {
    return nodes;
}

std::vector<Node*> Instance::getAnchors () {
    return anchors;
}

double Instance::getRadioRange () {
    return radioRange;
}

double Instance::getNoise () {
    return noise;
}

void Instance::printNodes () {
    for(int i = 0; i < nodes.size(); ++i) {
        nodes[i]->print();
    }
}

void Instance::printInstance () {
    printf("commons\tanchors\tradio range\tnoise\n");
    printf("%d\t%d\t.5lf\t%.5lf\n", nodes.size(), anchors.size(), radioRange, noise);
}