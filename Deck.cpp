#include "stdafx.h"
#include "Deck.h"

using std::cout;
using std::endl;

Deck::Deck()
{
	for (int i = 0; i != 52; ++i) {
		decklist.push_back(Card());

		if (i < 13) {
			decklist[i].rank = i + 2;
			decklist[i].suit = "Hearts";
		}
		else if (i < 26 && i >= 13) {
			decklist[i].rank = i - 11;
			decklist[i].suit = "Diamonds";
		}
		else if (i < 39 && i >= 26) {
			decklist[i].rank = i - 24;
			decklist[i].suit = "Spades";
		}
		else if (i < 52 && i >= 39) {	
			decklist[i].rank = i - 37;
			decklist[i].suit = "Clubs";
		}
		Card* dp = new Card;
		dp->rank = decklist[i].rank;
		dp->suit = decklist[i].suit;

		deck.push_back(dp);
	}
}

int Deck::sizeDecklist() const
{
	return decklist.size();
}

int Deck::sizeDeck() const
{
	return deck.size();
}

void Deck::printDecklist() const
{
	for (int i = 0; i != decklist.size(); ++i) {
		cout << decklist[i].rank << " " << decklist[i].suit << endl;
	}
}

void Deck::printDeck() const
{
	for (std::list<Card*>::const_iterator iter = deck.begin(); iter != deck.end(); ++iter) {
		cout << (*iter)->rank << " " << (*iter)->suit << endl;
	}
}

void Deck::burnCard(Card& burn)
{
	for (std::list<Card*>::iterator iter = deck.begin(); iter != deck.end(); ++iter) {
		if ((*iter)->rank == burn.rank) {
			if ((*iter)->suit == burn.suit) {
				deck.erase(iter++);
			}
		}
	}
}
