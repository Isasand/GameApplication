#include "Footballteam.h"
#include <stdlib.h>//rand(), srand()
#include <time.h>//time()
#include <cstring>//strcpy
#include <vector>

void Footballteam::AddPlayer(Footballplayer* newPlayer) {//add player to a team
	m_Team.push_back(newPlayer);
};

void Footballteam::setPlayersTeam(std::string argPlayerName, std::string argTeamName) {//set players team 
	for (int i = 0; i < m_Team.size(); i++) {
		if (m_Team.at(i)->getName() == argPlayerName) {
			m_Team.at(i)->setTeamName(argTeamName);
		}
	}
}

void Footballteam::ResetAllPlayersTeam() {//reset all players team
	for (int i = 0; i < m_Team.size(); i++) {
		m_Team.at(i)->setTeamName("");
	}
}

void Footballteam::ResetTeam() {//clearing the team vector
	m_Team.clear();
}

void Footballteam::PrintTeam() {//printing the team
	for (int i = 0; i < m_Team.size(); i++)
		std::cout << m_Team.at(i)->getName() << std::endl;
};

void Footballteam::PrintPlayerInfo() {//loop through the team and every players info-method

	for (int i = 0; i < m_Team.size(); i++) {
		m_Team.at(i)->getPlayerInfo();
	}
}

std::string Footballteam::getPlayersTeam(std::string argPlayerName) {//get players team
	for (int i = 0; i < m_Team.size(); i++) {
		if (m_Team.at(i)->getName() == argPlayerName) {
			return m_Team.at(i)->getTeamName();
		}
	}
}

int Footballteam::getPlayerScore() {//add upp all players value and get total team value
	std::string str;
	char foo[2];
	int sum = 0;
	int temp;

	for (int i = 0; i < m_Team.size(); i++) {
		str = m_Team.at(i)->getValue();//let str get the value of the object
		strcpy_s(foo, str.c_str());//make the string a char array 
		temp = atoi(foo);//change it to an int
		sum += temp; //put them all together
	}
	return sum;//return the sum 
}

Footballplayer Footballteam::get(std::string argPosition) {//create player based on position - this method is not random, it is picking the first matching player 
	Footballplayer returnValue;
	std::vector<Footballplayer*>temp;//temporary vector with hockey players
	for (int i = 0; i < m_Team.size(); i++) {
		if ((m_Team.at(i)->getPosition() == argPosition) && (m_Team.at(i)->getTeamName() == "") && (m_Team.at(i)->getName() != "") && (m_Team.at(i)->getSport() == "Football")) {//if position matches and the player does not already belong to a team
			temp.push_back(m_Team.at(i));//push back the temp vector of players
		}
	}
	if (temp.size() != 0) {//as long as temp size is not zero
		returnValue = *temp.at(0);//let return value get the temporary value
		return returnValue; //return return value
	}
}

Footballplayer Footballteam::getRandom(std::string argPosition) {//create a random player based on position
	Footballplayer returnValue;
	std::vector<Footballplayer*> temp;//temporary vector of hockey players
	int i = 0; //int to store a random value 
	bool NotFound = true;
	srand(time(0));//sets a seed value for rand 
	int Teamsize;
	Teamsize = m_Team.size();

	while (NotFound) {
		i = rand() % Teamsize;//generates a random int between 0-teamsize
		if ((m_Team.at(i)->getPosition() == argPosition) && (m_Team.at(i)->getTeamName() == "") && (m_Team.at(i)->getName() != "") && (m_Team.at(i)->getSport() == "Football")) {
			temp.push_back(m_Team.at(i));
			NotFound = false;
		}
	}

	if (temp.size() != 0) {//if the vector is not empty
		returnValue = *temp.at(0);
		return returnValue;//send a player as return
	}
}