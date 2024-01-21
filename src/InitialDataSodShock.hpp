/*
 * InitialDataSodShock.hpp
 *
 *  Created on: 23 Dec 2023
 *      Author: ntc132
 */

#ifndef SRC_INITIALDATASODSHOCK_H_
#define SRC_INITIALDATASODSHOCK_H_

#include "Equations.hpp"
#include "EquationsEuler.hpp"
#include "Grid.hpp"
#include "InitialData.hpp"

class InitialDataSodShock : public InitialData
{
 public:
  InitialDataSodShock(Grid& grid, EquationsEuler& equations) : InitialData(grid, equations){};
  virtual ~InitialDataSodShock();
  void setInitialData() override;
};

#endif /* SRC_INITIALDATASODSHOCK_H_ */
