/*
 * minihydro.cpp
 *
 *  Created on: 16 Dec 2023
 *      Author: Tiago Costa
 */
#include <Kokkos_Core.hpp>
#include "SimulationDependencies.h"
#include <cstdio>
#include <typeinfo>

SimulationConfig config("config.txt");

EquationsEulerPassiveScalar *equations = new EquationsEulerPassiveScalar(5./3);//EquationsEulerCooling(5./3, config.unitLengthInCgs, config.unitMassInCgs, config.unitVelocityInCgs);
Grid *grid                             = new GridRadial(config.gridMin, config.gridMax, config.gridNGhost, config.gridNcell, *equations);
InitialData *initialdata               = new InitialDataPowerLawPassiveScalar(config.bgDensity, config.bgVel, config.bgPressure, config.powerLawExponent, *grid, *equations);
Boundary *boundary                     = new BoundaryWindPassiveScalar(config.windDensity, config.windVel, config.windPressure, *grid, *equations);
Output *output                         = new OutputEulerPassiveScalar(*grid, *equations);
RiemannSolver *riemannsolver           = new RiemannSolverHLLC(*grid, *equations);
ShockFinder *shockfinder               = new ShockFinderEuler(*grid, *equations);

void doGreeting();
void freeMemory();


struct hello_world {
  KOKKOS_INLINE_FUNCTION
  void operator()(const int i) const {
    Kokkos::printf("Hello from i = %i\n", i);
  }
};


int main(int argc, char* argv[]) {
	
	Kokkos::initialize(argc, argv);
  	printf("Hello World on Kokkos execution space %s\n",
	typeid(Kokkos::DefaultExecutionSpace).name());

	Kokkos::parallel_for("HelloWorld", 15, hello_world());

	// You must call finalize() after you are done using Kokkos.
	std::string outputFilename = "output_hllc.txt";
	std::string outputEnergy = "energy.txt";

	constexpr double CFL = 0.3;
	double maxTime = config.maxTime;
	double outputTimeInterval = config.outputTimeInterval;

	if (std::remove(outputFilename.c_str()) != 0) {}
	if (std::remove(outputEnergy.c_str()) != 0) {}
	double time = 0., dt = 0., timeSinceLastOutput = 0.0;

	doGreeting();

	equations->preProcessor();
	initialdata->setInitialData();

	while(time <= maxTime){

		boundary->setBoundaries();
		riemannsolver->setFluxes();

		if(riemannsolver->maxSpeed > 0)
			dt = CFL * grid->dx / riemannsolver->maxSpeed;
		else
			throw std::runtime_error("Error: Invalid maxSpeed.");

		grid->update(dt);

		if((time == 0.) || (timeSinceLastOutput > config.outputTimeInterval)){
			output->makeOutput(outputFilename, time);
			shockfinder->findShockZones();
			timeSinceLastOutput = 0.;
		}

		std::cout << time << std::endl;
		timeSinceLastOutput += dt;
		time += dt;
	}

	output->makeOutput(outputFilename, time);
	shockfinder->findShockZones();

	freeMemory();

	std::cout << "All done." << std::endl;
	Kokkos::finalize();
	return 0;
}

void doGreeting(void){
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << " "                                         << std::endl;
    std::cout << "  SSS   H   H   OOO   CCCC  K   K   RRRR " << std::endl;
    std::cout << " S      H   H  O   O  C     K  K    R  R"  << std::endl;
    std::cout << "  SSS   HHHHH  O   O  C     KKK     RRR  " << std::endl;
    std::cout << "     S  H   H  O   O  C     K  K    RR R " << std::endl;
    std::cout << "  SSS   H   H   OOO   CCCC  K   K   R   R" << std::endl;
	std::cout << " "                                         << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "                Version 0                " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
}

void freeMemory(void){
	delete boundary;
	delete equations;
	delete grid;
	delete initialdata;
	delete output;
	delete riemannsolver;
	delete shockfinder;
}
