// Blackjack Homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Kenan Yusein 71947
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h> // for system("CLS"); - clearing console screen

void gameSETUP(Player& player, int& k, char s[]);
void gameProcess(Player& player, Deck& deck);
void gameStart(Player& player, Deck& deck);
void continueORexit(Player& player, Deck& deck);
void drawCardCheckPoints(Player& player, Deck& deck);
void HitStandProbability(Player& player, Deck& deck);
void hit(Player& player, Deck& deck);
void stand(Player& player, Deck& deck);
void probability(Player& player, Deck& deck);

double calculateProbability(const Deck& deck, const Player& player);
void hostWins(Player& player);
void playerWins(Player& player);
int generateHostPoints(Deck& deck, int HostPoints = 0);
void updatePlayerPoints(const Card& card, const Deck& deck, Player& player);
void toLower(char userEntry[]);


int main()
{
	Player player;
	int k;
	char s[10];
	gameSETUP(player, k, s);
	Deck deck(k, s);

	gameProcess(player, deck);
}

void gameSETUP(Player& player, int& k, char s[])
{
	std::cout << "_ _ _ _ _ _ Welcome to Kenan's Blackjack 1.0 Game _ _ _ _ _ _" << std::endl << std::endl;
	std::cin >> player;

	//creating the deck
	std::cout << "Choose your deck: (1)Default deck, (2)custom deck: ";
	char input;
	do
	{
		std::cin >> input;
		if (input == '1' || input == '2') break;
		std::cout << "Wrong input, try again: ";
	} while (true);
	if (input == '1')
	{
		strcpy_s(s, 10, "Default");
		k = 52;
	}
	else if (input == '2')
	{
		std::cout << "Enter an unique Serial for your Deck: ";
		std::cin >> s;
		std::cout << "Enter the number of Cards you want in your Deck: ";
		std::cin >> k;
	}
}

void gameProcess(Player& player, Deck& deck)
{
	gameStart(player, deck);
	drawCardCheckPoints(player, deck);
	HitStandProbability(player, deck);
}

void gameStart(Player& player, Deck& deck)
{
	player.setCurrentPoints(0);
	system("CLS"); // clear console 
	std::cout << "_ _ _ _ _ _ Welcome to Kenan's Blackjack 1.0 Game _ _ _ _ _ _" << std::endl << std::endl;
	std::cout << player << std::endl;
	std::cout << " START ! " << std::endl;
	int notDrawedCardsNumber = 0;
	for (int i = 0; i < deck.getK(); i++)
	{
		if (deck.getDeck()[i].getDrawed() == 0) notDrawedCardsNumber++;
	}
	std::cout << "Your Deck has " << notDrawedCardsNumber << " remainung non-drawed cards." << std::endl;
	if (notDrawedCardsNumber == 0)
	{
		deck.shuffleDeck();
		std::cout << "Your deck has been re-SHUFFLED;  Remaining cards: " << deck.getK() << std::endl;
	}
}
void continueORexit(Player& player, Deck& deck)
{
	char entry;
	std::cout << "Continue(0);  Exit(1):  ";
	do
	{
		std::cin >> entry;
		if (entry == '1' || entry == '0') break;
		std::cout << "Wrong input, try again: ";
	} while (true);

	if (entry == '0')
	{
		gameProcess(player, deck);
	}
	if (entry == '1')
	{
		std::cout << "Exiting game . . .";
		exit(0);
	}
}
void drawCardCheckPoints(Player& player, Deck& deck)
{
	Card currentCard;
	currentCard = deck.draw();
	updatePlayerPoints(currentCard, deck, player);
	std::cout << currentCard << "  Your Total Current Points: " << player.getCurrentPoints() << std::endl << std::endl;

	//check points - winner?
	if (player.getCurrentPoints() > 21)
	{
		hostWins(player);
		continueORexit(player, deck);
	}
	if (player.getCurrentPoints() == 21)
	{
		std::cout << "BLACKJACK! ";
		playerWins(player);
		continueORexit(player, deck);
	}
}
void HitStandProbability(Player& player, Deck& deck)
{
	char userEntry[20];
	std::cout << "Hit/Stand/Probability: ";
	do
	{
		std::cin >> userEntry;
		toLower(userEntry);
		if (strcmp(userEntry, "hit") == 0 || strcmp(userEntry, "stand") == 0 || strcmp(userEntry, "probability") == 0) break;
		std::cout << "Wrong input, try again: ";
	} while (true);

	if (strcmp(userEntry, "hit") == 0)
	{
		hit(player, deck);
	}
	else if (strcmp(userEntry, "stand") == 0)
	{
		stand(player, deck);

		std::cout << std::endl << "Hosts cards:" << std::endl;
		int hostpoints = generateHostPoints(deck);
		std::cout << "Host's points: " << hostpoints << std::endl;
		if (hostpoints > 21)
		{
			playerWins(player);

		}
		if (hostpoints >= 17 && hostpoints <= 21)
		{
			if (hostpoints > player.getCurrentPoints()) hostWins(player);
			else playerWins(player);

		}
	}
	else if (strcmp(userEntry, "probability") == 0)
	{
		probability(player, deck);

		std::cout << "Probability for Blackjack(21points):  " << calculateProbability(deck, player) << std::endl;
	}
}
void hit(Player& player, Deck& deck)
{
	drawCardCheckPoints(player, deck);
	HitStandProbability(player, deck);
}
void stand(Player& player, Deck& deck)
{
	std::cout << std::endl << "Hosts cards:" << std::endl;
	int hostpoints = generateHostPoints(deck);
	std::cout << "Host's points: " << hostpoints << std::endl;
	if (hostpoints > 21)
	{
		playerWins(player);
		continueORexit(player, deck);
	}
	if (hostpoints >= 17 && hostpoints <= 21)
	{
		if (hostpoints > player.getCurrentPoints()) hostWins(player);
		else playerWins(player);

		continueORexit(player, deck);
	}
}
void probability(Player& player, Deck& deck)
{
	std::cout << "Probability for Blackjack(21 points) with the next drawn card: " << calculateProbability(deck, player) << std::endl;
	HitStandProbability(player, deck);
}

