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
		cout << "Hand[" << i << "] Contents: " << hand[i]->rank << " " << hand[i]->suit << endl;
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
		cout << hValue.name << " (" << hValue.value << ")" << endl;
	}
	else if (isStraight && isFlush) {
		hValue.name = "Straight Flush";
		hValue.value = 9;
		hValue.highCard = hand[4]->rank;
		cout << hValue.name << " (" << hValue.value << "): " << hValue.highCard << " high" << endl;
	}
	else if (is4OfKind) {
		hValue.name = "Four of a kind";
		hValue.value = 8; 

		if (four1) {
			hValue.quad = hand[0]->rank;
			hValue.highCard = hand[4]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "quad " << hValue.quad << "s, " << hValue.highCard << " kicker" << endl;
		}
		else {
			hValue.quad = hand[4]->rank;
			hValue.highCard = hand[0]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "quad " << hValue.quad << "s, " << hValue.highCard << " kicker" << endl;
		}
	}
	else if (isFullHouse) {
		hValue.name = "Full House";
		hValue.value = 7;

		if (fh1) {
			hValue.triple = hand[0]->rank;
			hValue.pair = hand[4]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << hValue.triple << "s full of " << hValue.pair << "s" << endl;
		}
		else {
			hValue.triple = hand[4]->rank;
			hValue.pair = hand[0]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << hValue.triple << "s full of " << hValue.pair << "s" << endl;
		}
	}
	else if (isFlush) {
		hValue.name = "Flush";
		hValue.value = 6;
		hValue.highCard = hand[4]->rank;
		hValue.highCard2 = hand[3]->rank;
		hValue.highCard3 = hand[2]->rank;
		hValue.highCard4 = hand[1]->rank;
		hValue.highCard5 = hand[0]->rank;
		cout << hValue.name << " (" << hValue.value << "): " << hValue.highCard << ", " << hValue.highCard2 << ", " << hValue.highCard3 << ", " << hValue.highCard4 << ", " << hValue.highCard5 << endl;
	}
	else if (isStraight) {
		hValue.name = "Straight";
		hValue.value = 5;
		hValue.highCard = hand[4]->rank;
		cout << hValue.name << " (" << hValue.value << "): " << hValue.highCard << endl;
	}
	else if (has3OfKind) {
		hValue.name = "Three of a kind";
		hValue.value = 4;

		if (t1) {
			hValue.triple = hand[0]->rank;
			hValue.highCard = hand[4]->rank;
			hValue.highCard2 = hand[3]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "triple " << hValue.triple << "s, side card 1: " << hValue.highCard << ", side card 2: " << hValue.highCard2 << endl;
		}
		else if (t2) {
			hValue.triple = hand[1]->rank;
			hValue.highCard = hand[4]->rank;
			hValue.highCard2 = hand[0]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "triple " << hValue.triple << "s, side card 1: " << hValue.highCard << ", side card 2: " << hValue.highCard2 << endl;
		}
		else {
			hValue.triple = hand[2]->rank;
			hValue.highCard = hand[1]->rank;
			hValue.highCard2 = hand[0]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "triple " << hValue.triple << "s, side card 1: " << hValue.highCard << ", side card 2: " << hValue.highCard2 << endl;
		}
	}
	else if (has2Pair) {
		hValue.name = "Two pair";
		hValue.value = 3;

		if (hand[1]->rank > hand[3]->rank) {
			hValue.pair = hand[1]->rank;
			hValue.lowPair = hand[3]->rank;
		}
		else {
			hValue.pair = hand[3]->rank;
			hValue.lowPair = hand[1]->rank;
		}

		if (p1) {
			hValue.highCard = hand[4]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "high pair " << hValue.pair << "s, low pair: " << hValue.lowPair << "s, side card: " << hValue.highCard << endl;
		}
		else if (p2) {
			hValue.highCard = hand[2]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "high pair " << hValue.pair << "s, low pair: " << hValue.lowPair << "s, side card: " << hValue.highCard << endl;
		}
		else {
			hValue.highCard = hand[0]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "high pair " << hValue.pair << "s, low pair: " << hValue.lowPair << "s, side card: " << hValue.highCard << endl;
		}
	}
	else if (hasPair) {
		hValue.name = "Pair";
		hValue.value = 2;

		if (o1) {
			hValue.pair = hand[0]->rank;
			hValue.highCard = hand[4]->rank;
			hValue.highCard2 = hand[3]->rank;
			hValue.highCard3 = hand[2]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "pair " << hValue.pair << "s, side card 1: " << hValue.highCard << ", side card 2: " << hValue.highCard2 << ", side card 3: " << hValue.highCard3 << endl;
		}
		else if (o2) {
			hValue.pair = hand[1]->rank;
			hValue.highCard = hand[4]->rank;
			hValue.highCard2 = hand[3]->rank;
			hValue.highCard3 = hand[0]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "pair " << hValue.pair << "s, side card 1: " << hValue.highCard << ", side card 2: " << hValue.highCard2 << ", side card 3: " << hValue.highCard3 << endl;
		}
		else if (o3) {
			hValue.pair = hand[2]->rank;
			hValue.highCard = hand[4]->rank;
			hValue.highCard2 = hand[1]->rank;
			hValue.highCard3 = hand[0]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "pair " << hValue.pair << "s, side card 1: " << hValue.highCard << ", side card 2: " << hValue.highCard2 << ", side card 3: " << hValue.highCard3 << endl;
		}
		else {
			hValue.pair = hand[3]->rank;
			hValue.highCard = hand[2]->rank;
			hValue.highCard2 = hand[1]->rank;
			hValue.highCard3 = hand[0]->rank;
			cout << hValue.name << " (" << hValue.value << "): " << "pair " << hValue.pair << "s, side card 1: " << hValue.highCard << ", side card 2: " << hValue.highCard2 << ", side card 3: " << hValue.highCard3 << endl;
		}
	}
	return hValue;
}

