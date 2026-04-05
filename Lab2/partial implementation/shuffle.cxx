/*
 * Name: Ziyi Qin
 * Email: zqin2@scu.edu
 */
#include <iostream>
#include "card.h"
#include "deck.h"

namespace csen79 {
	// implement Fisher-Yates here
	void Deck::shuffle(void) {}

	// deal out one card
	const Card &Deck::deal() {
		return cards[0];	// replace this line with your implementation of the function.
	}
}

