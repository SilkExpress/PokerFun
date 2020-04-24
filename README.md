# PokerFun

Deck.h/Deck.cpp:

-Create new struct "Card" which holds a card rank and suit.

-Create a standard 52 card decklist of vector<Card>.

-Create a deck of cards which point to the available cards in the decklist (each card can be used only once).

-Allow printing of the decklist and deck.

-Allow cards to be "burned" or "played" from the deck to a players hand (destroy a deck pointer to the decklist).


Hand.h/Hand.cpp:

-Store the cards available for the player to make a hand, e.g. hole, flop, turn and river cards.

-Store a vector of availabe hand options (e.g. with all 7 cards dealt, there are 10 options).

-Store a vector of the cards that make up the best available hand.

-Allow the available cards to be set from the deck.

-Allow the display of all known cards and hand options.


HandType.h/HandType.cpp:

-Create new struct "HandType" which holds a hand name and value.

-Function to evaluate a hand's value.

-Function to evaluate the best hand option from the available hand options.

//
