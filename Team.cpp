#include "Team.h"
#include <iostream>
using namespace std;

Team::Team()
{
	m_GamesPlayed = 0; 
	m_GamesWon = 0; 
	m_Ties = 0; 
	m_GamesLost = 0;
}


Team::~Team()
{
}

void Team::PrintInfo() 
{
	std::string name = getTeamName();

	cout << name << "\n";
	cout << "Games played: " << m_GamesPlayed << "\n";
	cout << "Games won: " << m_GamesWon << "\n";
	cout << "Games Lost: " << m_GamesLost << "\n";
	cout << "Ties: " << m_Ties << "\n";
}

void Team::Win() 
{
	m_GamesWon += 1;
}

void Team::Tie() 
{
	m_Ties += 1;
}

void Team::Lost() 
{
	m_GamesLost+= 1;
}

void Team::PlayedGame() 
{
	m_GamesPlayed += 1;
}

void Team::setTeamName(std::string argName) 
{
	m_TeamName = argName;
}

std::string Team::getTeamName() 
{
	return m_TeamName;
}
