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

void createDeck(){
	/* TESTCASE:
	 * Card generatedCard;
	generatedCard = {suits::HEARTS, values::TWO};
	deck.push_back(generatedCard);
	generatedCard = {suits::HEARTS, values::THREE};
	deck.push_back(generatedCard);*/
	Card newCard;
	//add switch case for loop here
	for (int i = 0; i < 13; i++){
		switch (i) {
		 case 0:
		  newCard = {suits::HEARTS, values::TWO};
		  deck.push_back(newCard);
		  break;
		 case 1:
		  newCard = {suits::HEARTS, values::THREE};
		  deck.push_back(newCard);
		  break;
		 case 2:
		  newCard = {suits::HEARTS, values::FOUR};
		  deck.push_back(newCard);
		  break;
		 case 3:
		  newCard = {suits::HEARTS, values::FIVE};
		  deck.push_back(newCard);
		  break;
		 case 4:
		  newCard = {suits::HEARTS, values::SIX};
		  deck.push_back(newCard);
		  break;
		 case 5:
		  newCard = {suits::HEARTS, values::SEVEN};
		  deck.push_back(newCard);
		  break;
		 case 6:
		  newCard = {suits::HEARTS, values::SEVEN};
		  deck.push_back(newCard);
		  break;
		 case 7:
		  newCard = {suits::HEARTS, values::EIGHT};
		  deck.push_back(newCard);
		  break;
		 case 8:
		  newCard = {suits::HEARTS, values::NINE};
		  deck.push_back(newCard);
		  break;
		 case 9:
		  newCard = {suits::HEARTS, values::TEN};
		  deck.push_back(newCard);
		  break;
		}
	}
}

int main(int argc, char const *argv[])
{
	std::cout << "Blackjack CC" << std::endl;
	//Card testCard = {suits::HEARTS, values::THREE};
	//deck.push_back(testCard);
	
	createDeck();
	for (const auto& card : deck ) {
		std::cout << static_cast<int>(card.suit) << " " << static_cast<int>(card.value) << std::endl;
	}
	
	return 0;
}
