#include <cstdlib>
#include <string>

#include "Player.h"

using std::string;

void do_test(string name1, string name2="",
	     uint8_t atk=0, uint8_t mid=0, uint8_t def=0)
{
  Player* p1;
  p1 = nullptr;

  if(atk==0 && mid==0 && def==0)
  {
    if(name2=="")
      p1 = new Player(name1);
    else
      p1 = new Player(name1, name2);
  }
  else
  {
    p1 = new Player(name1, name2, atk, mid, def);
  }
  printf("\n----**TEST**----\n");
  printf("The name of the current player is %s, also written as %s.\n",
         p1->getFullName().c_str(),
	 p1->getPartialName().c_str());

  printf("%s\n", p1->getSkillString().c_str());

  delete p1;
  p1 = nullptr;
}

int main()
{
  do_test("Ronaldinho", "", 81, 93, 51);
  do_test("Casemiro");
  do_test("Young", "Ross");
  do_test("Gareth", "Bale", 89, 83, 62);

  return 0;
}
