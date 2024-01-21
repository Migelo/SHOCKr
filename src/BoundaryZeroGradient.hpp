/*
 * BoundaryZeroGradient.hpp
 *
 *  Created on: 22 Dec 2023
 *      Author: ntc132
 */

#ifndef BOUNDARYZEROGRADIENT_H_
#define BOUNDARYZEROGRADIENT_H_

#include "Boundary.hpp"
#include "Grid.hpp"

class BoundaryZeroGradient : public Boundary
{
 public:
  BoundaryZeroGradient(Grid& grid, Equations& equations) : Boundary(grid, equations){};
  virtual ~BoundaryZeroGradient();
  void setBoundaries() override;
};

#endif /* BOUNDARYZEROGRADIENT_H_ */
