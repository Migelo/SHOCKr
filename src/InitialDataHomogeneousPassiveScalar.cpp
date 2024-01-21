/*
 * InitialDataHomogeneousPassiveScalar.cpp
 *
 *  Created on: 15 Jan 2024
 *      Author: ntc132
 */

#include "InitialDataHomogeneousPassiveScalar.hpp"
#include "Equations.hpp"
#include "EquationsEulerPassiveScalar.hpp"
#include "InitialData.hpp"

void InitialDataHomogeneousPassiveScalar::setInitialData()
{
  InitialDataHomogeneous::setInitialData();

  for(int i = 0; i < grid.nx + 2 * grid.nGhost; i++)
    grid.quantities[i][EquationsEulerPassiveScalar::PASS] = 0.;
}

InitialDataHomogeneousPassiveScalar::~InitialDataHomogeneousPassiveScalar()
{
  // TODO Auto-generated destructor stub
}
