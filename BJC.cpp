//blackjack_c(ard)_counter.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>

enum class suits
{
	Begin, HEARTS = Begin, CLUBS, SPADES, DIAMONDS, End
};

enum class values {
	Begin, TWO = Begin, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING, ACE, End
};

struct Card {
	suits suit;
	values value;
};

//global variables
//to be added: Multiple decks as per rules in casinos
std::vector<Card> deck; //initial deck
std::vector<Card> deck_2; 


void createDeck() {
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 13; j++) 
		{
			Card newCard = {static_cast<suits>(i), static_cast<values>(j)};
			deck.push_back(newCard);
		}
	}
}

void shuffleDeck() 
{
	//seed random number generator for shuffling
	auto RNG = std::mt19937{std::random_device()()};
	std::uniform_int_distribution d(0, 51);
	for (int i = 0; i < sizeof(deck); i++) 
	{
		//get random seed

	}
}

int main(int argc, char const *argv[])
{
	std::cout << "Blackjack CC" << std::endl;
	//Card testCard = {suits::HEARTS, values::THREE};
	//deck.push_back(testCard);
	
	createDeck();
	/* TESTCCASE: print out the deck
	for (const auto& card : deck ) {
		std::cout << static_cast<int>(card.suit) << " " << static_cast<int>(card.value) << std::endl;
	}
	*/

	
	return 0;
}
