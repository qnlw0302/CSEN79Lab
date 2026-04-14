/*
 * CSEN 79 Lab Sample Code
 */
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "person.h"
#include "roster.h"

using namespace std;
using namespace csen79;

// Test code for class roster
// Input file: <CMD> [ID] [FIRST LAST]
// CMD : A | X | L
// ID: 7-digit unsigned integer
// FIRST, LAST: string
int main() {
	Roster r;
	Person st;
	Person::ID_t id;
	string cmd, first, last;

	// Read cmd first, then branch accordingly
	while (cin >> cmd) {
		switch (cmd[0]) {
		case Command::Add:
			cin >> st;
			try{
				r.insert(st);
			} catch (std::overflow_error &e){
				cout << e.what();
				cout << "Roster is full, can't insert: " << st << endl;
			}
			break;
		case Command::Erase:
			cin >> id;
			try {
				r.erase(id);
			} catch (std::invalid_argument &e) {
				cout << e.what();
				cout << "ID not found: " << id << endl;
			}
			break;
		case Command::Print:
			// listing the entire roster with a rudimentary iterator
			cout << "---- Current Roster ----"  << endl;
			int i = 1;
			for (auto st = r.begin(); st != r.end(); st = r.next(), i++)
				cout << i << ": " << *st << endl;
			break;
		} 
	}
	
	return EXIT_SUCCESS;
}

