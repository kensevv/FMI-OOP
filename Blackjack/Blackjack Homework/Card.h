#pragma once
#include"CardColour.h"
#include <iostream>

class Card
{
private:
	CardColour colour; // Spades, Hearts, Diamonds, and Clubs
	char value[3]; // 2,3,4,5,6,7,8,9,10,J,Q,K,A
	char serialKey[25];
	bool drawed;
	int points;
public:
	Card();

	void setColour(CardColour newColour);
	void setColour(int newColour);
	void setValue(const char * newValue);
	void setSerialKey(const char * newSerialKey);
	void setDrawed(bool newDrawed);
	void setPoints(int newPoints);
	const CardColour getColour()const;
	const char* getValue()const;
	const char* getSerialKey()const;
	bool getDrawed()const;
	int getPoints() const;

	Card& operator=(const Card& other);
	friend std::ostream& operator<<(std::ostream& out, const Card & card);
	bool operator==(const CardColour & colour);
};

