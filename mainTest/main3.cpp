#include <string>

#include "Player.h"
#include "FootballClub.h"

void do_test(Player* p,
	           FootballClub* new_fc,
	           FootballClub* old_fc=nullptr,
	           int64_t transfer_fee=0)
{
  printf("\n----**TEST**----\n");

  p->setCurrentClub(old_fc);

  printf("Player: %s\n", p->getFullName().c_str());

  if(p->getCurrentClub())
  {
    printf("Old club: %s\n", p->getCurrentClub()->getPresentClubString().c_str());
  }
  else
  {
    printf("%s is free agent.\n", p->getLastName().c_str());
  }

  printf("New club: %s\n", new_fc->getPresentClubString().c_str());

  printf("__Transfer phase__\n");

  if(p->getCurrentClub())
  {
    new_fc->transferMoneyTo(p->getCurrentClub(), transfer_fee);
    printf("Old club: %s\n", p->getCurrentClub()->getPresentClubString().c_str());
  }

  p->setCurrentClub(new_fc);
  
  printf("New club: %s\n", p->getCurrentClub()->getPresentClubString().c_str());
}

int main()
{
  Player* p1 = new Player("Cristiano", "Ronaldo", "",
		                      93, 81, 37);

  FootballClub* fc1 = new FootballClub("Real Madrid Club de Futbol",
		                                   "Real Madrid",
				                               "Los Blancos",
				                               300000000);

  FootballClub* fc2 = new FootballClub("Manchester United Football Club",
		                                   "Man United",
				                               "Red Devils",
				                               250000000);

  do_test(p1, fc2, fc1, 185000000);
}
