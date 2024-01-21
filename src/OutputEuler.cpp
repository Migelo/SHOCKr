/*
 * OutputEuler.cpp
 *
 *  Created on: 23 Dec 2023
 *      Author: ntc132
 */

#include "OutputEuler.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "EquationsEuler.hpp"

void OutputEuler::makeOutput(const std::string& filename)
{
  std::ofstream outputFile(filename, std::ios_base::app);

  if(!outputFile.is_open())
    {
      std::cerr << "Error opening file: " << filename << std::endl;
      return;
    }

  for(int i = 0; i <= grid.maxXIndex; i++)
    {
      const auto rhoV2 = grid.quantities[i][EquationsEuler::XMOM] * grid.quantities[i][EquationsEuler::XMOM] /
                         grid.quantities[i][EquationsEuler::DENS];
      const auto p     = (static_cast<EquationsEuler*>(&equations))->getPressure(grid.quantities[i][EquationsEuler::ENERGY], rhoV2);
      const auto gamma = (static_cast<EquationsEuler*>(&equations))->gamma;
      outputFile << grid.getX(i) << " " << grid.quantities[i][EquationsEuler::DENS] << " "
                 << 0.5 * rhoV2 / (p / (gamma - 1) + 0.5 * rhoV2) << " "
                 << grid.quantities[i][EquationsEuler::XMOM] / grid.quantities[i][EquationsEuler::DENS] << " " << p << std::endl;
    }

  outputFile << " " << std::endl;
  outputFile.close();
}

OutputEuler::~OutputEuler()
{
  // TODO Auto-generated destructor stub
}
