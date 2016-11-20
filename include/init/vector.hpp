/**
 * \file vector.hpp
 * 
 * File that contains the class Vector.
 *
 */

#pragma once

#include <init/node.hpp>
#include <math.h>
#include <iostream>

/**
 * Class Vector defines de the vector equal that the norm 
 * of the vector is equal to the distance between two Nodes pointing to one of them.
 */
class Vector {
public:
    /**
     * Create a new vector between two nodes with a specific norm.
     *
     * \param a Node a, where the vector starts.
     * \param b Node b, the direction of the vector from the a.
     * \param norm The norm of the Vector
     */
    Vector (Node * a, Node * b, double norm);

    /**
     * Create a new vector between two nodes with a specific norm.
     *
     * \param a Node a, where the vector starts.
     * \param b Node b, the direction of the vector from the a.
     */
    Vector (Node * a, Node * b);

    /**
     * Create a new vector.
     *
     * \param a x axis of the vector.
     * \param b y of the axis.
     */
    Vector (double x, double y);

    /**
     * Create a null vector.
     */
    Vector () {this->x = 0; this->y = 0; }

    /**
     * Destroy the vector.
     */
    ~Vector () {};

    /**
     * Return where in te axis wanted te node is.
     * \param a Axis::x or Axis::y.
     * \return double Where in the axis selected.
     */
    double get (Axis a);

    /**
     * Return the Euclidean norm of the vector.
     * \return double Euclidean norm of the vector.
     */
    double getNorm ();

    /**
     * Sum two vectors.
     */
    Vector operator+ (Vector b);

    /**
     * Multiply a vector by a scalar.
     */
    Vector operator* (double scalar);

    /**
     * Print the vector.
     */
    void print ();
private:
    /**
     * Direction x of the vector.
     */ 
    double x;

    /**
     * Direction y of the vector.
     */
    double y;
    
    /**
     * Calculate the Euclidean Norm of the vector.
     *
     * \param x First dimension of the vector.
     * \param y Second dimension of the vector.
     * \return double Euclidean Norm of the vector. 
     */
    double calcNorm (double x, double y);
};
