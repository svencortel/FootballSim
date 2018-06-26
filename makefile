main1:
	g++ mainTest/main1.cpp src/Player.cpp -o build/main1 -I include
main2:
	g++ mainTest/main2.cpp src/Player.cpp src/FootballClub.cpp -o build/main2 -I include
main3:
	g++ mainTest/main3.cpp src/Player.cpp src/FootballClub.cpp -o build/main3 -I include
