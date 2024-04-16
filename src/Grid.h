/*
 * Grid.h
 *
 *  Created on: 19 Dec 2023
 *      Author: ntc132
 */
#include <vector>
#include "Equations.h"

#include <Kokkos_Core.hpp>

#ifndef SRC_GRID_H_
#define SRC_GRID_H_

class Grid {
public:
	Grid(double xmin, double xmax, int nGhost, int nx, Equations& equations);
	virtual ~Grid();

	double dx, xMidpoint;
	double xmin, xmax;
	int minXIndex, maxXIndex;
	int nGhost;
	int nx;

	Kokkos::View<double**> quantities;
	Kokkos::View<double**> fluxes;

	double getX(int cellIndex){
		return xmin + (cellIndex - minXIndex) * dx + dx/2.;
	}

	virtual void update(double dt){};

	Equations& equations;
};

#endif /* SRC_GRID_H_ */
