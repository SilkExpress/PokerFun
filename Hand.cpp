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
	
	//check card is in the deck
	for (std::list<Card*>::iterator iter = unknownCards.begin(); iter != unknownCards.end(); ++iter) {
		if ((*iter)->rank == dp->rank) {
			if ((*iter)->suit == dp->suit) {
				inDeck = true;
			}
		}
	}

	if (inDeck == true) { //Card found and set
		deck.burnCard(card); //card is moved from the deck, delete the pointer

		availableCards.push_back(dp); //add card to the container of available cards
		count++;

		if (count > 5) {
			availableHands.clear();
			handOptions(); //find the available hand options
		}
		else {
			bestHand.push_back(dp);

			if (count == 5) {
				availableHands.push_back(bestHand);
			}
		}

		return true;
	}
	else { //Card not found, re-enter a card
		cout << "Card not found in the deck" << endl;
		return false;
	}
}

void Hand::findUnique(int tIndex, int index)
{
	if (tIndex == 0) {
		std::vector<Card*> temp;

		cout << endl << "Push these tempHand cards into availableHands: " << endl;
		for (int j = 5; j > 0; j--) {
			cout << tempHand[j]->rank << " " << tempHand[j]->suit << " ";

			Card* dp = new Card;
			dp->rank = tempHand[j]->rank;
			dp->suit = tempHand[j]->suit;

			temp.push_back(dp);
		}
		cout << endl;

		availableHands.push_back(temp);
		
		cout << endl << "availableHands: " << endl;
		for (int x = 0; x != availableHands.size(); ++x) { //hands
			for (int y = 0; y != availableHands[x].size(); ++y) { //cards in hand
				cout << availableHands[x][y]->rank << " " << availableHands[x][y]->suit << " ";
			}
			cout << endl;
		}
	}
	else {
		for (int i = index; i < availableCards.size(); i++) {
			tempHand[tIndex]->rank = availableCards[i]->rank;
			tempHand[tIndex]->suit = availableCards[i]->suit;
			findUnique(tIndex - 1, i + 1);
		}
	}
}

void Hand::handOptions() //find all possible unique hand combinations (both hole cards are always included)
{
	for (int i = 0; i != availableCards.size(); ++i) {
		Card* dp = new Card;
		dp->rank = i + 2;
		dp->suit = "Hearts";

		tempHand.push_back(dp);

		tempHand[i]->rank = availableCards[i]->rank;
		tempHand[i]->suit = availableCards[i]->suit;

		cout << "availableCards " << i << " at handOptions(): " << availableCards[i]->rank << ", " << availableCards[i]->suit << endl;
	}

	findUnique(5, 0);
}

void Hand::setHand(std::vector<Card*>& hand)
{
	for (int i = 0; i != bestHand.size(); ++i) {
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
		cout << "Only one hand available" << endl;
		return;
	}
	for (int i = 0; i != availableHands.size(); ++i) {
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