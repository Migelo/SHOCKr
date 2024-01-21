/*
 * InitialDataIsothermal.cpp
 *
 *  Created on: 7 Jan 2024
 *      Author: ntc132
 */

#include "InitialDataIsothermal.hpp"
#include "Equations.hpp"
#include "EquationsEuler.hpp"
#include "InitialData.hpp"

#include <cmath>

void InitialDataIsothermal::setInitialData()
{
  for(int i = 0; i < grid.nx + 2 * grid.nGhost; i++)
    {
      const auto rho  = 0.1;
      const auto p    = 0.01;
      const auto u    = 0.;
      const auto rRef = 1.;

      grid.quantities[i][EquationsEuler::DENS] = rho * std::pow(rRef / grid.getX(i), 2.);
      grid.quantities[i][EquationsEuler::XMOM] = rho * u * std::pow(rRef / grid.getX(i), 2.);
      grid.quantities[i][EquationsEuler::ENERGY] =
          (static_cast<EquationsEuler*>(&equations))->totalEnergy(p, rho * u * u * std::pow(rRef / grid.getX(i), 2.));
    }
}

InitialDataIsothermal::~InitialDataIsothermal()
{
  // TODO Auto-generated destructor stub
}
