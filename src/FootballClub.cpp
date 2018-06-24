#include <string>

#include "FootballClub.h"

using std::to_string;

FootballClub::FootballClub(string full_name_,
		           string partial_name_,
			   string jargon_name_,
			   int64_t budget_)
	: full_name(full_name_)
	, partial_name(partial_name_)
	, jargon_name(jargon_name_)
	, budget(budget_)
{}

string FootballClub::getFullName() const
{
  return full_name;
}

string FootballClub::getPartialName() const
{
  return partial_name;
}

string FootballClub::getJargonName() const
{
  return jargon_name;
}

uint64_t FootballClub::getBudget() const
{
  return budget;
}

void FootballClub::addToBudget(uint32_t value)
{
  budget+=value;
}

void FootballClub::extractFromBudget(uint32_t value)
{
  budget-=value;
}

void FootballClub::transferMoneyTo(FootballClub* fc, uint32_t value)
{
  fc->addToBudget(value);
  extractFromBudget(value);
}

string FootballClub::getPresentClubString() const
{
  return full_name+", also known as "+partial_name+
	 " or "+jargon_name+".\n"+
	 "They currently hold a budget of "+
	 to_string(budget)+" euros.";
}

