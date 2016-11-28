/**
 * \file edge.hpp
 *
 * File the defines the edges of the graph.
 */
 
#pragma once

#include <init/enum.hpp>
#include <stdio.h>

/**
 * Forward declaration of the class Node.
 * file of the class node.hpp.
 */
class Node;

/**
 * Class Edge defines the behavior of the edges at the graph.
 */
class Edge {
public:
    Node * b;
    double dist;
    Edge (Node * b, double dist) {this->b = b; this->dist = dist;   }
    Edge () {b = NULL; dist = 0;   }
    ~Edge () {}
    
    /**
     * Prints the command to plot the object on Geogebra.
     */
    void printGeo (int id);

};
