#pragma once
#include "stdafx.h"
//Defines a card
//Contains the cards available
//Contains the unknown cards

struct Card
{
	int rank;
	std::string suit;
};

class Deck
{
private:
	std::vector<Card> decklist; //complete decklist
	std::list<Card*> deck; //cards in deck pointer to decklist
public:
	Deck(); //initialise the decklist, create a new deck array of pointers to decklist
	int sizeDecklist() const; //number of cards in decklist (52 cards)
	int sizeDeck() const; //number of cards left in the deck
	void printDecklist() const; //display all cards in the game (52 cards)		
	void printDeck() const; //display cards left in the deck
	void burnCard(Card& burn); //destroy deck pointer to decklist (i.e. card is played)
	const std::list<Card*>& deckCards() const { return deck; } //return the deck
};