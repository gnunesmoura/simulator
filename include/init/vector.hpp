/**
 * \file vector.hpp
 * 
 * File that contains the class Vector.
 *
 */

#pragma once

/**
 * Class Vector defines de the vector equal that the norm 
 * of the vector is equal to the distance between two Nodes pointing to one of them.
 */
class Vector {
public:
    /**
     * Create a new vector between two nodes.
     *
     * \param a Node a, where the vector starts.
     * \param b Node b, the direction of the vector from the a.
     * \param norm The norm of the Vector
     */
    Vector (Node a, Node b, double norm);

    /**
     * Destroy the vector.
     */
     
    ~Vector ();
private:
    double x;
    double y;
    double norm;
}
