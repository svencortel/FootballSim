#include <string>

#include "FootballClub.h"
#include "Player.h"

using std::to_string;

FootballClub::FootballClub(string full_name_,
                           string partial_name_,
                           string jargon_name_,
                           int64_t budget_)
	: full_name(full_name_)
	, partial_name(partial_name_)
	, jargon_name(jargon_name_)
	, budget(budget_)
  , number_of_first_team_deployed(0)
  , number_of_subs_deployed(0)
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

bool FootballClub::addPlayer(Player* new_player)
{
  return players.insert({new_player->getFullName(), {RES, new_player}}).second;
}

void FootballClub::addPlayers(vector<Player*> new_players)
{
  for(std::vector<Player*>::iterator it = new_players.begin(); it != new_players.end(); ++it)
  {
    addPlayer(*it);
  }
}

bool FootballClub::removePlayer(string name)
{
  return players.erase(name) > 0;
}

string FootballClub::getPresentClubString() const
{
  return full_name+", also known as "+partial_name+
	 " or "+jargon_name+".\n"+
	 "They currently hold a budget of "+
	 to_string(budget)+" euros.";
}

static string getPositionString(PositionEnum pos)
{
#define CASE(position) case(position): return #position; break;
  switch(pos)
  {
    CASE(ST)
    CASE(LW)
    CASE(RW)
    CASE(CF)
    CASE(CAM)
    CASE(LM)
    CASE(RM)
    CASE(CM)
    CASE(CDM)
    CASE(LB)
    CASE(RB)
    CASE(CB)
    CASE(GK)
    CASE(SUB)
    CASE(RES)
  }
#undef CASE
}

string FootballClub::getAllPlayersString() const
{
  string out="";
  uint8_t player_nr=0;
  for(const auto &p : players)
  {
    player_nr++;
    out+= to_string(player_nr) + ". " +
    p.second.second->getFullName() + " (" +
    p.second.second->getAlias() + ")\t" +
    getPositionString(p.second.first) + "\n";
  }

  return out;
}
