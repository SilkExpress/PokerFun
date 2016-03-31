#include "stdafx.h"
#include "Hand.h"
#include <algorithm>

using std::cout;
using std::endl;

bool Hand::setCard(Deck& deck, Card& card)
{
	Card* dp = new Card;
	dp->rank = card.rank;
	dp->suit = card.suit;

	bool inDeck = false;

	std::list<Card*> unknownCards = deck.deckCards();

	for (std::list<Card*>::iterator iter = unknownCards.begin(); iter != unknownCards.end(); ++iter) {
		if ((*iter)->rank == dp->rank)
		{
			if ((*iter)->suit == dp->suit)
			{
				inDeck = true;
			}
		}
	}

	if (inDeck == true) {

		deck.burnCard(card); //card is no longer in the deck, delete the pointer

		availableCards.push_back(dp);
		count++;

		if (count > 5)
			handOptions();
		else
			bestHand.push_back(dp);

		return true;
	}
	else {
		cout << "Card not found in the deck" << endl;
		return false;
	}
}

void Hand::handOptions() //find all possible unique hand combinations (both hole cards are always included)
{
	std::vector<Card*> altHand(5);
	Card* dp = new Card;

	for (int i = 0; i != 5; ++i) {
		altHand[i] = availableCards[i];
	}

	if (count == 6) {

		availableHands.push_back(altHand); //1,2,3,4,5

		altHand[4] = availableCards[5];
		availableHands.push_back(altHand); //1,2,3,4,6

		altHand[2] = availableCards[4];
		availableHands.push_back(altHand); //1,2,5,4,6
	}
	else if (count == 7) {

		altHand[2] = availableCards[4];
		altHand[3] = availableCards[6];
		altHand[4] = availableCards[5];
		availableHands.push_back(altHand); //1,2,5,7,6

		altHand[2] = availableCards[2];
		availableHands.push_back(altHand); //1,2,3,7,6

		altHand[2] = availableCards[3];
		availableHands.push_back(altHand); //1,2,4,7,6

		altHand[4] = availableCards[4];
		availableHands.push_back(altHand); //1,2,4,7,5

		altHand[4] = availableCards[2];
		availableHands.push_back(altHand); //1,2,4,7,3

		altHand[2] = availableCards[4];
		availableHands.push_back(altHand); //1,2,5,7,3

		altHand[3] = availableCards[5];
		availableHands.push_back(altHand); //1,2,5,6,3
	}
}

void Hand::setHand(std::vector<Card*>& hand)
{
	for (int i = 0; i != bestHand.size(); ++i)
	{
		bestHand[i]->rank = hand[i]->rank;
		bestHand[i]->suit = hand[i]->suit;
	}
}

void Hand::printAvailable() const
{
	for (std::vector<Card*>::const_iterator iter = availableCards.begin(); iter != availableCards.end(); ++iter) {
		cout << (*iter)->rank << " " << (*iter)->suit << endl;
	}
}

void Hand::printHole() const
{
	int end = count;
	if (count > 2)
		end = 2;

	for (int i = 0; i != end; ++i) {
		cout << availableCards[i]->rank << " " << availableCards[i]->suit << endl;
	}
}

void Hand::printCommunity() const
{
	int end = 0;
	int start = 0;
	if (count > 2) {
		start = 2;
		end = count;
	}
	else
		cout << "There are no community cards" << endl;

	for (int i = start; i != end; ++i) {
		cout << availableCards[i]->rank << " " << availableCards[i]->suit << endl;
	}
}

void Hand::printHands() const
{
	if (availableHands.size() == 0) {
		cout << "Only hand available" << endl;
		return;
	}
	for (int i = 0; i != availableHands.size(); ++i)
	{
		cout << "Hand option: " << i + 1 << endl;
		for (int j = 0; j != availableHands[i].size(); ++j) {
			cout << availableHands[i][j]->rank << " " << availableHands[i][j]->suit << endl;
		}
	}
}

void Hand::printBest() const
{
	for (std::vector<Card*>::const_iterator iter = bestHand.begin(); iter != bestHand.end(); ++iter) {
		cout << (*iter)->rank << " " << (*iter)->suit << endl;
	}
}