enum single_contact
{
	DRAW_THREE,     // note to self - this must be aware of "drawn" deck.
	                // if we assume there is only one "drawn" deck type per
			// game, we can just find that one. but what if a game
			// emerges with multiple instances of "drawn"? just
			// choosing the next one in the list might be a
			// solution
	DEAL_HORIZONTAL // spider deal - deals a single card to all decks
}

enum double_contact
{
	INCOMPATIBLE,   // these two decks are incompatible
	ALTERNATE_DOWN, // alternating colors, going down by one
	SAME_DOWN,      // same color, going down by one
	SAME_UP         // same color, going up by one
}

enum deck_type
{
	DRAW,   // the draw deck in klondike solitaire
	DRAWN,  // the three visible cards from klondike draw deck
	SIMPLE, // face-down hidden deck that upturns its top card once visible above deck is exhausted
	TOP     // all-visible above deck
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

// the biggest part of a game's ruleset definition is a series of matchups that
// define what moves are legal
typedef struct matchup_struct
{
	int deck_one; // use deck_type struct
	int deck_two; // use deck_type struct
	int matchup_type; // use double_contact struct
} matchup;
