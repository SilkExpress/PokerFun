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

		if (count > 5) {
			availableHands.clear();
			handOptions();
		}
		else {
			bestHand.push_back(dp);

			if (count == 5) {
				availableHands.push_back(bestHand);
			}
		}
		return true;
	}
	else {
		cout << "Card not found in the deck" << endl;
		return false;
	}
}

void Hand::options(int hIndex, int index)
{
	cout << "Call to options() " << "hIndex: " << hIndex << ", index: " << index << endl;

	if (hIndex == 0)
	{
		std::vector<Card*> temp;
		temp.clear();

		cout << "Push into availableHands these tempHand Cards: " << endl;

		for (int j = 5; j > 0; j--) {
			cout << tempHand[j]->rank << " " << tempHand[j]->suit << " ";
			temp.push_back(tempHand[j]);
			cout << "here" << endl;
			availableHands.push_back(tempHand);
			cout << availableHands.size() << endl;
			cout << availableHands[0][j]->rank << endl;
			availableHands[availableHands.size()].push_back(tempHand[j]);
			cout << "or here?" << endl;
		}
		cout << endl;

		//availableHands.push_back(temp);
		
		cout << "availableHands: " << endl;
		for (int x = 0; x != availableHands.size(); ++x) { //hands
			for (int y = 0; y != availableHands[x].size(); ++y) { //cards in hand
				cout << availableHands[x][y]->rank << " " << availableHands[x][y]->suit << " ";
			}
			cout << endl;
		}
	}
	else {
		for (int i = index; i < availableCards.size(); i++)
		{
			tempHand[hIndex]->rank = availableCards[i]->rank;
			tempHand[hIndex]->suit = availableCards[i]->suit;
			options(hIndex - 1, i + 1);
		}
	}
}

void Hand::handOptions() //find all possible unique hand combinations (both hole cards are always included)
{
	cout << "Call to handOptions()" << endl;

	for (int i = 0; i != availableCards.size(); ++i) {

		Card* dp = new Card;
		dp->rank = i + 2;
		dp->suit = "Hearts";

		tempHand.push_back(dp);

		tempHand[i]->rank = availableCards[i]->rank;
		tempHand[i]->suit = availableCards[i]->suit;

		cout << "availableCards " << i << " at handOptions(): " << availableCards[i]->rank << ", " << availableCards[i]->suit << endl;
	}

	options(5, 0);
}

/*
void Hand::options( int hIndex, int index)
{
	cout << "Call to options()" << endl;

	if (hIndex == 0)
	{
		for (int j = 5; j>0; j--)
			std::cout << tempHand[j].rank << " " << tempHand[j].suit << " ";
		std::cout << std::endl;

		//availableHands.push_back(bestHand);

		for (int x = 0; x != tempHand.size() - 1; ++x) {
			//cout << "available hands size: " <<availableHands.size() << endl;
			//cout << "does it get here? " << x << endl;
			availableHands[availableHands.size() - 1][x]->rank = tempHand[x].rank;
			
			//cout << "and here? " << x << endl;
			availableHands[availableHands.size() - 1][x]->suit = tempHand[x].suit;
			//cout << "step complete times: " << x << endl;
		}
		
		for (int i = 0; i != availableCards.size(); ++i) {
			//cout << "availableCards " << i << " at options() if loop: " << availableCards[i]->rank << ", " << availableCards[i]->suit << endl;
		}
	}
	else 
		//for (int z = 0; z != tempHand.size(); ++z) {
		//	cout << "tempHand " << z << " at options() else loop: " << tempHand[z].rank << ", " << tempHand[z].suit << endl;
		//}
		for (int i = index; i < availableCards.size(); i++)
		{
			for (int j = 0; j != availableCards.size(); ++j) {
				//cout << "availableCards " << i << " at options() else loop: " << availableCards[i]->rank << ", " << availableCards[i]->suit << endl;
			}
			
			//cout << "check" << endl;
			//cout << tempHand[i].rank << endl;
			//cout << "try to set" << endl;
			tempHand[hIndex].rank = availableCards[i]->rank;
			tempHand[hIndex].suit = availableCards[i]->suit;
			//cout << "next options" << endl;
			options(hIndex - 1, i + 1);
		}
}

void Hand::handOptions() //find all possible unique hand combinations (both hole cards are always included)
{
	cout << "Call to handOptions()" << endl;

	if (availableHands.size() == 1) {
		for (int i = 0; i < availableCards.size(); i++)
		{
			tempHand.push_back(Card());
			
			tempHand[i].rank = availableCards[i]->rank;	
			tempHand[i].suit = availableCards[i]->suit;
		}
	}
	else {
		availableHands.clear();	
	}

	for (int i = 0; i != availableCards.size(); ++i) {
		cout << "availableCards " << i << " at handOptions(): " << availableCards[i]->rank << ", " << availableCards[i]->suit << endl;
	}

	options(5, 0);
}
*/

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