/*
 * InitialDataHomogeneousLinearisedEuler.hpp
 *
 *  Created on: 23 Dec 2023
 *      Author: ntc132
 */

#ifndef SRC_INITIALDATAHOMOGENEOUSLINEARISEDEULER_H_
#define SRC_INITIALDATAHOMOGENEOUSLINEARISEDEULER_H_

#include "Equations.hpp"
#include "EquationsLinearisedEuler.hpp"
#include "Grid.hpp"
#include "InitialData.hpp"

class InitialDataHomogeneousLinearisedEuler : public InitialData
{
 public:
  InitialDataHomogeneousLinearisedEuler(Grid& grid, EquationsLinearisedEuler& equations, double rho, double u, double p)
      : InitialData(grid, equations), rho(rho), u(u), p(p){};
  virtual ~InitialDataHomogeneousLinearisedEuler();
  void setInitialData() override;

  double rho;
  double u;
  double p;
};

#endif /* SRC_INITIALDATAHOMOGENEOUSLINEARISEDEULER_H_ */
