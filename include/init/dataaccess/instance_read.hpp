/**
 * \file instanceRead.hpp
 *
 * File that defines the read of an instance.
 *
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <init/instance.hpp>
#include <init/node.hpp>
/**
 * Read an instance.
 * \param Name of the file.
 * \return vector<Node*> * Pointer to the vector with all nodes.
 */
Instance readInstance (const char * arqName);

/**
 * Read a result.
 * \param Name of the file.
 * \return vector<Node> Vector with all nodes.
 */
std::vector<Node> readResult (const char * arqName);


/**
 * Print the result to a new file.
 * \param nodes The nodes placeds by the system.
 * \param arqName Name of the file.
 */
void printResult (std::vector<Node*> nodes, const char * arqName);