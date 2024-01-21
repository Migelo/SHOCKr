/*
 * InitialData.hpp
 *
 *  Created on: 23 Dec 2023
 *      Author: ntc132
 */

#include "Equations.hpp"
#include "Grid.hpp"

#ifndef SRC_INITIALDATA_H_
#define SRC_INITIALDATA_H_

class InitialData
{
 public:
  InitialData(Grid& grid, Equations& equations);
  virtual ~InitialData();

  Grid& grid;
  Equations& equations;
  virtual void setInitialData(){};
};

#endif /* SRC_INITIALDATA_H_ */
