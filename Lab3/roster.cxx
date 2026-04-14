/*
 * CSEN 79 Lab Sample Code
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "person.h"
#include "roster.h"


namespace csen79 {

	// STUDENT WORK
	Roster::Roster(){
		idx = 0;
		last = 0;
	}
	// insert into the roster
	void Roster::insert(const T &rec) {
		for (int i = 0; i < CAPACITY; i++){
			if(roster[i].getID() == 0){
				roster[i] = rec;
				if (i >= last)
					last = i + 1;
				return;
			}
		}
		throw std::overflow_error("Roster::insert: roster is full");
		// STUDENT WORK
	}

	// simply mark the slot empty
	void Roster::erase(Person::ID_t id) {
		for (int i = 0; i < last; i++){
			if(roster[i].getID() == id){
				roster[i] = T();
				while(last > 0 && roster[last - 1].getID() == 0)
					last--;
				return;
			}
		}
		throw std::invalid_argument("Roster::erase: ID not found");
		// STUDENT WORK
	}

	// rudimentary iterator
	// in the future, this will return an object of iterator type
	Roster::T* Roster::begin(void) {
		idx = 0;
		while(idx < last && roster[idx].getID() == 0){
			idx++;
		}
		if (idx >= last){return end();}
		// STUDENT WORK
		return &roster[idx];
	}

	Roster::T* Roster::end(void) {
		// STUDENT WORK
		return &roster[last];
	}

	// The next element for interation
	// if already reached the end, throw exception
	Roster::T* Roster::next(void) {
		if(idx >= last){
			throw std::out_of_range("Roster::next: already at end");
		}
		do {
			idx++;
		} while(idx < last && roster[idx].getID() == 0);
		if (idx >= last)
			return end();
		// STUDENT WORK
		return &roster[idx];
	}
}
