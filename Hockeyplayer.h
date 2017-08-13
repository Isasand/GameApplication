#pragma once
#include "Player.h"
class Hockeyplayer : public Player
{
public:
	Hockeyplayer(std::string argName, std::string argPosition, std::string argValue, std::string argSport) : Player(argName, argPosition, argValue, argSport) {};
	Hockeyplayer() { m_Sport = "Hockey", m_TeamName = ""; }; //tom konstruktor som sätter typ av sport och m_team till blank
	~Hockeyplayer();
};

