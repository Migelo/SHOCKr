/*
 * Boundary.cpp
 *
 *  Created on: 22 Dec 2023
 *      Author: ntc132
 */

#include "Boundary.hpp"
#include "Equations.hpp"
#include "Grid.hpp"

Boundary::Boundary(Grid& grid, Equations& equations) : grid(grid), equations(equations) {}

Boundary::~Boundary()
{
  // TODO Auto-generated destructor stub
}
