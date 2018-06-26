#include "FootballClub.h"

void do_test(string fname, string pname, string jname,
	     int64_t budget=0)
{
  FootballClub* f1;
  if (budget==0)
    f1 = new FootballClub(fname, pname, jname);
  else
    f1 = new FootballClub(fname, pname, jname, budget);

  printf("\n----**TEST**----\n");

  printf("The name of the current football club is %s, also known as %s or %s.\nThey currently hold a budget of %lu euros.\n",
	 f1->getFullName().c_str(),
	 f1->getPartialName().c_str(),
	 f1->getJargonName().c_str(),
	 f1->getBudget());
}

int main()
{
  do_test("Real Madrid Club de Futbol",
	  "Real Madrid",
	  "Los Blancos",
	  300000000);

  do_test("Fotbal Club Olimpia",
	  "FC Olimpia",
	  "the Yellow and Blues");

  do_test("Fotbal Club Dinamo Bucuresti",
	  "FC Dinamo",
	  "the Red Dogs",
	  15000000);

  return 0;
}
