#include "Card.h"
#include <cstring>

Card::Card()
{
	this->drawed = 0;
	this->points = 0;
}

Card& Card::operator=(const Card& other)
{
	this->colour = other.colour;
	strcpy_s(this->value, strlen(other.value)+ 1, other.value);
	strcpy_s(this->serialKey, strlen(other.serialKey) + 1 ,other.serialKey);
	this->points = other.points;
	this->drawed = other.drawed;

	return *this;
}

bool Card::operator==(const CardColour& othercolour)
{
	return (this->colour == othercolour);
}

void Card::setColour(CardColour newColour)
{
	switch (newColour)
	{
		case 0:
		{
			this->colour = Spades;
			break;
		}
		case 1:
		{
			this->colour = Hearts;
			break;
		}
		case 2:
		{
			this->colour = Diamonds;
			break;
		}
		case 3:
		{
			this->colour = Clubs;
			break;
		}
		default:
		{
			//std::cout << "Wrong!";
			break;
		};
	}
}

void Card::setColour(int newColour)
{
	switch (newColour)
	{
	case 0:
	{
		this->colour = Spades;
		break;
	}
	case 1:
	{
		this->colour = Hearts;
		break;
	}
	case 2:
	{
		this->colour = Diamonds;
		break;
	}
	case 3:
	{
		this->colour = Clubs;
		break;
	}
	default:
	{
		//std::cout << "Wrong!";
		break;
	};
	}
}

void Card::setValue(const char* newValue)
{
	strcpy_s(this->value, strlen(newValue) + 1, newValue);
}



void Card::setSerialKey(char newSerialKey[15])
{
	strcpy_s(this->serialKey, strlen(newSerialKey)+1 , newSerialKey);
}

void Card::setDrawed(bool newDrawed)
{
	this->drawed = newDrawed;
}

void Card::setPoints(int newPoints)
{
	this->points = newPoints;
}


const CardColour Card::getColour() const
{
	return this->colour;
}

const char* Card::getValue() const
{
	return this->value;
}

const char* Card::getSerialKey() const
{
	return this->serialKey;
}

bool Card::getDrawed() const
{
	return this->drawed;
}

int Card::getPoints() const
{
	return this->points;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	out << card.value << " of ";
	switch (card.colour)
	{
		case 0:
		{
			out << "Spades";
			break;
		}
		case 1:
		{
			out << "Hearts";
			break;
		}
		case 2:
		{
			out << "Diamonds";
			break;
		}
		case 3:
		{
			out << "Clubs";
			break;
		}
		default:
		{
			//std::cout << "Wrong!";
			break;
		};
		}
	if (strcmp(card.getValue(), "A") == 0)
	{
		out<< "(11or1 points)";
	}
	else out << "(" << card.points <<" points)";

	return out;
}
