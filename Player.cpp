#include "Player.h"

#include <iostream>
#include <string>


std::string Player::getName()
{
	return m_Name;
}

std::string Player::getPosition() 
{
	return m_Position;
}

std::string Player::getTeamName() 
{
	return m_TeamName;
};

void Player::setTeamName(std::string argName) 
{
	m_TeamName = argName;
};
std::string Player::getValue() 
{
	return m_Value;
}

std::string Player::getSport() 
{
	return m_Sport;
}

void Player::getPlayerInfo() 
{
	std::cout << m_Position  << ", " << m_Name << " Score: " << m_Value << std::endl;
}