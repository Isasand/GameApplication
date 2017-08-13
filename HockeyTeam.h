
#include "Team.h"
#include "Hockeyplayer.h"//to be able to declare object from hockeyplayer-class
#include <stdlib.h>//atoi()
#include <vector>
class Hockeyteam : public Team
{
public:
	Hockeyteam() { m_GamesPlayed = 0; m_GamesWon = 0; m_Ties = 0; m_GamesLost = 0; };
	~Hockeyteam() {
		for (int i = 0; i < m_Team.size(); i++) {
			delete m_Team[i];
			m_Team.clear();
		}
	};

	void AddPlayer(Hockeyplayer* newplayer);
	void setPlayersTeam(std::string playerName, std::string teamName);
	void ResetAllPlayersTeam();
	void ResetTeam();
	void PrintTeam();
	void PrintPlayerInfo();
	int getPlayerScore();
	std::string getPlayersTeam(std::string argPlayerName);

	Hockeyplayer get(std::string argPosition);//method to get a player (not random)
	Hockeyplayer getRandom(std::string argPosition);//method to get a random player

protected:
	std::vector<Hockeyplayer*> m_Team; //vector of all the players in the team, containing objects from players-class 
};
