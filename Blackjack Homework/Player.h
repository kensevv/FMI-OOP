#pragma once
#include "Deck.h"
#include <iostream>
#include "fractionalNumber.h"
class Player
{
private:
	char name[64];
	int age; //18-90
	int wins;
	int loses;
	fractionalNumber winRate;
	int currentPoints; // polojitelno chislo

public:
	//
	Player();

	friend std::ostream& operator<<(std::ostream& out, const Player & player);
	friend std::istream& operator>>(std::istream& in, Player & player);
	//setters getters
	friend bool correctName(const char * name);

	void setName(const char* newName);
	void setAge(int newAge);
	void setWins(int newWins);
	void setLoses(int newLoses);
	void setWinRate(int newNumerator, int newDenominator);
	void setCurrentPoints(int newCurrentPoints);

	const char* getName()const;
	int getAge()const;
	int getWins()const;
	int getLoses()const;
	const fractionalNumber& getWinRate()const;
	int getCurrentPoints()const;

};

