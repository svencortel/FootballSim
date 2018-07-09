#ifndef RESULT_H
#define RESULT_H

#include "FootballClub.h"

struct Result
{
  FootballClub* home_club;
  FootballClub* away_club;
  uint8_t home_score;
  uint8_t away_score;
};

#endif