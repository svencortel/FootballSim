#ifndef FOOTBALLCLUB_H

#include <string>

using std::string;

class FootballClub
{
private:
  string full_name, partial_name, jargon_name;
  // make it signed to allow negative values?
  int64_t budget;
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
  // TODO: this could go with a "player value" mechanism
  //void transferMoneyTo(Player* p, uint32_t value);
}

#define FOOTBALLCLUB_H
#endif
