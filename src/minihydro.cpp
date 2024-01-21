/*
 * minihydro.cpp
 *
 *  Created on: 16 Dec 2023
 *      Author: Tiago Costa
 */
#include <cstdio>
#include <iostream>

#include "Boundary.hpp"
#include "BoundaryWind.hpp"
#include "BoundaryWindLinearisedEuler.hpp"
#include "BoundaryWindPassiveScalar.hpp"
#include "BoundaryZeroGradient.hpp"
#include "Equations.hpp"
#include "EquationsEuler.hpp"
#include "EquationsEulerPassiveScalar.hpp"
#include "EquationsLinearisedEuler.hpp"
#include "Grid.hpp"
#include "Grid1D.hpp"
#include "GridRadial.hpp"
#include "InitialData.hpp"
#include "InitialDataHomogeneous.hpp"
#include "InitialDataHomogeneousLinearisedEuler.hpp"
#include "InitialDataHomogeneousPassiveScalar.hpp"
#include "InitialDataIsothermal.hpp"
#include "InitialDataSodShock.hpp"
#include "Output.hpp"
#include "OutputEuler.hpp"
#include "OutputEulerPassiveScalar.hpp"
#include "OutputLinearisedEuler.hpp"
#include "RiemannSolver.hpp"
#include "RiemannSolverHLLC.hpp"
#include "RiemannSolverRusanov.hpp"
#include "ShockFinder.hpp"
#include "ShockFinderEulerPassiveScalar.hpp"

EquationsEulerPassiveScalar *equations = new EquationsEulerPassiveScalar(5. / 3);
Grid *grid                             = new GridRadial(0.01, 10., 1, 1000, *equations);
InitialData *initialdata               = new InitialDataHomogeneousPassiveScalar(*grid, *equations);
Boundary *boundary                     = new BoundaryWindPassiveScalar(*grid, *equations);
Output *output                         = new OutputEulerPassiveScalar(*grid, *equations);
RiemannSolver *riemannsolver           = new RiemannSolverHLLC(*grid, *equations);
ShockFinder *shockfinder               = new ShockFinderEulerPassiveScalar(*grid, *equations);

void freeMemory(void)
{
  delete boundary;
  delete equations;
  delete grid;
  delete initialdata;
  delete output;
  delete riemannsolver;
  delete shockfinder;
}

int main()
{
  double CFL                 = 0.3;
  double maxTime             = 0.5;
  double outputTimeInterval  = 0.01;
  std::string outputFilename = "output_hllc.txt";
  std::string outputEnergy   = "energy.txt";

  double time = 0., dt = 0.;
  double timeSinceLastOutput = 0.0;

  if(std::remove(outputFilename.c_str()) != 0)
    {
    }
  if(std::remove(outputEnergy.c_str()) != 0)
    {
    }

  initialdata->setInitialData();

  while(time <= maxTime)
    {
      boundary->setBoundaries();
      riemannsolver->setFluxes();

      if(riemannsolver->maxSpeed > 0)
        dt = CFL * grid->dx / riemannsolver->maxSpeed;
      else
        throw std::runtime_error("Error: Invalid maxSpeed.");

      grid->update(dt);

      if((time == 0.) || (timeSinceLastOutput > outputTimeInterval))
        {
          output->makeOutput(outputFilename);
          shockfinder->findShockZones();
          timeSinceLastOutput = 0.;
        }

      std::cout << "time = " << time << std::endl;
      timeSinceLastOutput += dt;
      time += dt;
    }

  output->makeOutput(outputFilename);
  shockfinder->findShockZones();

  freeMemory();
  return 0;
}
