/*
 * BoundaryWindLinearisedEuler.hpp
 *
 *  Created on: 23 Dec 2023
 *      Author: ntc132
 */

#ifndef SRC_BOUNDARYWINDLINEARISEDEULER_H_
#define SRC_BOUNDARYWINDLINEARISEDEULER_H_

#include "Boundary.hpp"
#include "Equations.hpp"
#include "EquationsLinearisedEuler.hpp"
#include "Grid.hpp"
#include "InitialDataHomogeneousLinearisedEuler.hpp"

class BoundaryWindLinearisedEuler : public Boundary
{
 public:
  BoundaryWindLinearisedEuler(Grid& grid, EquationsLinearisedEuler& equations,
                              const InitialDataHomogeneousLinearisedEuler& initialdata)
      : Boundary(grid, equations), initialdata(initialdata){};
  virtual ~BoundaryWindLinearisedEuler();

  void setBoundaries() override;
  InitialDataHomogeneousLinearisedEuler initialdata;
};

#endif /* SRC_BOUNDARYWINDLINEARISEDEULER_H_ */
