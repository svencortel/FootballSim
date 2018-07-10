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
  , goalkeeper_deployed(false)
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

enum PadEnum {
  FRONT = 0,
  BACK
};

// TODO: maybe modify this function to pad with a chosen character
// TODO(2): move this method from here to a "Utils.h" file
static string getPaddedString(uint16_t pad, string input_string, PadEnum padenum)
{
  size_t string_length = input_string.length();

  // just pad with a blank space if pad is shorter than the string to pad
  if (pad <= string_length)
  {
    return padenum == FRONT ? " " + input_string : input_string + " ";
  }

  string pad_string (pad-string_length, ' ');

  return padenum == FRONT ? pad_string + input_string : input_string + pad_string;
}

string FootballClub::getAllPlayersString() const
{
  string out="";
  uint8_t player_nr=0;
  for(const auto &p : players)
  {
    player_nr++;
    out+= getPaddedString(35, to_string(player_nr) +
    ". " + p.second.second->getFullName() + " (" +
    p.second.second->getAlias() + ")", BACK) +
    getPositionString(p.second.first) + "\n";
  }

  return out;
}

#include <stdlib.h>
#include <time.h>

static PositionEnum getRandomPosEnum(bool include_subres=true)
{
  int limit = 15;
  if(!include_subres)
  {
    limit = 13;
  }

  int rnumber = rand() % limit;

  return static_cast<PositionEnum>(rnumber);
}

void FootballClub::chooseFirstTeam()
{
  if(players.empty())
  {
    return;
  }

  map<string, pair<PositionEnum, Player*>>::iterator it = players.begin();

  srand(time(NULL));

  for(; it != players.end(); ++it)
  {
    // very random for now
    it->second.first = getRandomPosEnum();

    if(it->second.first != SUB &&
       it->second.first != RES)
    {
      // if we have one too many first 11 players then sub them
      number_of_first_team_deployed ++;
      if(number_of_first_team_deployed == 12)
      {
        number_of_first_team_deployed --;
        it->second.first = SUB;
      }
    }

    // if we have too many subs then res them
    if (it->second.first == SUB)
    {
      if(number_of_subs_deployed == 8)
      {
        // try to put them in first 11 if there is no place on bench
        if(number_of_first_team_deployed < 11)
        {
          it->second.first = getRandomPosEnum(false);
          number_of_first_team_deployed ++;
        }
        else
        {
          it->second.first = RES;
        }
      }
      else
      {
        number_of_subs_deployed ++;
      }
    }
  }
}
