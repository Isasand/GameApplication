#pragma once
#include "Team.h"
#include "Footballplayer.h"
#include <vector>//std::vector
#include <iostream>//std::string


class Footballteam : public Team
{
public:
	Footballteam() { m_GamesPlayed = 0; m_GamesWon = 0; m_Ties = 0; m_GamesLost = 0; };
	~Footballteam() { for (int i = 0; i < m_Team.size(); i++) { m_Team.clear(); } };

	void AddPlayer(Footballplayer* newplayer);
	void setPlayersTeam(std::string playername, std::string teamname);
	void ResetAllPlayersTeam();
	void ResetTeam();
	void PrintTeam();
	void PrintPlayerInfo();
	int getPlayerScore();
	std::string getPlayersTeam(std::string argPayerName);

	Footballplayer get(std::string argPosition);//method to get player, not random
	Footballplayer getRandom(std::string argPosition);//method to get random player

protected:
	std::vector<Footballplayer*> m_Team;//all players in the team
};
