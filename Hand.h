#pragma once
#include "stdafx.h"
#include "Deck.h"
//Keeps track of the cards played, saving them into appropriate containers
//Creates container to hold all possible unique hand combinations
//Allows printing of the known cards

class Hand
{
private:
	std::vector<Card*> availableCards; //cards available to construct a hand
	std::vector<std::vector<Card*>> availableHands; //available hand options
	std::vector<Card*> tempHand; //temporary container for finding the available hand options
	std::vector<Card*> bestHand; //the best hand option
	int count; //count of known cards e.g. hole, flop, turn and river cards (up to 7 count)
public:
	bool setCard(Deck& deck, Card& card); //card is played (enter into the availableCards)
	void handOptions(); //find the available hands (up to 5 cards) using cards from hole and community
	void findUnique(int tIndex, int index); //recursive function to iterate through all combinations (called through handOPtions())
	void setHand(std::vector<Card*>& hand); //set the bestHand
	void printAvailable() const; //print available cards
	void printHole() const; //print hole cards
	void printCommunity() const; //print community cards	
	void printHands() const; //print the available hand options
	void printBest() const; //print the best hand	
	std::vector<std::vector<Card*>>& availableOptions() { return availableHands; } //return the available hand options
	std::vector<Card*>& bestOption() { return bestHand; } //return the current best hand option
};