#ifndef PLAYER_H

#include <string>

using std::string;

class Player
{
private:
  string first_name;
  string last_name;
  uint8_t atk_score;
  uint8_t mid_score;
  uint8_t def_score;

public:
  Player(string fname, string lname="");

  Player(string fname,
         string lname,
         uint8_t atk,
         uint8_t mid,
         uint8_t def);

  void setName(string fname, string lname="");
  string getFullName() const;
  string getPartialName() const;
  string getFirstName() const;
  string getLastName() const;

  void increaseAtk(uint8_t value);
  uint8_t getAtk() const;

  void increaseMid(uint8_t value);
  uint8_t getMid() const;

  void increaseDef(uint8_t value);
  uint8_t getDef() const;

  string getSkillString() const;
};

#define PLAYER_H
#endif
