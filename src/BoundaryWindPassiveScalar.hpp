/*
 * BoundaryWindPassiveScalar.hpp
 *
 *  Created on: 15 Jan 2024
 *      Author: ntc132
 */

#ifndef SRC_BOUNDARYWINDPASSIVESCALAR_H_
#define SRC_BOUNDARYWINDPASSIVESCALAR_H_

#include "BoundaryWind.hpp"
#include "Equations.hpp"
#include "EquationsEulerPassiveScalar.hpp"
#include "Grid.hpp"

class BoundaryWindPassiveScalar : public BoundaryWind
{
 public:
  BoundaryWindPassiveScalar(Grid& grid, EquationsEulerPassiveScalar& equations) : BoundaryWind(grid, equations){};
  void setBoundaries() override;
  virtual ~BoundaryWindPassiveScalar();
};

#endif /* SRC_BOUNDARYWINDPASSIVESCALAR_H_ */
