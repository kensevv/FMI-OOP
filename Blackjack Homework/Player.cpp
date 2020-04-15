#include "Player.h"

Player::Player()
{
	setName("Default Default");
	this->age = 18;
	this->currentPoints = 0;
	this->wins = 0;
	this->loses = 0;
	setWinRate(0, 0);
}

 bool correctName(const char * name)
{
	int spaces = 0;
	int spaceIndex;
	for (int i = 0; i < strlen(name) + 1; i++)
	{
		if (name[i] == ' ')
		{
			spaces++;
			spaceIndex = i;
		}
	}
	if (spaces != 1) return false;

	bool correctCapitals = false;
	if (name[0] >= 'A' && name[0] <= 'Z' &&
		name[spaceIndex + 1] >= 'A' && name[spaceIndex + 1] <= 'Z') 
	{
		correctCapitals = true;
	}

	bool correctLetters = true;
	for (int i = 1; i < strlen(name); i++)
	{
		if (i == spaceIndex || i == spaceIndex + 1) continue;
		if (name[i] >= 'a' && name[i] <= 'z')
		{
			continue;
		}
		correctLetters = false;
	}
	
	return correctCapitals && correctLetters;
}

void Player::setName(const char* newName)
{
	strcpy_s(this->name, 64, newName);
}

void Player::setAge(int newAge)
{
	this->age = newAge;
}

void Player::setWins(int newWins)
{
	this->wins = newWins;
}

void Player::setLoses(int newLoses)
{
	this->loses = newLoses;
}

void Player::setWinRate(int newNumerator, int newDenominator)
{
	this->winRate.numerator = newNumerator;
	this->winRate.denominator = newDenominator;
}

void Player::setCurrentPoints(int newCurrentPoints)
{
	if(newCurrentPoints >= 0) this->currentPoints = newCurrentPoints;
}

const char* Player::getName() const
{
	return this->name;
}

int Player::getAge() const
{
	return this->age;
}

int Player::getWins() const
{
	return this->wins;
}

int Player::getLoses() const
{
	return this->loses;
}

const fractionalNumber& Player::getWinRate() const
{
	return this->winRate;
}


int Player::getCurrentPoints() const
{
	return this->currentPoints;
}

std::ostream& operator<<(std::ostream& out, const Player & player)
{
	out << "Name: " << player.name << std::endl
		<< "Age: " << player.age << std::endl
		<< "Wins: " << player.wins << std::endl
		<< "Loses: " << player.loses << std::endl
		<< "WinRate: " << player.winRate << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Player & player)
{
	std::cout << "Enter Player Name (First Last) : ";
	char name[64];
	do
	{
		in.getline(name, 64);
		if (correctName(name))
		{
			player.setName(name);
			break;
		}
		else std::cout << "Wrong input! Follow the example: First_Last. Try again: ";
	} while (true);
	
	std::cout << "Enter Player Age: ";
	int age;
	do
	{
		in >> age;
		if (age >= 18 && age <= 90)
		{
			player.age = age;
			break;
		}
		else std::cout << "Wrong input! Age must be from 18 to 90. Try again: ";
	} while (true);

	return in;
}