bool isHigher(HandType bestH, HandType newH) {
	if (newH.value == 9) { //straight flush
		if (newH.highCard > bestH.highCard)
			return true;
		else
			return false;
	}
	else if (newH.value == 8) { //4 of a kind
		if (newH.quad > bestH.quad)
			return true;
		else if ((newH.quad == bestH.quad) && (newH.highCard > bestH.highCard)) //same quad, check the high card
			return true;
		else
			return false;
	}
	else if (newH.value == 7) { //fullhouse
		if (newH.triple > bestH.triple)
			return true;
		else if ((newH.triple == bestH.triple) && (newH.pair > bestH.pair)) //same triple, check the pair
			return true;
		else
			return false;
	}
	else if (newH.value == 6) { //flush
		if (newH.highCard > bestH.highCard)
			return true;
		else if (newH.highCard < bestH.highCard)
			return false;
		else if (newH.highCard2 > bestH.highCard2) //same high card 1, check high card 2
			return true;
		else if (newH.highCard2 < bestH.highCard2)
			return true;
		else if (newH.highCard3 > bestH.highCard3) //same high card 2, check high card 3
			return true;
		else if (newH.highCard3 < bestH.highCard3)
			return true;
		else if (newH.highCard4 > bestH.highCard4) //same high card 3, check high card 4
			return true;
		else if (newH.highCard4 < bestH.highCard4)
			return true;
		else if (newH.highCard5 > bestH.highCard5) //same high card 4, check high card 5
			return true;
		else
			return false;
	}
	else if (newH.value == 5) { //straight
		if (newH.highCard > bestH.highCard)
			return true;
		else
			return false;
	}
	else if (newH.value == 4) { //3 of a kind
		if (newH.triple > bestH.triple)
			return true;
		else if (newH.triple < bestH.triple)
			return false;
		else if (newH.highCard > bestH.highCard) //same triple, check high card 1
			return true;
		else if (newH.highCard < bestH.highCard)
			return false;
		else if (newH.highCard2 > bestH.highCard2) //same high card 1, check high card 2
			return true;
		else
			return false;
	}
	else if (newH.value == 3) { //2 pair
		if (newH.pair > bestH.pair)
			return true;
		else if (newH.pair < bestH.pair)
			return false;
		else if (newH.lowPair > bestH.lowPair) //same high pair, check low pair
			return true;
		else if (newH.lowPair < bestH.lowPair)
			return false;
		else if (newH.highCard > bestH.highCard) //same low pair, check high card
			return true;
		else
			return false;
	}
	else if (newH.value == 2) { //pair
		if (newH.pair > bestH.pair)
			return true;
		else if (newH.pair < bestH.pair)
			return false;
		else if (newH.highCard > bestH.highCard) //same pair, check high card 1
			return true;
		else if (newH.highCard < bestH.highCard)
			return false;
		else if (newH.highCard2 > bestH.highCard2) //same high card 1, check high card 2
			return true;
		else if (newH.highCard2 < bestH.highCard2)
			return false;
		else if (newH.highCard3 > bestH.highCard3) //same high card 2, check high card 3
			return true;
		else
			return false;
	}
	else if (newH.value == 1) { //high card
		if (newH.highCard > bestH.highCard)
			return true;
		else if (newH.highCard < bestH.highCard)
			return false;
		else if (newH.highCard2 > bestH.highCard2) //same high card 1, check high card 2
			return true;
		else if (newH.highCard2 < bestH.highCard2)
			return true;
		else if (newH.highCard3 > bestH.highCard3) //same high card 2, check high card 3
			return true;
		else if (newH.highCard3 < bestH.highCard3)
			return true;
		else if (newH.highCard4 > bestH.highCard4) //same high card 3, check high card 4
			return true;
		else if (newH.highCard4 < bestH.highCard4)
			return true;
		else if (newH.highCard5 > bestH.highCard5) //same high card 4, check high card 5
			return true;
		else
			return false;
	}
}

