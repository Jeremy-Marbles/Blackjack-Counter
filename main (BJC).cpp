//blackjack_c(ard)_counter.cpp
#include <iostream>
#include <vector>
#include <random>

enum class suits
{
	Begin, HEARTS = Begin, CLUBS, SPADES, DIAMONDS, End
};

enum class values {
	Begin, TWO = Begin, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
	JACK, QUEEN, KING, ACE, End
};

struct Card {
	suits suit;
	values value;
};

//global variables
std::vector<Card> deck;

void createDeckTest(){
	Card generatedCard;
	generatedCard = {suits::HEARTS, values::TWO};
	deck.push_back(generatedCard);
	generatedCard = {suits::HEARTS, values::THREE};
	deck.push_back(generatedCard);
}

int main(int argc, char const *argv[])
{
	std::cout << "Blackjack CC" << std::endl;
	//Card testCard = {suits::HEARTS, values::THREE};
	//deck.push_back(testCard);
	
	createDeckTest();
	for (const auto& card : deck ) {
		std::cout << static_cast<int>(card.suit) << " " << static_cast<int>(card.value) << std::endl;
	}
	
	return 0;
}
