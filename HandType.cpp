#include "stdafx.h"
#include "HandType.h"
#include <algorithm>

using std::cout;
using std::endl;

bool compareCard(const Card* a, const Card* b)
{
	return a->rank < b->rank;
}

HandType handValue(std::vector<Card*>& hand)
{
	HandType hValue;
	hValue.name = "High card";
	hValue.value = 1;

	bool isRoyal = false;
	bool isFlush = false;
	bool isStraight = false;
	bool is4OfKind = false;
	bool has3OfKind = false;
	bool has2Pair = false;
	bool hasPair = false;
	bool isFullHouse = false;

	int countFlush = 0;
	int countStraight = 0;

	std::sort(hand.begin(), hand.end(), compareCard);

	for (int i = 0; i != hand.size(); ++i) {
		cout << "Hand [" << i << "] Contents: " << hand[i]->rank << " " << hand[i]->suit << endl;
	}

	for (int i = 0; i != hand.size() - 1; ++i) {
		if (hand[i]->suit == hand[i + 1]->suit) {
			countFlush++;
		}
		if (hand[i]->rank == hand[i + 1]->rank - 1) {
			countStraight++;
		}
	}

	bool four1 = ((hand[0]->rank == hand[1]->rank) && (hand[1]->rank == hand[2]->rank) && (hand[2]->rank == hand[3]->rank));
	bool four2 = ((hand[1]->rank == hand[2]->rank) && (hand[2]->rank == hand[3]->rank) && (hand[3]->rank == hand[4]->rank));

	is4OfKind = (four1 || four2);

	bool fh1 = ((hand[0]->rank == hand[1]->rank) && (hand[1]->rank == hand[2]->rank) && (hand[3]->rank == hand[4]->rank));
	bool fh2 = ((hand[0]->rank == hand[1]->rank) && (hand[2]->rank == hand[3]->rank) && (hand[3]->rank == hand[4]->rank));

	isFullHouse = (fh1 || fh2);

	bool t1 = ((hand[0]->rank == hand[1]->rank) && (hand[1]->rank == hand[2]->rank));
	bool t2 = ((hand[1]->rank == hand[2]->rank) && (hand[2]->rank == hand[3]->rank));
	bool t3 = ((hand[2]->rank == hand[3]->rank) && (hand[3]->rank == hand[4]->rank));

	has3OfKind = (t1 || t2 || t3);

	bool p1 = ((hand[0]->rank == hand[1]->rank) && (hand[2]->rank == hand[3]->rank));
	bool p2 = ((hand[0]->rank == hand[1]->rank) && (hand[3]->rank == hand[4]->rank));
	bool p3 = ((hand[1]->rank == hand[2]->rank) && (hand[3]->rank == hand[4]->rank));

	has2Pair = (p1 || p2 || p3);

	bool o1 = (hand[0]->rank == hand[1]->rank);
	bool o2 = (hand[1]->rank == hand[2]->rank);
	bool o3 = (hand[2]->rank == hand[3]->rank);
	bool o4 = (hand[3]->rank == hand[4]->rank);

	hasPair = (o1 || o2 || o3 || o4);

	if (hand[0]->rank >= 10)
		isRoyal = true;

	if (countFlush == 4)
		isFlush = true;

	if (countStraight == 4)
		isStraight = true;

	if (isStraight && isFlush && isRoyal) {
		hValue.name = "Royal Flush";
		hValue.value = 10;
	}
	else if (isStraight && isFlush) {
		hValue.name = "Straight Flush";
		hValue.value = 9;
	}
	else if (is4OfKind) {
		hValue.name = "Four of a kind";
		hValue.value = 8;
	}
	else if (isFullHouse) {
		hValue.name = "Full House";
		hValue.value = 7;
	}
	else if (isFlush) {
		hValue.name = "Flush";
		hValue.value = 6;
	}
	else if (isStraight) {
		hValue.name = "Straight";
		hValue.value = 5;
	}
	else if (has3OfKind) {
		hValue.name = "Three of a kind";
		hValue.value = 4;
	}
	else if (has2Pair) {
		hValue.name = "Two pair";
		hValue.value = 3;
	}
	else if (hasPair) {
		hValue.name = "Pair";
		hValue.value = 2;
	}

	cout << "Return hValue name: " << hValue.name << " hValue value: " << hValue.value << endl;

	return hValue;
}

HandType smallHand(std::vector<Card*>& hand)
{
	HandType hValue;
	hValue.name = "High card";
	hValue.value = 1;
	return hValue;
}

void findBestHand(Hand& hand)
{
	std::vector<std::vector<Card*>> hands = hand.availableOptions();
	std::vector<Card*> bHand = hand.bestOption();
	HandType handT;
	HandType bestH;

	
	for (int i = 0; i != hands.size(); ++i) { //for each hand option in available hands **** NEED CASE FOR findBestHand on hole cards only ****
		if (hands.size() == 1) {
			cout << "Only hand is best hand:" << endl;
			bestH = smallHand(bHand); //current best hand type
		}
		else {
			cout << "New hand:" << endl;
			handT = handValue(hands[i]); //check hand option type
			cout << "Current best hand:" << endl;
			bestH = handValue(bHand); //current best hand type

			cout << "Check hand: " << i + 1 << " with type: " << handT.name << " Against best: " << bestH.name << endl;

			if (handT.value > bestH.value) {
				hand.setHand(hands[i]); //Set the best hand to equal the new best
				cout << "New best Hand set, Hand option: " << i + 1 << " With value: " << handT.name << endl;
			}
		}
	}
}