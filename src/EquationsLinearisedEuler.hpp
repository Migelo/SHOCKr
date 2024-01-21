/*
 * EquationsLinearisedEuler.hpp
 *
 *  Created on: 23 Dec 2023
 *      Author: ntc132
 */

#ifndef SRC_EQUATIONSLINEARISEDEULER_H_
#define SRC_EQUATIONSLINEARISEDEULER_H_

#include "Equations.hpp"
#include "EquationsLinearisedEuler.hpp"
#include "Grid.hpp"

class EquationsLinearisedEuler : public Equations
{
 public:
  EquationsLinearisedEuler(double BgDensity, double BgVel, double BgSoundSpeed)
      : BgDensity(BgDensity), BgVel(BgVel), BgSoundSpeed(BgSoundSpeed){};
  virtual ~EquationsLinearisedEuler();

  double BgDensity;
  double BgVel;
  double BgSoundSpeed;

  static const int DENS  = 0;
  static const int VEL   = 1;
  static const int PRESS = 2;

  double* getFlux(std::vector<double>& quantities) override;
  double getMaxAbsEigenvalue(std::vector<double>& quantities) override;
};

#endif /* SRC_EQUATIONSLINEARISEDEULER_H_ */
