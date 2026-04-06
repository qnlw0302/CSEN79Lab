/*
 * CSEN 79 Lab: Poker Statistics
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include "card.h"
#include "deck.h"
#include "poker.h"

using namespace std;
using namespace lab2_zqin2;

void pokerHands(Poker &poker) {
    bool found[Poker::POKER_ARRAY_SIZE] = {false};
    int foundcount = 0;

    while (foundcount < Poker::POKER_ARRAY_SIZE) {
        poker.dealHand();
        Poker::Rank r = poker.rankHand();

        if (!found[r]) {
            found[r] = true;
            foundcount++;

            cout << Poker::RankNames[r] << ": ";
            const Card *hand = poker.getHand();
            for (int i = 0; i < Poker::POKER_HANDCARDS; i++) {
                cout << hand[i] << " ";
            }
            cout << endl;
        }
    }
}

// Collect statistics for each rank of Poker
void pokerStats(Poker &poker) {
	const int BATCH = 50000;
	long count[Poker::POKER_ARRAY_SIZE] = {0};
	long total = 0;
	double prev[Poker::POKER_ARRAY_SIZE] = {0};
	time_t tmark = clock();			// ready, get set, go!
	time_t batchTime = clock();
	while (true){
		for(int i = 0; i< BATCH; i++){
			poker.dealHand();
			count[poker.rankHand()]++;
		}
		total += BATCH;
		bool stable = true;
		for (int r = 0; r < Poker::POKER_ARRAY_SIZE; r++){
			double pct = 100.0 * count[r] / total;
			if (fabs(pct -prev[r]) > 0.01) stable = false;
			prev[r] = pct;
		}
		if (stable && total >= 50000) break;
	}
	/*
	 * Do your thing here.
	 * This is supposed to be big loop that deal many many poker hands and collect the
	 * statistics for each rank.
	 * Once you believe the statistics are good.  Exit the loop.
	 * "tmark" then computes the number of "clock ticks" in your loop.
	 * You should convert that to human friendly units, such as "seconds"
	 * 
	 * Output your stats then, with the amount of time it took you collect the stats.
	 */
	tmark = clock() - tmark;	// stop the clock
	double seconds = (double) tmark / CLOCKS_PER_SEC;
	double avgPer50K = seconds / (total / BATCH);
	cout << "Dealt " << total << " hands. Elapsed Time: " << seconds << " seconds." << endl;
    cout << "Average " << avgPer50K << " seconds per 50k hands" << endl;
	for (int r = Poker::POKER_ARRAY_SIZE - 1; r >= 0; r--){
		cout << setw(20) << right << Poker::RankNames[r] << ": " << setw(8) << count[r] << " " << fixed << setprecision(2) << (100.0 * count[r] / total) << "%" << endl;
	}
}

int main(void) {
	Poker poker;
	cout << "Sample hand for each Rank:" << endl;
	pokerHands(poker);
	cout << endl << "Statistics:" << endl;
	pokerStats(poker);

	return EXIT_SUCCESS;
}
