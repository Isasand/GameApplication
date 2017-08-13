#pragma once

#include <iostream>//std::string

class Player
{
public:
	Player(std::string argName, std::string argPosition, std::string argValue, std::string argSport) { m_Name = argName; m_Position = argPosition; m_Value = argValue; m_TeamName = ""; m_Sport = argSport; };
	Player() { m_TeamName = ""; };
	~Player() {};

	std::string getName();
	std::string getPosition();
	std::string getTeamName();
	void setTeamName(std::string argname);
	std::string getValue();
	std::string getSport();
	void getPlayerInfo();

protected:
	std::string m_Name;
	std::string m_Position;
	std::string m_TeamName;
	std::string m_Value;
	std::string m_Sport;
};