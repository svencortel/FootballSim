all:
	make main1 && make main2 && make main3
main1:
	g++ -std=c++17 mainTest/main1.cpp src/Player.cpp -o build/main1 -I include
main2:
	g++ -std=c++17 mainTest/main2.cpp src/Player.cpp src/FootballClub.cpp -o build/main2 -I include
main3:
	g++ -std=c++17 mainTest/main3.cpp src/Player.cpp src/FootballClub.cpp -o build/main3 -I include
