#ifndef POSITIONS_H
#define POSITIONS_H

#include <string>

using std::string;

enum PositionEnum
{
  ST = 0,
  LW,
  RW,
  CF,
  CAM,
  LM,
  RM,
  CM,
  CDM,
  LB,
  RB,
  CB,
  GK,  // = 12
  SUB, // = 13
  RES
};

#endif