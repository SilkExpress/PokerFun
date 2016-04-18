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
using std::getline;
using std::string;

int main()
{
	Deck deck;
	Hand hand;
	Card burn;

	int rank;
	string suit;

	int numPlayers;

	int input;
	char inChar;

	cout << "Please entering the number of players: " << endl;
	cin >> inChar;
	numPlayers = inChar - '0';
	cout << "Number of starting players: " << numPlayers << endl;

	while (true) {
		cout << "Please choose from the following options: " << endl;
		cout << "1. Enter hole cards." << endl << "2. Randomise hole cards." << endl << "3. Print decklist." << endl << "4. Print deck." << endl;

		cin >> inChar;
		input = inChar - '0';
		switch (input) {
		case 1:
			for (int i = 0; i != 2; ++i) {
				cout << "Enter hole card " << i + 1 << ": ";
				cin >> rank >> suit; //fix scenario where rank rank suit

				burn.rank = rank;
				burn.suit = suit;

				//cout << "Card " << i << " is: " << rank << " " << suit << endl;

				bool cardSet = hand.setCard(deck, burn);

				if (cardSet)
					continue;
				else //try again
					i--;
			}
			break;
		case 2:
			for (int i = 0; i != 2; ++i) {
				cout << "Randomizing hole card " << i + 1 << ": ";

				//randomize function
				burn.rank = rank;
				burn.suit = suit;

				cout << "Card " << i << " is: " << rank << " " << suit << endl;

				bool cardSet = hand.setCard(deck, burn);

				if (cardSet)
					continue;
				else //try again
					i--;
			}
			break;
		case 3:
			deck.printDecklist();
			cout << "Decklist contains: " << deck.sizeDecklist() << " cards" << endl;
			continue;
		case 4:
			deck.printDeck();
			cout << "Deck contains: " << deck.sizeDeck() << " cards" << endl;
			continue;
		default:
			cout << "Invalid input. Please enter a number representing one of the following options:" << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Please choose from the following options: " << endl;
		cout << "1. Enter flop cards." << endl << "2. Randomise flop cards." << endl << "3. Print decklist." << endl << "4. Print deck." << endl << "5. Display hole cards. " << endl;
		cout << "6. Display community cards." << endl << "7. Display all known cards." << endl << "8. Display all available hand options." << endl << "9. Display the best available hand." << endl;
		cout << "10. Find odds of hand winning now. " << endl << "11. Find odds of hand winning on flop." << endl;

		cin >> inChar;
		input = inChar - '0';
		switch (input) {
		case 1:
			for (int i = 0; i != 3; ++i) {
				cout << "Enter flop card " << i + 1 << ": ";
				cin >> rank >> suit;

				burn.rank = rank;
				burn.suit = suit;

				//cout << "Card " << i + 2 << " is: " << rank << " " << suit << endl;

				bool cardSet = hand.setCard(deck, burn);

				if (cardSet)
					continue;
				else //try again
					i--;
			}
			break;
		case 2:
			break;
		case 3:
			deck.printDecklist();
			cout << "Decklist contains: " << deck.sizeDecklist() << " cards" << endl;
			continue;
		case 4:
			deck.printDeck();
			cout << "Deck contains: " << deck.sizeDeck() << " cards" << endl;
			continue;
		case 5:
			cout << "Hole cards: " << endl;
			hand.printHole();
			continue;
		case 6:
			cout << "Community cards: " << endl;
			hand.printCommunity();
			continue;
		case 7:
			cout << "Available cards: " << endl;
			hand.printAvailable();
			continue;
		case 8:
			cout << "Hands available: " << endl;
			hand.printHands();
			continue;
		case 9:
			findBestHand(hand);
			cout << "Best hand: " << endl;
			hand.printBest();
			continue;
		case 10:
			//odds now
			break;
		case 11:
			//odds after flop
			break;
		default:
			cout << "Invalid input. Please enter a number representing one of the following options:" << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Please choose from the following options: " << endl;
		cout << "1. Enter turn card." << endl << "2. Randomise turn card." << endl << "3. Print decklist." << endl << "4. Print deck." << endl << "5. Display hole cards. " << endl;
		cout << "6. Display community cards." << endl << "7. Display all known cards." << endl << "8. Display all available hand options." << endl << "9. Display the best available hand." << endl;
		cout << "10. Find odds of hand winning now. " << endl << "11. Find odds of hand winning on flop." << endl;

		cin >> inChar;
		input = inChar - '0';
		switch (input) {
		case 1:
			for (int i = 0; i != 1; ++i) {
				cout << "Enter turn card 1: ";
				cin >> rank >> suit;

				burn.rank = rank;
				burn.suit = suit;

				//cout << "Card " << i + 5 << " is: " << rank << " " << suit << endl;

				bool cardSet = hand.setCard(deck, burn);

				if (cardSet)
					continue;
				else //try again
					i--;
			}
			break;
		case 2:
			break;
		case 3:
			deck.printDecklist();
			cout << "Decklist contains: " << deck.sizeDecklist() << " cards" << endl;
			continue;
		case 4:
			deck.printDeck();
			cout << "Deck contains: " << deck.sizeDeck() << " cards" << endl;
			continue;
		case 5:
			cout << "Hole cards: " << endl;
			hand.printHole();
			continue;
		case 6:
			cout << "Community cards: " << endl;
			hand.printCommunity();
			continue;
		case 7:
			cout << "Available cards: " << endl;
			hand.printAvailable();
			continue;
		case 8:
			cout << "Hands available: " << endl;
			hand.printHands();
			continue;
		case 9:
			findBestHand(hand);
			cout << "Best hand: " << endl;
			hand.printBest();
			continue;
		case 10:
			//odds now
			break;
		case 11:
			//odds after flop
			break;
		default:
			cout << "Invalid input. Please enter either a number representing one of the following options:" << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Please choose from the following options: " << endl;
		cout << "1. Enter river card." << endl << "2. Randomise river card." << endl << "3. Print decklist." << endl << "4. Print deck." << endl << "5. Display hole cards. " << endl;
		cout << "6. Display community cards." << endl << "7. Display all known cards." << endl << "8. Display all available hand options." << endl << "9. Display the best available hand." << endl;
		cout << "10. Find odds of hand winning now. " << endl << "11. Find odds of hand winning on flop." << endl;

		cin >> inChar;
		input = inChar - '0';
		switch (input) {
		case 1:
			for (int i = 0; i != 1; ++i) {
				cout << "Enter river card 1: ";
				cin >> rank >> suit;

				burn.rank = rank;
				burn.suit = suit;

				//cout << "Card " << i + 5 << " is: " << rank << " " << suit << endl;

				bool cardSet = hand.setCard(deck, burn);

				if (cardSet)
					continue;
				else //try again
					i--;
			}
			break;
		case 2:
			break;
		case 3:
			deck.printDecklist();
			cout << "Decklist contains: " << deck.sizeDecklist() << " cards" << endl;
			continue;
		case 4:
			deck.printDeck();
			cout << "Deck contains: " << deck.sizeDeck() << " cards" << endl;
			continue;
		case 5:
			cout << "Hole cards: " << endl;
			hand.printHole();
			continue;
		case 6:
			cout << "Community cards: " << endl;
			hand.printCommunity();
			continue;
		case 7:
			cout << "Available cards: " << endl;
			hand.printAvailable();
			continue;
		case 8:
			cout << "Hands available: " << endl;
			hand.printHands();
			continue;
		case 9:
			findBestHand(hand);
			cout << "Best hand: " << endl;
			hand.printBest();
			continue;
		case 10:
			//odds now
			break;
		case 11:
			//odds after flop
			break;
		default:
			cout << "Invalid input. Please enter either '1', '2', '3' or '4'" << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Please choose from the following options: " << endl;
		cout << "1. Print decklist." << endl << "2. Print deck." << endl << "3. Display hole cards. " << endl;
		cout << "4. Display community cards." << endl << "5. Display all known cards." << endl << "6. Display all available hand options." << endl << "7. Display the best available hand." << endl;
		cout << "8. Find odds of hand winning now. " << endl << "9. Find odds of hand winning on flop." << endl << "10. Exit." << endl;

		cin >> inChar;
		input = inChar - '0';
		switch (input) {
		
		case 1:
			deck.printDecklist();
			cout << "Decklist contains: " << deck.sizeDecklist() << " cards" << endl;
			continue;
		case 2:
			deck.printDeck();
			cout << "Deck contains: " << deck.sizeDeck() << " cards" << endl;
			continue;
		case 3:
			cout << "Hole cards: " << endl;
			hand.printHole();
			continue;
		case 4:
			cout << "Community cards: " << endl;
			hand.printCommunity();
			continue;
		case 5:
			cout << "Available cards: " << endl;
			hand.printAvailable();
			continue;
		case 6:
			cout << "Hands available: " << endl;
			hand.printHands();
			continue;
		case 7:
			findBestHand(hand);
			cout << "Best hand: " << endl;
			hand.printBest();
			continue;
		case 8:
			//odds now
			break;
		case 9:
			//odds after flop
			break;
		case 10:
			break;
		default:
			cout << "Invalid input. Please enter either '1', '2', '3' or '4'" << endl;
			continue;
		}
		break;
	}

	findBestHand(hand);

	cout << "Best hand: " << endl;
	hand.printBest();

	findOdds(deck, hand);

	return 0;
}