void findBestHand(Hand& hand)
{
	std::vector<std::vector<Card*>> hands = hand.availableOptions();
	std::vector<Card*> bHand = hand.bestOption();
	HandType handT;
	HandType bestH;

	if (hands.size() == 0) {
		cout << "Only hand is best hand:" << endl;
		bool o1 = (bHand[0]->rank == bHand[1]->rank);

		if (o1) {
			bestH.name = "Pair";
			bestH.value = 2;
		}
		else {
			bestH.name = "High Card";
			bestH.value = 1;
		}
		cout << "Best hand type: " << bestH.name << endl;
	}
	
	for (int i = 0; i != hands.size(); ++i) { 
		if (hands.size() == 1) {
			cout << "Only hand is best hand:" << endl;
			bestH = handValue(bHand); //current best hand type
			cout << "Best hand type: " << bestH.name << endl;
		}
		else {
			cout << "Hand " << i + 1 << ":" << endl;
			handT = handValue(hands[i]); //check hand option type

			cout << "Check hand: " << i + 1 << " with type: " << handT.name << ", against best: " << bestH.name << endl;

			if (handT.value > bestH.value) {
				cout << "Current best hand:" << endl;
				bestH = handValue(bHand); //current best hand type

				hand.setHand(hands[i]); //Set the best hand to equal the new best
				cout << "New best hand set, hand option: " << i + 1 << ", with type: " << handT.name << endl;

				cout << "Best hand:" << endl;
				bestH = handValue(bHand); //new best hand type
			}
			else if (handT.value == bestH.value) {
				if (isHigher(bestH, handT) == true) {
					cout << "Current best hand:" << endl;
					bestH = handValue(bHand); //current best hand type

					hand.setHand(hands[i]); //Set the best hand to equal the new best
					cout << "New best hand set, hand option: " << i + 1 << ", with type: " << handT.name << endl;

					cout << "Best hand:" << endl;
					bestH = handValue(bHand); //new best hand type
				}
				else
					cout << "Hand option: " << i + 1 << " is equal or lower value than the current best hand" << endl;
			}
			else
				cout << "Hand option: " << i + 1 << " is equal or lower value than the current best hand" << endl;
		}
	}
}