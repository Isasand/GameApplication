#pragma once
#include "Player.h"
#include <iostream>

class Footballplayer : public Player
{
public:
	Footballplayer(std::string argname, std::string argposition, std::string argvalue, std::string argsport) : Player(argname, argposition, argvalue, argsport) {};
	Footballplayer() { 
		m_Sport = "Hockey", m_TeamName = ""; 
	}; //tom konstruktor som sätter typ av sport och m_team till blank
	~Footballplayer();
	
};

