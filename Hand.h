#pragma once
#include "stdafx.h"
#include "Deck.h"
//Tracks hole and community cards
//Finds all possible hand combinations

class Hand
{
private:
	std::vector<Card*> availableCards; //cards available to construct a hand
	std::vector<std::vector<Card*>> availableHands; //available hand options
	std::vector<Card*> bestHand; //the best hand option
	int count; //count of cards known
public:
	bool setCard(Deck& deck, Card& card); //card is played (enter into the availableCards)
	void handOptions(); //find the available hands (up to 5 cards) using cards from hole and community
	void setHand(std::vector<Card*>& hand); //set the bestHand
	void printAvailable() const; //print available cards
	void printHole() const; //print hole cards
	void printCommunity() const; //print community cards	
	void printHands() const; //print the available hand options
	void printBest() const; //print the best hand	
	std::vector<std::vector<Card*>>& availableOptions() { return availableHands; } //return the available hand options
	std::vector<Card*>& bestOption() { return bestHand; } //return the available hand options
};