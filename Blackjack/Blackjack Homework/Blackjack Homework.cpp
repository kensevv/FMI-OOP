// Blackjack Homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Kenan Yusein 71947
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h> // for system("CLS"); - clearing console screen

double calculateProbability(const Deck& deck, const Player& player);
void hostWins(Player& player);
void playerWins(Player& player);
int generateHostPoints(Deck& deck, int HostPoints = 0);
void updatePlayerPoints(const Card& card, const Deck& deck, Player& player);
void toLower(char userEntry[]);
//void updatePlayer(Player& player, int HostPoints);

void game();

int main()
{
	game();
	system("pause");
}

void game()
{
	std::cout << "_ _ _ _ _ _ Welcome to Kenan's Blackjack 1.0 Game _ _ _ _ _ _" << std::endl << std::endl;
	Player player;
	std::cin >> player;
	std::cout << "Enter the number of Cards you want in your Deck: ";
	int k;
	std::cin >> k;
	Deck deck(k, "Custom");

	do
	{
		char entry;
		std::cout << "Play/Continue(0);  Exit(1):  ";
		do
		{
			std::cin >> entry;
			if (entry == '1' || entry == '0') break;
			std::cout << "Wrong input, try again: ";
		} while (true);
		if (entry == '1')
		{
			std::cout << "All files have been saved; Exiting game . . .";
			break;
		}

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

		player.setCurrentPoints(0);
		char userEntry[20] = " ";
		do
		{
			if (strcmp(userEntry, "probability") != 0)
			{
				Card currentCard;
				currentCard = deck.draw();
				updatePlayerPoints(currentCard, deck, player);
				std::cout << currentCard << "  Your Total Current Points: " << player.getCurrentPoints() << std::endl << std::endl;

				if (player.getCurrentPoints() > 21)
				{
					hostWins(player);
					break;
				}
				if (player.getCurrentPoints() == 21)
				{
					std::cout << "BLACKJACK! ";
					playerWins(player);
					break;
				}
			}
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
				//
			}
			else if (strcmp(userEntry, "stand") == 0)
			{
				std::cout << std::endl << "Hosts cards:" << std::endl;
				int hostpoints = generateHostPoints(deck);
				std::cout << "Host's points: " << hostpoints << std::endl;
				if (hostpoints > 21)
				{
					playerWins(player);
					break;
				}
				if (hostpoints >= 17 && hostpoints <= 21)
				{
					if (hostpoints > player.getCurrentPoints()) hostWins(player);
					else playerWins(player);
					break;
				}
			}
			else if (strcmp(userEntry, "probability") == 0)
			{
				std::cout << "Probability for Blackjack(21points):  " << calculateProbability(deck, player) << std::endl;
			}
		} while (true);
	} while (true);
}

double calculateProbability(const Deck& deck, const Player& player)
{
	double totalRemainingCards = 0;
	double fittingCards = 0;

	for (int i = 0; i < deck.getK(); i++)
	{
		if (deck.getDeck()[i].getDrawed() == 0)
		{
			if (21 - player.getCurrentPoints() == deck.getDeck()[i].getPoints()) fittingCards++;
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
	//if(current.getValue(), "A")
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


