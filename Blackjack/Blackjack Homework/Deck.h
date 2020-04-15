#pragma once
#include "Card.h"

class Deck
{
private:
	char s[10];
	int k;
	Card* deck;
public:
	Deck();
	Deck(int newk, const char * news);
	~Deck();

	Card* createDeck();
	void shuffleDeck();
	void shuffleDeck(Card newDeck[]);

	void setS(const char * newSeria);
	const char* getS()const;

	void setK(int newK);
	int getK()const;

	void setDeck(const Card * newDeck);
	const Card* getDeck()const;

	//
	const Card& draw();
	void swap(int card1, int card2);
	void swap(Card  newDeck[], int card1, int card2);
	int suit_count(const CardColour& colour);
	int rank_count(char * value);

	
};

