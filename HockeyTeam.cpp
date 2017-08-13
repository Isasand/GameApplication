#include "HockeyTeam.h"
#include <time.h>
#include <cstring>
#include <vector>

void Hockeyteam::AddPlayer(Hockeyplayer* newplayer) {//add a player to team
	m_Team.push_back(newplayer);
};

void Hockeyteam::setPlayersTeam(std::string argPlayerName, std::string argTeamName) {//decide ¨what team a player belongs to
	for (int i = 0; i<m_Team.size(); i++) {
		if (m_Team.at(i)->getName() == argPlayerName) {
			m_Team.at(i)->setTeamName(argTeamName);
		}
	}
}

void Hockeyteam::ResetAllPlayersTeam() {//reset all team names in the team 
	for (int i = 0; i < m_Team.size(); i++) {
		m_Team.at(i)->setTeamName("");
	}
}

void Hockeyteam::ResetTeam() {//clearing the team vector
	m_Team.clear();
}

void Hockeyteam::PrintTeam() {//printing team
	for (int i = 0; i<m_Team.size(); i++)
		std::cout << m_Team.at(i) -> getName() << std::endl;
};

void Hockeyteam::PrintPlayerInfo() {//loop through the team and every players info-method
	for (int i = 0; i<m_Team.size(); i++) {
		m_Team.at(i)->getPlayerInfo();
	}
}

std::string Hockeyteam::getPlayersTeam(std::string argPlayerName) {//get a players team
	for (int i = 0; i < m_Team.size(); i++) {
		if (m_Team.at(i)->getName() == argPlayerName) {
			return m_Team.at(i) -> getTeamName();
		}
	}
}

int Hockeyteam::getPlayerScore() {//add all players score together to get totral team value

	//why is m_value not an int from the beginning? need to clean up this method
	std::string str;
	char foo[2];
	int sum = 0;
	int temp;

	for (int i = 0; i < m_Team.size(); i++) {
		str = m_Team.at(i) -> getValue();//str gets the value from the object
		strcpy_s(foo, str.c_str());//making the string to a char array 
		temp = atoi(foo);//change it to an int
		sum += temp;
	}
	return sum;//return total sum of values
}

Hockeyplayer Hockeyteam::get(std::string argPosition) //create a player based on position, not a random method but taking the first matching player
{
	Hockeyplayer returnValue;
	std::vector<Hockeyplayer*>temp;//temp vector of players
	for (int i = 0; i < m_Team.size(); i++) {
		if ((m_Team.at(i)->getPosition() == argPosition) && (m_Team.at(i)->getTeamName() == "") && (m_Team.at(i)->getName() != "") && (m_Team.at(i)->getSport() == "Hockey")) {
			//if the position matches and the player does not belong to a team already, plus matching sport 
			temp.push_back(m_Team.at(i));//push back to vector of players
		}
	}
	if (temp.size() != 0) {//as long as the vector aint empty
		returnValue = *temp.at(0);
		return returnValue; //return returnvalue
	}
}

Hockeyplayer Hockeyteam::getRandom(std::string argPosition) {//create a player randomly based on position
	Hockeyplayer returnValue;
	std::vector<Hockeyplayer*> temp;//temporary vector of players
	int i = 0;//int made to store random value  
	bool NotFound = true;
	srand(time(0));//seeds a seed value for rand
	int Teamsize;
	Teamsize = m_Team.size();

	while (NotFound) {
		i = rand() % Teamsize;//generates a random int betweed 0-teamsize
		if ((m_Team.at(i)->getPosition() == argPosition) && (m_Team.at(i)->getTeamName() == "") && (m_Team.at(i)->getName() != "") && (m_Team.at(i)->getSport() == "Hockey")) {
			temp.push_back(m_Team.at(i));//if the player that is found matches, push back, otherwise the loop will continue
			NotFound = false;
		}
	}

	if (temp.size() != 0) {//if it aint empty
		returnValue = *temp.at(0);
		return returnValue;//send the player back
	}
}