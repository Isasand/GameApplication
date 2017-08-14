#include "Team.h"
#include "Hockeyteam.h"
#include "Footballteam.h"
#include "Player.h"
#include "Hockeyplayer.h"
#include "Footballplayer.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <cstring>
#include <Windows.h>
using namespace std;

template <typename t>

void IfNameAlike(t* team1, t* team2) {
	while (team2->getTeamName() == team1->getTeamName()) {
		cout << "Hey, that name is taken!" << endl;
		team2->setTeamName(NamingRandomteam2());
		cout << endl;
	}
	
}

template <typename t2>

void Game(int score1, int score2, t2* team1, t2* team2) {
	if (score1<score2) {
		team1->Lost();
		team2->Win();
		cout << team2->getTeamName() << " wins!" << endl;
	}

	if (score1>score2) {
		team1->Win();
		team2->Lost();
		cout << team1->getTeamName() << " wins!" << endl;
	}

	if (score1 == score2) {
		team1->Tie();
		team2->Tie();
		cout << "Its a tie!" << endl;
	}
	team1->PlayedGame();
	team2->PlayedGame();
}

int HockeyOrFootball();
void AddAllPlayers(int choice, Hockeyteam* hockeyPlayers, Footballteam* footballPlayers, string t1, string t2, string t3, string t4);
string NamingRandomteam1();
string NamingRandomteam2();
void HockeyDraft(Hockeyteam *team, Hockeyteam *players, string teamName, string position[6], Hockeyplayer teamPlayer[6]);
void FootballDraft(Footballteam *team, Footballteam *players, string teamName, string position[11], Footballplayer teamplayer[11]);
void NextGameorGamestats(int i);


int main() {

	int choice;
	Hockeyteam *allHockeyPlayers = new Hockeyteam();//team of players containing all players in the file
	Footballteam *allFootballPlayers = new Footballteam();

	ifstream readFile;
	readFile.open("spelarinfo.txt");//stream to read file 

	choice = HockeyOrFootball();
	cin.get();

	string line, t_Name, t_Position, t_Value, t_Sport;

	while (getline(readFile, line)) {//read file to line 
		stringstream split(line);//split the line with stringstream into name, position, value and sport
		getline(split, t_Name, ':');
		getline(split, t_Position, ':');
		getline(split, t_Value, ':');
		getline(split, t_Sport, ':');
		AddAllPlayers(choice, allHockeyPlayers, allFootballPlayers, t_Name, t_Position, t_Value, t_Sport);
	}

	readFile.close();

	if (choice == 1) {
		Hockeyteam *randomteam1 = new Hockeyteam();//create to teams
		Hockeyteam *randomteam2 = new Hockeyteam();

		randomteam1->setTeamName(NamingRandomteam1());//name the teams
		randomteam2->setTeamName(NamingRandomteam2());
		IfNameAlike(randomteam1, randomteam2);

		string position[6] = { "Goalkeeper", "Defense", "Defense", "Defense", "Forward", "Forward" };//array of påositions for filling the team
		Hockeyplayer teamPlayer[6];
		Hockeyplayer teamPlayer2[6];


		for (int i = 0; i<3; i++) {
			allHockeyPlayers->ResetAllPlayersTeam();//resetar all players teams
			randomteam1->ResetTeam();
			randomteam2->ResetTeam();

			HockeyDraft(randomteam1, allHockeyPlayers, randomteam1->getTeamName(), position, teamPlayer);//drafting the first random team 
			randomteam1->PrintPlayerInfo();
			cout << "Total playerscore: " << randomteam1->getPlayerScore() << endl << endl;//printing playerscore

			HockeyDraft(randomteam2, allHockeyPlayers, randomteam2->getTeamName(), position, teamPlayer2);//drafting the second team
			randomteam2->PrintPlayerInfo();
			cout << "Total playerscore: " << randomteam2->getPlayerScore() << endl << endl;//printing playerscore

			Game(randomteam1->getPlayerScore(), randomteam2->getPlayerScore(), randomteam1, randomteam2);//playing a game betweed the two teams
			NextGameorGamestats(i);

			cin.get();
			system("CLS");
		}
		cout << "Game results: " << endl;
		randomteam1->PrintInfo();
		randomteam2->PrintInfo();
	}

	else if (choice = 2) {
		Footballteam *randomteam1 = new Footballteam();//create two teams
		Footballteam *randomteam2 = new Footballteam();

		randomteam1->setTeamName(NamingRandomteam1());//naming them
		randomteam2->setTeamName(NamingRandomteam2());
		IfNameAlike(randomteam1, randomteam2);

		string position[11] = { "Goalkeeper", "Defense", "Defense", "Defense", "Defense", "Defense", "Midfielder", "Midfielder", "Midfielder", "Forward", "Forward" };//array av positioner så att vi kan leta igenom laget
		Footballplayer teamPlayer[11];
		Footballplayer teamPlayer2[11];

		for (int i = 0; i < 3; i++) {
			allFootballPlayers->ResetAllPlayersTeam();//reseting all players teams
			randomteam1->ResetTeam();
			randomteam2->ResetTeam();

			FootballDraft(randomteam1, allFootballPlayers, randomteam1->getTeamName(), position, teamPlayer);//drafting random team one 
			randomteam1->PrintPlayerInfo();//printing player info of the team
			cout << "Total playervalue: " << randomteam1->getPlayerScore() << endl << endl;//printing total value of the drafted team

			FootballDraft(randomteam2, allFootballPlayers, randomteam2->getTeamName(), position, teamPlayer2);//drafting second team
			randomteam2->PrintPlayerInfo();
			cout << "Total playervalue: " << randomteam2->getPlayerScore() << endl << endl;

			Game(randomteam1->getPlayerScore(), randomteam2->getPlayerScore(), randomteam1, randomteam2);
			NextGameorGamestats(i);

			cin.get();
			system("CLS");
		}
		cout << "Game results: " << endl;
		randomteam1->PrintInfo();
		randomteam2->PrintInfo();
	}
	cin.get();
	return 0;
}


