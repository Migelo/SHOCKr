/*
 * InitialDataHomogeneous.hpp
 *
 *  Created on: 23 Dec 2023
 *      Author: ntc132
 */

#ifndef SRC_INITIALDATAHOMOGENEOUS_H_
#define SRC_INITIALDATAHOMOGENEOUS_H_

#include "Equations.hpp"
#include "EquationsEuler.hpp"
#include "Grid.hpp"
#include "InitialData.hpp"

class InitialDataHomogeneous : public InitialData
{
 public:
  InitialDataHomogeneous(Grid& grid, EquationsEuler& equations) : InitialData(grid, equations){};
  virtual ~InitialDataHomogeneous();
  void setInitialData() override;

 protected:
  void initialize(int i, double& rho, double& p, double& u);
};

#endif /* SRC_INITIALDATAHOMOGENEOUS_H_ */
