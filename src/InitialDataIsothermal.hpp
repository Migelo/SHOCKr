/*
 * InitialDataIsothermal.hpp
 *
 *  Created on: 7 Jan 2024
 *      Author: ntc132
 */

#ifndef SRC_INITIALDATAISOTHERMAL_H_
#define SRC_INITIALDATAISOTHERMAL_H_

#include "Equations.hpp"
#include "EquationsEuler.hpp"
#include "Grid.hpp"
#include "InitialData.hpp"

class InitialDataIsothermal : public InitialData
{
 public:
  InitialDataIsothermal(Grid& grid, EquationsEuler& equations) : InitialData(grid, equations){};
  virtual ~InitialDataIsothermal();
  void setInitialData() override;
};

#endif /* SRC_INITIALDATAISOTHERMAL_H_ */
