#pragma once
#include <iostream>
#include <string>


class Team
{
public:
	Team();
	~Team();

	int m_GamesPlayed;
	int m_GamesWon;
	int m_Ties;
	int m_GamesLost;
	void PrintInfo();
	void Win();
	void Tie();
	void Lost();
	void PlayedGame();
	void setTeamName(std::string argNamw);
	std::string getTeamName();

protected:
	std::string m_TeamName;
};

