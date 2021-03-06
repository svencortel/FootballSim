#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>

#include "Positions.h"

using std::string;
using std::set;

class FootballClub;

class Player
{
private:
  const string first_name;
  const string last_name;
  const string alias;
  uint8_t atk_score;
  uint8_t mid_score;
  uint8_t def_score;
  FootballClub* current_club;
  set<PositionEnum> profficient_positions;

public:
  Player(string fname,
         string lname,
         string alias="",
         uint8_t atk=50,
         uint8_t mid=50,
         uint8_t def=50);

  // No need for this because players do not change names?
  //void setName(string fname, string lname="");
  string getFullName() const;
  string getPartialName() const;
  string getFirstName() const;
  string getLastName() const;
  string getAlias() const;

  void increaseAtk(uint8_t value);
  uint8_t getAtk() const;

  void increaseMid(uint8_t value);
  uint8_t getMid() const;

  void increaseDef(uint8_t value);
  uint8_t getDef() const;

  string getSkillString() const;

  FootballClub* getCurrentClub() const;
  void setCurrentClub(FootballClub* newClub);

  PositionEnum getCurrentPosition();
  // this will also calculate the actual scores that the player gives the team
  void setCurrentPosition();

  set<PositionEnum> getProfficientPositions();
  bool addProficientPosition();
};

#endif
