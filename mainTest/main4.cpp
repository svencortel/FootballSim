#include "Player.h"
#include "FootballClub.h"

#include <utility>
#include <map>

using std::pair;
using std::map;

typedef map<string, Player*> player_map;
typedef pair<string, Player*> player_map_pair;

player_map_pair ppair(string fname, string lname, string alias,
                     uint8_t atk, uint8_t mid, uint8_t def)
{
  Player *p = new Player(fname, lname, alias, atk, mid, def);
  return {p->getFullName(), p};
}

int main()
{
  printf("\n ---- TEST 1 ----\n");

  FootballClub* real = new FootballClub("Real Madrid Club de Futbol",
                                        "Real Madrid",
                                        "Los Blancos",
                                        300000000);

  printf("%s\n", real->getAllPlayersString().c_str());

  printf("\n ---- TEST 2 ----\n");

  vector<Player*> more_players = { new Player("Keylor", "Navas", "", 31, 24, 44),
                                   new Player("Alvaro", "Odriozola", "", 31, 24, 44),
                                   new Player("Toni", "Kroos", "", 31, 24, 44),
                                   new Player("Dani", "Carvajal", "", 31, 24, 44),
                                   new Player("Raphael", "Varane", "", 31, 24, 44),
                                   new Player("Jose", "Ignacio", "Nacho", 31, 24, 44),
                                   new Player("Mateo", "Kovacic", "", 31, 24, 44),
                                   new Player("Cristiano", "Ronaldo", "", 92, 83, 45),
                                   new Player("Gareth", "Bale", "", 92, 83, 45),
                                   new Player("Marcelo", "Vieira", "Marcelo", 92, 83, 45),
                                   new Player("Sergio", "Ramos", "", 92, 83, 45),
                                   new Player("Karim", "Benzema", "", 92, 83, 45),
                                   new Player("Luka", "Modric", "", 92, 83, 45),
                                   new Player("Francisco", "Roman", "Isco", 92, 83, 45),
                                   new Player("Marco", "Asensio", "", 92, 83, 45),
                                 };

  real->addPlayers(more_players);

  printf("%s\n", real->getAllPlayersString().c_str());

  printf("\n ---- TEST 3 ----\n");

  real->addPlayer(new Player("Dani", "Ceballos", "", 80, 80, 64));

  printf("%s\n", real->getAllPlayersString().c_str());

  return 0;
}
