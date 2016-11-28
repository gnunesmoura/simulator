/**
 * \file movement.hpp
 * 
 * File that contains how movementment of the nodes work.
 *
 */

#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <init/test.hpp>
#include <init/node.hpp>
#include <init/vector.hpp>

/**
 * The movement class defines how the node move with
 * a certain vector.
 */
class Movement{
private:

    /**
     * Node that move.
     */
    Node * node;
    
    /**
     * Multiplier of the distance that the node
     * will move.
     */
    double range;

    /**
     * Noise in force measurement.
     */
    double noise;

    /**
     * The maximum acceptable .
     */
    double acceptableError;

    /**
     * The larger force acting on the node.
     */
    Vector biggerStress;

    /**
     * Return the larger vector acting on the node.
     * \return Vector Larger vector acting on the node.
     */ 
    Vector largerVector (); 

    /**
     * Return the edge with the largest vector on the node.
     * \return Edge The strongest edge;
     */
    Edge strongestEdge ();

public:

    /**
     * Create a object movement.
     * The object Move didn't control the lifetime
     * of the node.
     * \param node Node that will be moved.
     */
    Movement (Node * node, double noise, double range);

    Movement() { node = NULL;    }
    
    /**
     * Destroy the object Move.
     */
    ~Movement () {}

    /**
     * Moves the node half of the vector applied on it.
     * \param placed If the placed neighbors are acting on this movement.
     * \return double Distance that the node was moved.
     */
    double move (bool placed);

    /**
     * Calculate the movement resultant of the force between the node and
     * an edge.
     * \param e The edge to calculate the vector.
     * \return Vector Vector resultant of the node and edge.
     */
    inline Vector movement (Edge e);

    /**
     * Verify if the node is under stress.
     * \return bool If the node is under stress.
     */
    bool stress ();

    /**
     * Movement the node using a Vector.
     * \param move The vector that represents the movement.
     */
    inline void newPos (Vector move);

    /**
     * Movement the node using the larger stress of the node.
     */
    void releaseStress ();

    int nVectors ();
};
