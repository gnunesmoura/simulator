/**
 * \file node.hpp
 *
 *
 *   
 */

#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <init/test.hpp>
#include <init/enum.hpp>
#include <init/edge.hpp>
#include <init/vector.hpp>
class Edge;

/**
 * Class defines the behavior of the nodes.
 */
class Node {
private:
    int id;
    double x, y;
    std::vector<Edge> anchor;
    std::vector<Edge> neighbor;
    std::vector<Edge> placed;
    Type type;
    void printAnchors ();
    void printNeighbors ();
    void printPlaceds ();
public:
    /**
     * Creates a new node.
     * \param id Id of the node.
     * \param x Position in the x axis.
     * \param y Position in the y axis.
     * \param t Type of the node.
     */
    Node (int id, double x, double y, Type t) {
        this->id = id; 
        this->x = x; 
        this->y = y; 
        this->type = t; 
    }

    ~Node () {}
    double get (Axis a);
    int getId();
    Type getType ();
    void newPos (double x, double y);
    void setType(Type t);
    void addEdge (Node * b, double dist);
    size_t getNAnchors();;
    size_t getNNeighbors();
    size_t getNPlaceds();

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
     * Return the vector of neighbors of the node.
     * /return vector<Edge>* pointer to the vector. 
     */
    std::vector<Edge> * getPlaceds ();

    /**
     * Put the node as a new placed node.
     */
    void notifyPlacement (Node * node);

    /**
     * Prints the node.
     */
    void print ();

    /**
     * Prints the command to plot the object on Geogebra.
     */
    void printGeo ();

    /**
     * Prints the edges to plot on geogebra.
     */
    void printEdgesGeo ();

    /**
     * Prints the node Edges.
     */
    void printEdges (Type a);

    /**
     * Return if the node is bigger then the other.
     * \param Pointer to the node that will be compared.
     */
    bool biggerThen (Node * node);

    /**
     * If any placed neighbor or known anchor is near the node n and
     * not your neighbor.
     * \param n Node that will be verified.
     * \param range How close the other nodes must be to be consedered neighbors. 
     * \return bool True if there is some neighbor, false otherwise.
     */
    bool inRange (Node * n, double range);

    /**
     * If the node has n as neighbor or anchor.
     * \param n Node.
     * \return bool True if n is neighbor or anchor of the node, false otherwise.
     */
    bool isNeighbor (Node * n);
};
