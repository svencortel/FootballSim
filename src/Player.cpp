#include <string>

#include "Player.h"

using std::string;
using std::to_string;

Player::Player(string fname_, string lname_)
	: first_name(fname_)
	, last_name(lname_)
	, atk_score(50)
	, mid_score(50)
	, def_score(50)
{}

Player::Player(string fname_, string lname_,
	       uint8_t atk, uint8_t mid, uint8_t def)
	: first_name(fname_)
	, last_name(lname_)
	, atk_score(atk)
	, mid_score(mid)
	, def_score(def)
{}

void Player::setName(string fname_,
		     string lname_)
{
  first_name = fname_;
  last_name  = lname_;
}

string Player::getFullName() const
{
  if(last_name.compare("") == 0)
  {
    return first_name;
  }
  return first_name + " " + last_name;
}

string Player::getPartialName() const
{
  if(last_name.compare("") == 0)
  {
    return first_name;
  }
  return first_name.substr(0,1) + ". " + last_name;
}

string Player::getFirstName() const
{
  return first_name;
}

string Player::getLastName() const
{
  return last_name;
}

void Player::increaseAtk(uint8_t value)
{
  atk_score+=value;
  if(atk_score > 100)
  {
    atk_score=100;
  }
}

uint8_t Player::getAtk() const
{
  return atk_score;
}

void Player::increaseMid(uint8_t value)
{
  mid_score+=value;
  if(mid_score > 100)
  {
    mid_score=100;
  }
}

uint8_t Player::getMid() const
{
  return mid_score;
}

void Player::increaseDef(uint8_t value)
{
  def_score+=value;
  if(def_score > 100)
  {
    def_score=100;
  }
}

uint8_t Player::getDef() const
{
  return def_score;
}

string Player::getSkillString() const
{
  return getFullName() + " player skill:\n" +
	 "Atk:\t" + to_string(atk_score) + "\n" +
	 "Mid:\t" + to_string(mid_score) + "\n" +
	 "Def:\t" + to_string(def_score);
}

