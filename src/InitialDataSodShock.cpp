/*
 * InitialDataSodShock.cpp
 *
 *  Created on: 23 Dec 2023
 *      Author: ntc132
 */

#include "InitialDataSodShock.hpp"
#include "Equations.hpp"
#include "EquationsEuler.hpp"
#include "Grid.hpp"
#include "InitialData.hpp"

void InitialDataSodShock::setInitialData()
{
  double p, rho, u;

  for(int i = 0; i < grid.nx + 2 * grid.nGhost; i++)
    {
      const auto x = grid.getX(i);

      if(x < grid.xMidpoint)
        {
          rho = 1;
          p   = 1;
          u   = 0;
        }
      else
        {
          rho = 0.125;
          p   = 0.1;
          u   = 0;
        }

      grid.quantities[i][EquationsEuler::DENS]   = rho;
      grid.quantities[i][EquationsEuler::XMOM]   = rho * u;
      grid.quantities[i][EquationsEuler::ENERGY] = (static_cast<EquationsEuler*>(&equations))->totalEnergy(p, rho * u * u);
    }
}

InitialDataSodShock::~InitialDataSodShock()
{
  // TODO Auto-generated destructor stub
}
