#pragma once
#include "stdafx.h"
#include "Hand.h"
//Finds the type of hand for all available hand options 
//and sets bestHand to equal the highest value option

struct HandType
{
	int value;
	std::string name;	
	int quad;
	int triple;
	int pair;
	int lowPair;
	int highCard;
	int highCard2;
	int highCard3;
	int highCard4;
	int highCard5;
};

HandType handValue(std::vector<Card*>& hand); //find the type of a hand
void findBestHand(Hand& hand); //find the best hand from all options
bool isHigher(HandType bestH, HandType newH); //compares 2 hands of the same type to assess which is higher