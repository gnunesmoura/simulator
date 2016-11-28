/**
 * \file system.hpp
 * 
 * File that defines how the system of nodes will behave.
 *
 */

#pragma once

#include <iostream>
#include <init/movement.hpp>
#include <init/instance.hpp>

/**
 * Class System defines how the system of nodes behave and how
 * the solution will be improved.
 */
class System {
private:

    /**
     * The instance to solve.
     */
    Instance instance;

    std::vector<Node*> nodes;

    std::vector<Movement> moves;
    
    /**
     * Sort the nodes by priority.
     */
    void sortPriority ();

    /**
     * Sort the nodes by ID.
     */
    void sortID ();

    /**
     * Find the place of one node.
     * \param node Pointer to the node;
     */
    void findPlace (Node * node);

    /**
     * Move the node until its movement distance is smaller the var.
     * \param m Movement.
     * \param placed If it will use the placed nodes.
     * \param var The mininum variation to stop the node.
     */
    void moveNode (Movement m, bool placed, double var);

    
     
public:
    /**
     * Creates a new system with all the nodes.
     * \param nodes Nodes of the system.
     */
    System  (Instance instance);

    /**
     * Destroy the system.
     */
    ~System () {}

    /**
     * Solve the system.
     */
     void solve ();
};
