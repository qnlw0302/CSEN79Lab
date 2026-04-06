/*
 * Name: Ziyi Qin
 * Email: zqin2@scu.edu
 */
#include <iostream>
#include <algorithm>
#include "card.h"
#include "deck.h"

namespace lab2_zqin2 {
	
	// implement Fisher-Yates here
	void Deck::shuffle(void){
    for (int i = 51; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(cards[i], cards[j]);
    	}
    next = 0;
	}
	// deal out one card
	const Card &Deck::deal() {
		if (52 - next <= guard)
			shuffle();
		return cards[next++];	// replace this line with your implementation of the function.
	}
}

