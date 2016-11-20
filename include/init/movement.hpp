/**
 * \file movement.hpp
 * 
 * File that contains how movementment of the nodes work.
 *
 */

#pragma once

#include <iostream>
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
    double scalar;

public:

    /**
     * Create a object movement.
     * The object Move didn't control the lifetime
     * of the node.
     * \param node Node that will be moved.
     */
    Movement (Node * node) {    this->node = node; }
    
    /**
     * Destroy the object Move.
     */
    ~Movement () {}

    /**
     * Calculate the movement and moves the node.
     * \return double Distance moved.
     */
    double move (bool neighbor);
};
