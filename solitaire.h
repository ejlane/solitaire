enum contact
{
	INCOMPATIBLE,   // these two decks are incompatible
	ALTERNATE_DOWN, // alternating colors, going down by one
	SAME_DOWN,      // same color, going down by one
	SAME_UP         // same color, going up by one
}

enum deck_type
{
	CLASSIC_DRAW,   // the draw deck in classic solitaire
	CLASSIC_FACEUP, // the three visible cards from classic draw deck
	SIMPLE,         // face-down hidden deck that upturns its top card once visible above deck is exhausted
	CLASSIC_TOP,    // all-visible above deck (classic card matching)
	SPIDER_TOP      // all-visible above deck (spider card matching)
}

// card *next is so that I can make a linked list of cards (deck)
typedef struct card_struct
{
	int number;
	char suit;
	card *next;
} card;

// deck struct acts as the head for a linked list of cards. holds deck type metadata
// also supports deck *next for making a linked list of decks
typedef struct deck_struct
{
	int type; // use deck_type struct
	card *first; // first card in deck
	deck *next;  // next deck in list (if this is a linked list of decks)
} deck;
