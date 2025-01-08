//blackjack card counting practice program
//by Jeremy Wong
//This program is meant to help with practice on card counting,
//with rules placed upon casinos such as deck slicing
//
//Implementing the high low system with counting
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

std::vector<Card> createDeck(std::vector<Card>& deck) {
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 13; j++) 
		{
			Card newCard = {static_cast<suits>(i), static_cast<values>(j)};
			deck.push_back(newCard);
		}
	}


	return deck;
}

std::vector<Card> shuffleDeck(std::vector<Card>& deck) 
{
	//seed random number generator for shuffling
	auto RNG = std::mt19937{std::random_device()()};
	std::uniform_int_distribution d(0, 51); //range between 1 and 52 cards in a standard deck
	for (int i = 0; i < sizeof(deck); i++) 
	{
		//get random seed
		int randomSeed = d(RNG);
		std::swap(deck[i], deck[randomSeed]);
	}

	return deck;
}

//Draw cards by taking from the first element of the shuffled deck array and send it to a pushable hand.
//1) call new player_hand vector (should be a global variable)
//2) move() from first deck vector element to player_hand vector (push_back?)
//3) remove from deck
void drawCard(std::vector<Card>& given_deck, std::vector<Card>& given_hand)
{
	/*TESTCASE: print value at given deck
	std::cout << static_cast<int>(given_deck[0].suit) << " " << static_cast<int>(given_deck[0].value) << std::endl;
	given_hand.push_back(given_deck[0]);
	std::cout << static_cast<int>(given_hand[0].suit) << " " << static_cast<int>(given_hand[0].value) << std::endl;
	*/

}


int main(int argc, char const *argv[])
{
	std::cout << "Blackjack CC" << std::endl;
	//Card testCard = {suits::HEARTS, values::THREE};
	
	std::vector<Card> deck_1;
	std::vector<Card> player_hand;

	createDeck(deck_1);		//confirmed functional
	shuffleDeck(deck_1);	//confirmed functional
	drawCard(deck_1, player_hand);

	/* TESTCCASE: print out the deck
	for (const auto& card : deck_1 ) {
		std::cout << static_cast<int>(card.suit) << " " << static_cast<int>(card.value) << std::endl;
	}
	*/

	return 0;
}