double calculateProbability(const Deck& deck, const Player& player)
{
	double totalRemainingCards = 0;
	double fittingCards = 0;

	for (int i = 0; i < deck.getK(); i++)
	{
		if (deck.getDeck()[i].getDrawed() == 0)
		{
			int cardPoints = deck.getDeck()[i].getPoints();
			if (strcmp(deck.getDeck()[i].getValue(), "A") == 0)
			{
				if (21 - player.getCurrentPoints() == 1) cardPoints = 1;
			}

			if (21 - player.getCurrentPoints() == cardPoints) fittingCards++;
			totalRemainingCards++;
		}
	}

	return fittingCards / totalRemainingCards;
}

void hostWins(Player& player)
{
	std::cout << " You LOSE!" << std::endl << std::endl;
	player.setLoses(player.getLoses() + 1);
	player.setWinRate(player.getWins(), player.getWins() + player.getLoses());
}

void playerWins(Player& player)
{
	std::cout << " You WIN!" << std::endl << std::endl;
	player.setWins(player.getWins() + 1);
	player.setWinRate(player.getWins(), player.getWins() + player.getLoses());
}

int generateHostPoints(Deck& deck, int HostPoints)
{
	if (HostPoints >= 17) return HostPoints;
	Card current = deck.draw();
	std::cout << current << ", ";
	return generateHostPoints(deck, HostPoints + current.getPoints());
}

void updatePlayerPoints(const Card& card, const Deck& deck, Player& player)
{
	if (strcmp(card.getValue(), "A") == 0)
	{

		if (player.getCurrentPoints() + card.getPoints() > 21)
		{
			player.setCurrentPoints(player.getCurrentPoints() + 1);
		}
		else
		{
			player.setCurrentPoints(player.getCurrentPoints() + card.getPoints());
		}
	}
	else
	{
		player.setCurrentPoints(player.getCurrentPoints() + card.getPoints());
	}
}

void toLower(char userEntry[])
{
	for (int i = 0; i < strlen(userEntry); i++)
	{
		if (userEntry[i] >= 'A' && userEntry[i] <= 'Z') userEntry[i] = userEntry[i] + 32;
	}
}