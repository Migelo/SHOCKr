/*
 * Grid.cpp
 *
 *  Created on: 19 Dec 2023
 *      Author: ntc132
 */

#include "Grid.h"
#include "Equations.h"
#include <Kokkos_Core.hpp>

Grid::Grid(double xmin, double xmax, int nGhost, int nx, Equations& equations) : xmin(xmin), xmax(xmax), nGhost(nGhost), nx(nx), equations(equations) {

    quantities = Kokkos::View<double**>("quantities", nx + 2*nGhost, equations.nCons());
    fluxes     = Kokkos::View<double**>("fluxes", nx + 2*nGhost + 1, equations.nCons());

    dx = (xmax - xmin)/nx;
    xMidpoint = (xmax + xmin)/2;
    minXIndex = nGhost;
    maxXIndex = nGhost + nx - 1;

}
Grid::~Grid() {
	// TODO Auto-generated destructor stub
}

