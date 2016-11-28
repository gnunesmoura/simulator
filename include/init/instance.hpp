/**
 * \file instance.hpp
 *
 * File that contains an instance.
 *
 */

#pragma once

#include <iostream>
#include <stdio.h>
#include <init/node.hpp>
#include <vector>

/**
 * Instance class defines how an instance works.
 */
class Instance {
private:
    /**
     * The common nodes of the instance.
     */
    std::vector<Node*> nodes;

    /**
     * The anchor nodes of the instance.
     */
    std::vector<Node*> anchors;

    /**
     * The radio range in this system.
     */
    double radioRange;

    /** 
     * The noise factor in the system.
     */
    double noise;

    /**
     * The start of the instance;
     */
    double start;

    /**
     * The end of the instance;
     */
    double end;

public:
    /**
     * Create a new instace.
     * \param nodes Vector of pointers to common nodes.
     * \param anchors Vector of pointers to anchors nodes.
     * \param radioRange The radio range of the nodes.
     * \param noise The noise factor of the system.
     * \param start The start of the instance.
     * \param end The end of the instance.
     * \param name The name of the instance.
     */
    Instance (std::vector<Node*> nodes, std::vector<Node*> anchors, double radioRange, double noise, double start, double end);

    /**
     * Create a empty instance.
     */
    Instance () {}

    /**
     * Destroy the instance.
     */
    ~Instance ();

    /**
     * Return the common nodes of the instance.
     * \return std::vector<Node*> commun nodes.
     */
    std::vector<Node*> getNodes ();

    /**
     * Return the anchor nodes of the instance.
     * \return std::vector<Node*> Anchor nodes.
     */
    std::vector<Node*> getAnchors ();

    /**
     * Return the radio range of the nodes.
     * \return double Radio range.
     */
    double getRadioRange ();

    /**
     * Return the noise factor in the system.
     * \return double Noise factor.
     */
    double getNoise ();
    
    /**
     * Print on the screen all the common nodes.
     */
    void printNodes();

    /**
     * Print the instance.
     */
    void printInstance ();

};
