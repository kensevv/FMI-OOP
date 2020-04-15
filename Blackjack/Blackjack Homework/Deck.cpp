#include "Deck.h"
#include <cstring>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

Deck::Deck()
{
	this->k = 52;
	this->deck = new Card[k];
	setS("Default");
	
	int addedCards = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			this->deck[addedCards].setColour(i);
			this->deck[addedCards].setDrawed(0);
			// TODO SERIAL KEY

			switch (j)
			{
			case 0:
				deck[addedCards].setValue("2");
				deck[addedCards].setPoints(2);
				break;
			case 1:
				deck[addedCards].setValue("3");
				deck[addedCards].setPoints(3);
				break;
			case 2:
				deck[addedCards].setValue("4");
				deck[addedCards].setPoints(4);
				break;
			case 3:
				deck[addedCards].setValue("5");
				deck[addedCards].setPoints(5);
				break;
			case 4:
				deck[addedCards].setValue("6");
				deck[addedCards].setPoints(6);
				break;
			case 5:
				deck[addedCards].setValue("7");
				deck[addedCards].setPoints(7);
				break;
			case 6:
				deck[addedCards].setValue("8");
				deck[addedCards].setPoints(8);
				break;
			case 7:
				deck[addedCards].setValue("9");
				deck[addedCards].setPoints(9);
				break;
			case 8:
				deck[addedCards].setValue("10");
				deck[addedCards].setPoints(10);
				break;
			case 9:
				deck[addedCards].setValue("J");
				deck[addedCards].setPoints(10);
				break;
			case 10:
				deck[addedCards].setValue("Q");
				deck[addedCards].setPoints(10);
				break;
			case 11:
				deck[addedCards].setValue("K");
				deck[addedCards].setPoints(10);
				break;
			case 12:
				deck[addedCards].setValue("A");
				deck[addedCards].setPoints(11); // moje da e i 1
				break;

			default:
				break;
			}


			//this->deck[addedCards].setSerialKey();

			addedCards++;
		}
	}
	shuffleDeck();
}

Deck::Deck(int newk, const char * news)
{
	setS(news);
	this -> k = newk;
	this->deck = new Card[k];

	
	Card* helperDeck = new Card[52];
	helperDeck = createDeck();
	shuffleDeck(helperDeck);

	if (this->k > 0 && this->k <= 52)
	{	
		for (int i = 0; i < this->k; i++)
		{
			this->deck[i] = helperDeck[i];
		}
	}
	
	if (this->k > 52)
	{
		int addedCards = 0;
		for (int i = 0; i < 52; i++)
		{
			this->deck[addedCards] = helperDeck[i];
			addedCards++;
		}
		
		for (int i = 0; i < this->k / 52; i++)
		{
			shuffleDeck(helperDeck);
			for (int j = 0; j < k - 52 ; j++)
			{
				if (addedCards == k) break;
				if (j == 52) break;
				this->deck[addedCards] = helperDeck[j];
				addedCards++;
			}
		}
	}
	delete[] helperDeck;

	//TODO : for - setS for all cards on deck
}

Deck::~Deck()
{
	delete[] this->deck;
}

Card * Deck::createDeck()
{
	Card * newDeck = new Card[52];
	int addedCards = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			newDeck[addedCards].setColour(i);
			newDeck[addedCards].setDrawed(0);
			//TODO serialKEY

			switch (j)
			{
			case 0:
				newDeck[addedCards].setValue("2");
				newDeck[addedCards].setPoints(2);
				break;
			case 1:
				newDeck[addedCards].setValue("3");
				newDeck[addedCards].setPoints(3);
				break;
			case 2:
				newDeck[addedCards].setValue("4");
				newDeck[addedCards].setPoints(4);
				break;
			case 3:
				newDeck[addedCards].setValue("5");
				newDeck[addedCards].setPoints(5);
				break;
			case 4:
				newDeck[addedCards].setValue("6");
				newDeck[addedCards].setPoints(6);
				break;
			case 5:
				newDeck[addedCards].setValue("7");
				newDeck[addedCards].setPoints(7);
				break;
			case 6:
				newDeck[addedCards].setValue("8");
				newDeck[addedCards].setPoints(8);
				break;
			case 7:
				newDeck[addedCards].setValue("9");
				newDeck[addedCards].setPoints(9);
				break;
			case 8:
				newDeck[addedCards].setValue("10");
				newDeck[addedCards].setPoints(10);
				break;
			case 9:
				newDeck[addedCards].setValue("J");
				newDeck[addedCards].setPoints(10);
				break;
			case 10:
				newDeck[addedCards].setValue("Q");
				newDeck[addedCards].setPoints(10);
				break;
			case 11:
				newDeck[addedCards].setValue("K");
				newDeck[addedCards].setPoints(10);
				break;
			case 12:
				newDeck[addedCards].setValue("A");
				newDeck[addedCards].setPoints(11); // moje da e i 1
				break;

			default:
				break;
			}
			addedCards++;
		}
	}

	//shuffleDeck(newDeck);
	return newDeck;
}

void Deck::swap(int card1, int card2)
{
	if (card1 <= this->k && card2 <= this->k)
	{
		Card temp;
		temp = this->deck[card1];
		this->deck[card1] = this->deck[card2];
		this->deck[card2] = temp;
	}
	else
	{
		//std::cout << "wrong input";
	}
}
void Deck::shuffleDeck()
{
	srand(time(NULL));
	for (int i = 0; i < this->k; i++)
	{
		deck[i].setDrawed(0);
		int r = i + (rand() % (this->k - i));
		Deck::swap(i, r);
	}
}
void Deck::swap(Card newDeck[], int card1, int card2)
{
	if (card1 <= 52 && card2 <= 52)
	{
		Card temp;
		temp = newDeck[card1];
		newDeck[card1] = newDeck[card2];
		newDeck[card2] = temp;
	}
	else
	{
		//std::cout << "wrong input";
	}
}
void Deck::shuffleDeck(Card newDeck[])
{
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		newDeck[i].setDrawed(0);
		int r = i + (rand() % (52 - i));
		Deck::swap(newDeck,i, r);
	}
}

int Deck::suit_count(const CardColour & colour)
{
	int number = 0;

	for (int i = 0; i < this->k; i++)
	{
		if (deck[i].getColour() == colour) number++;
	}
	return number;
}

int Deck::rank_count(char* othervalue)
{
	int number = 0;

	for (int i = 0; i < this->k; i++)
	{
		if (strcmp(deck[i].getValue(), othervalue) == 0 && this->deck[i].getDrawed() == 0)
		{
			number++;
		}
	}
	return number;
}

void Deck::setS(const char* newS)
{
	strcpy_s(this->s, strlen(newS) + 1, newS);
}

const char* Deck::getS() const
{
	return this->s;
}

void Deck::setK(int newK)
{
	this->k = newK;
}

int Deck::getK() const
{
	return this->k;
}

void Deck::setDeck(const Card* newDeck)
{
	delete[] this->deck;
	this->deck = new Card[this->k];
	for (int i = 0; i < this->k; i++)
	{
		this->deck[i] = newDeck[i];
	}
}

const Card* Deck::getDeck() const
{
	return this->deck;
}

const Card& Deck::draw()
{
	Card* newBuffer = new Card[this->k];
	for (int i = 0; i < this->k - 1; i++)
	{
		newBuffer[i] = this->deck[i + 1];
	}
	newBuffer[k-1] = this->deck[0];

	delete[] this->deck;
	deck = newBuffer;

	newBuffer[this->k - 1].setDrawed(1);
	return newBuffer[this->k-1];
}