//functions

int HockeyOrFootball() {
	int choice;
	cout << "Lets play best of three, hockey(1) or football(2)? ";
	cin >> choice;
	return choice;
}

void AddAllPlayers(int choice, Hockeyteam* hockeyPlayers, Footballteam* footballPlayers, string t1, string t2, string t3, string t4) {
	if (choice == 1) {
		Hockeyplayer *player = new Hockeyplayer(t1, t2, t3, t4);//create a temporary hockeyplayer
		if (player->getName() != "") {//a vector may get an empty spot at initialization because the constructor contains element with an assigned value, 
									  //therefore im checking it so it wont be added as an empty player
			hockeyPlayers->AddPlayer(player);//put in the team containing all players
		}
	}
	if (choice == 2) {
		Footballplayer *player = new Footballplayer(t1, t2, t3, t4);//create a temporary footballplayer
		if (player->getName() != "") {//vektorerna får en tom plats med konstruktorn för att den innehåller element som är har ett värde satt, så jag kollar att den inte kommer med 
			footballPlayers->AddPlayer(player);
		}
	}
}

string NamingRandomteam1() {
	string name;
	cout << "Give a name to random team 1: ";
	getline(cin, name);
	return name;
}

string  NamingRandomteam2() {
	string name;
	cout << "Give a name to random team 2: ";
	getline(cin, name);
	return name;
}

void HockeyDraft(Hockeyteam *team, Hockeyteam *players, string teamName, string position[6], Hockeyplayer teamPlayer[6]) {
	cout << "drafting players for " << team->getTeamName();
	Sleep(500);
	for (int i = 0; i<3; i++) {
		cout << ".";
		Sleep(300);
	}
	cout << endl << endl;

	for (int i = 0; i<6; i++) {
		teamPlayer[i] = players->getRandom(position[i]);
		team->AddPlayer(&teamPlayer[i]);
		team->setPlayersTeam(teamPlayer[i].getName(), teamName);
		players->setPlayersTeam(teamPlayer[i].getName(), teamName);
	}
}

void FootballDraft(Footballteam *team, Footballteam *players, string teamName, string position[11], Footballplayer teamPlayer[11]) {
	cout << "drafting players for " << team->getTeamName();
	Sleep(500);
	for (int i = 0; i<3; i++) {
		cout << ".";
		Sleep(300);
	}
	cout << endl << endl;

	for (int i = 0; i<11; i++) {
		teamPlayer[i] = players->getRandom(position[i]);
		team->AddPlayer(&teamPlayer[i]);
		team->setPlayersTeam(teamPlayer[i].getName(), teamName);
		players->setPlayersTeam(teamPlayer[i].getName(), teamName);
	}
}

void NextGameorGamestats(int i) {
	if (i != 2)
		cout << "Press Enter to play next game!";
	else
		cout << "Press Enter to see game stats!";
}