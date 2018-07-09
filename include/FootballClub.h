#ifndef FOOTBALLCLUB_H
#define FOOTBALLCLUB_H

#include <string>
#include <map>
#include <vector>
#include <utility>

#include "Positions.h"

using std::string;
using std::map;
using std::vector;
using std::pair;

class Player;

class FootballClub
{
private:
  string full_name, partial_name, jargon_name;
  // make budget signed to allow negative values?
  int64_t budget;
  // a map of players with their full names as keys
  // also stores information about players' position in the
  // team
  map<string, pair<PositionEnum, Player*>> players;
  // counter to use to limit the number of first team and sub players
  uint8_t number_of_first_team_deployed;
  uint8_t number_of_subs_deployed;

public:
  FootballClub(string full_name_,
	       string partial_name_,
	       string jargon_name_,
	       int64_t budget_=0);

  string getFullName() const;
  string getPartialName() const;
  string getJargonName() const;

  uint64_t getBudget() const;
  void addToBudget(uint32_t value);
  void extractFromBudget(uint32_t value);

  void transferMoneyTo(FootballClub* fc, uint32_t value);

  bool addPlayer(Player* new_player);
  void addPlayers(vector<Player*> new_players);
  bool removePlayer(string fullname);
  Player* getPlayer(string name) const;

  string getPresentClubString() const;
  string getAllPlayersString() const;

  void chooseFirstTeam();
  vector<pair<PositionEnum, Player*>> getMatchTeam() const;

  // TODO: this could go with a "player value" mechanism
  //void transferMoneyTo(Player* p, uint32_t value);
};

#endif
