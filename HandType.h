#pragma once
#include "stdafx.h"
#include "Hand.h"

struct HandType
{
	int value;
	std::string name;
};


HandType handValue(std::vector<Card*>& hand);
void findBestHand(Hand& hand);

/*
HandType handValue(std::vector<Card*>& hand);
void findBestHand(Hand& hand);
*/