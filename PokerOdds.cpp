// PokerOdds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"
#include "Hand.h"
#include "Odds.h"
#include "HandType.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	Deck deck;
	Hand hand;
	//Odds handOdds;

	//deck.printDecklist();
	//cout << "Decklist contains: " << deck.sizeDecklist() << " cards" << endl;

	Card burn;
	int rank;
	std::string suit;
	
	for (int i = 0; i != 2; ++i) {
		//cout << "Enter hole card " << i + 1 << " in format rank suit: ";
		//cin >> rank >> suit; //fix scenario where rank rank suit

		rank = i + 3;
		suit = "Hearts";

		burn.rank = rank;
		burn.suit = suit;

		bool cardSet = hand.setCard(deck, burn);

		cout << "Card " << i << " is: " << rank << ", " << suit << endl;

		if (cardSet)
			continue;
		else
			i--;
	}
	
	for (int i = 0; i != 3; ++i) {
		//cout << "Enter flop card " << i + 1 << " in format rank suit: ";
		//cin >> rank >> suit;

		rank = i + 6;
		suit = "Spades";

		burn.rank = rank;
		burn.suit = suit;

		bool cardSet = hand.setCard(deck, burn);

		cout << "Card " << i + 2 << " is: " << rank << ", " << suit << endl;

		if (cardSet)
			continue;
		else
			i--;
	}
	///*
	for (int i = 0; i != 1; ++i) {
		//cout << "Enter turn card in format rank suit: ";
		//cin >> rank >> suit;

		rank = i + 10;
		suit = "Clubs";

		burn.rank = rank;
		burn.suit = suit;

		bool cardSet = hand.setCard(deck, burn);

		cout << "Card " << i + 5 << " is: " << rank << ", " << suit << endl;

		if (cardSet)
			continue;
		else
			i--;
	}
	/*
	for (int i = 0; i != 1; ++i) {
		//cout << "Enter river card in format rank suit: ";
		//cin >> rank >> suit;

		rank = i + 12;
		suit = "Clubs";

		burn.rank = rank;
		burn.suit = suit;

		bool cardSet = hand.setCard(deck, burn);

		cout << "Card " << i + 5 << " is: " << rank << ", " << suit << endl;

		if (cardSet)
			continue;
		else
			i--;
	}
	*/

	//deck.printDeck();
	//cout << "Deck contains: " << deck.sizeDeck() << " cards" << endl;

	cout << "Hole cards: " << endl;
	hand.printHole();
	cout << "Community cards: " << endl;
	hand.printCommunity();
	cout << "Available cards: " << endl;
	hand.printAvailable();
	cout << "Hands available: " << endl;
	hand.printHands();

	findBestHand(hand);

	cout << "Best hand: " << endl;
	hand.printBest();

	return 0;
}