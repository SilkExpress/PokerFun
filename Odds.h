#pragma once
#include "stdafx.h"
#include "Hand.h"
#include "HandType.h"


/*
class Odds: public Hand
{
private:
	int odds;
	HandType bestValue;
public:
	void findOdds(Deck& deck, Hand& hand); //find the odds of hand winning
	void findBest(std::vector<std::vector<Card*>>& options); //find the best hand from hand options
	//Combination handValue(std::vector<Card*>& hand); //find the type of hand
	//const Combination& handType() const { return bestValue; } //return the hand type for the best hand
};

*/

void findOdds(Deck& deck, Hand& hand); //find the odds of hand winning
void findBest(std::vector<std::vector<Card*>>& options); //find the best hand from hand options