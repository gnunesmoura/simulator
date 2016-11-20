/**
 * \file node.hpp
 *
 *
 *   
 */

#pragma once

#include <iostream>
#include <vector>
#include <init/enum.hpp>
#include <init/edge.hpp>

/**
 * Class defines the behavior of the nodes.
 */
class Node {
private:
    double x, y;
    std::vector<Edge> anchor;
    std::vector<Edge> neighbor;
    Type type;

public:
    /**
     * Creates a new node.
     *
     * \param x Position in the x axis.
     * \param y Position in the y axis.
     * \param t Type of the node.
     */
    Node (double x, double y, Type t) {this->x = x; this->y = y; this->type = t; }

    ~Node () {};
    double get (Axis a);
    Type getType ();
    void newPos (double x, double y);
    void setType(Type t);
    void addEdge (Node * b, double dist);
    size_t getNAnchors();
    size_t getNNeighbors();

    /**
     * Return the vector of anchors of the node.
     * /return vector<Edge>* pointer to the vector. 
     */ 
    std::vector<Edge> * getAnchors ();

    /**
     * Return the vector of neighbors of the node.
     * /return vector<Edge>* pointer to the vector. 
     */
    std::vector<Edge> * getNeighbors ();

    /**
     * Prints the node.
     */
    void print ();
};
