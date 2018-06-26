#ifndef FOOTBALLCLUB_H
#define FOOTBALLCLUB_H

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Player;

class FootballClub
{
private:
  string full_name, partial_name, jargon_name;
  // make budget signed to allow negative values?
  int64_t budget;
  // a map of players with their full names as keys
  unordered_map<string, Player*> players;
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
  bool removePlayer(string fullname);
  Player* getPlayer(string name) const;

  string getPresentClubString() const;
  string getAllPlayersString() const;

  // TODO: this could go with a "player value" mechanism
  //void transferMoneyTo(Player* p, uint32_t value);
};

#endif
