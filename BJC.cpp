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
	for (int i = 0; i < deck.size(); i++) 
	{
		//get random seed
		int randomSeed = d(RNG);
		std::swap(deck[i], deck[randomSeed]);
	}

	return deck;
}

//Draw cards by taking from the first element of the shuffled deck array and send it to a pushable hand.
//1) call new player_hand vector (should be a global variable)
//2) check if vector is empty
//3) move() from first deck vector element to player_hand vector (push_back?)
//4) remove from deck [use erase()]
void drawCard(std::vector<Card>& given_deck, std::vector<Card>& given_hand)
{
	/*TESTCASE: print value at given deck
	std::cout << static_cast<int>(given_deck[0].suit) << " " << static_cast<int>(given_deck[0].value) << std::endl;
	given_hand.push_back(given_deck[0]);
	std::cout << static_cast<int>(given_hand[0].suit) << " " << static_cast<int>(given_hand[0].value) << std::endl;
	*/
	if (given_deck.empty()) { 
		std::cout << "drawCard Error: Empty Vector for given_deck input" << std::endl;
	} else {
		given_hand.push_back(*given_deck.begin());
		given_deck.erase(given_deck.begin());
	}

}

void printCard(std::vector<Card> play_hand, int index) 
{
	std::string suit;
	std::string value;
	switch (play_hand[index].suit) {
	case suits::HEARTS:
		suit = "Hearts";
		break;
	case suits::CLUBS:
		suit = "Clubs";
		break;
	case suits::SPADES:
		suit = "Spades";
		break;
	case suits::DIAMONDS:
		suit = "Diamonds";
		break;
	}

	switch (play_hand[index].value) {
	case values::TWO:
		value = "Two";
		break;
	case values::THREE:
		value = "Three";
		break;
	case values::FOUR:
		value = "Four";
		break;
	case values::FIVE:
		value = "Five";
		break;
	case values::SIX:
		value = "Six";
		break;
	case values::SEVEN:
		value = "Seven";
		break;
	case values::EIGHT:
		value = "Eight";
		break;
	case values::NINE:
		value = "Nine";
		break;
	case values::TEN:
		value = "Ten";
		break;
	case values::JACK:
		value = "Jack";
		break;
	case values::QUEEN:
		value = "Queen";
		break;
	case values::KING:
		value = "King";
		break;
	case values::ACE:
		value = "Ace";
		break;
	}

	std::cout << value << " of " << suit << std::endl;
}

//Check a given hand for total card amount.  
//1) cycle through hand for enums. while vector[i] != vector.end()
//2) initiate return int as total value of hand
//3) If aces are present, change between values if necessary (1 or 11). TODO: figure out logic for aces
//COMPLETE: make a logic function to print out suit of card
int checkHand(std::vector<Card>& given_hand) 
{
	if(given_hand.empty()) {	//Give an error code for bad given_hand
		std::cout << "checkHand Error: Empty Vector for given_hand input" << std::endl;
		return -3;
	}
	
	int total = 0;
	
	//Hand parsing logic:
	//1) Check for aces first, then add up the total of the hand
	//2) If aces are present, add 11 to total, then check if total is over 21. If so, subtract 10 from total
	for (int i = 0; i < given_hand.size(); i++) 
	{
		if (given_hand[i].value != values::ACE){
			switch (given_hand[i].value){
		 	 case values::TWO:	
		   	  total += 2;
			  printCard(given_hand, i);
		   	  break;
		 	case values::THREE:
		   	 total += 3;
			 printCard(given_hand, i);
		   	 break;
		 	case values::FOUR:
		   	 total += 4;
			 printCard(given_hand, i);
		   	 break;
		 	case values::FIVE:
		  	 total += 5;
			 printCard(given_hand, i);
		  	 break;
			case values::SIX:
		  	 total += 6;
			 printCard(given_hand, i);
		  	 break;
		 	case values::SEVEN:
		 	 total += 7;
			 printCard(given_hand, i);
		 	 break;
		 	case values::EIGHT:
		 	 total += 8;
			 printCard(given_hand, i);
		  	 break;
		 	case values::NINE:
		  	 total += 9;
			 printCard(given_hand, i);
		  	 break;
		 	case values::TEN:
		  	 total += 10;
			 printCard(given_hand, i);
		  	 break;
		 	case values::JACK:
		  	 total += 10;
			 printCard(given_hand, i);
		  	 break;
		 	case values::QUEEN:
		  	 total += 10;
			 printCard(given_hand, i);
		  	 break;
		 	case values::KING:
		  	 total += 10;
			 printCard(given_hand, i);
		  	 break;
			}
		}

		if (given_hand[i].value == values::ACE){
			if (total != 21) {
				total += 11;
			} else if (total > 21) {
				total = total - 10;
			}
		}

	}
	return total;
}

//Start high low (running count) calculation
//NOTE: Ace, face cards, 10s are -1. 2-6 are +1. 7-9 do not give (dis)advantage

int calcHiLow(std::vector<Card> player_hand, std::vector<Card> dealer_hand)
{
	int advantage = 0;
	int player_advantage = 0, dealer_advantage = 0;

	for (int i = 0; i < player_hand.size(); i++)
	{
		switch(player_hand[i].value)
		{
			case values::TWO:
			case values::THREE:
			case values::FOUR:
			case values::FIVE:
			case values::SIX:
				player_advantage++;
				break;
			case values::TEN:
			case values::JACK:
			case values::QUEEN:
			case values::KING:
			case values::ACE:
				player_advantage--;
				break;
			default:
				break;
		}
	}
	
	for (int i = 0; i < dealer_hand.size(); i++)
	{
		switch(dealer_hand[i].value)
		{
			case values::TWO:
			case values::THREE:
			case values::FOUR:
			case values::FIVE:
			case values::SIX:
				dealer_advantage++;
				break;
			case values::TEN:
			case values::JACK:
			case values::QUEEN:
			case values::KING:
			case values::ACE:
				dealer_advantage--;
				break;
			default:
				break;
		}
	}

	return advantage;

}

int getTrueCount(int advantage, int currentDecks)
{
	if (advantage <= -1) {
		std::cout << "True count is less than zero: aborting calculation." << std::endl;
		return -1;
	}

	int trueCount = advantage / currentDecks;

	return trueCount;
}

//Purge vectors for next round, or after a deck is empty. Return 1 if vector is clear, -1 otherwise
int resetVectors(std::vector<Card>& given_hand) 
{
	given_hand.clear();
	if (given_hand.empty()){
		return 1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	std::cout << "Blackjack Classic Count" << std::endl;
	
	std::vector<Card> deck_1;		//Used in final main function
	std::vector<Card> player_hand; 
	std::vector<Card> dealer_hand;
	int currentAmount;

	//START MAIN FUNCTIONALITY
	std::cout << "Set initial buy-in: ";	//Will not check for negative values
	std::cin >> currentAmount;
	std::cout << "Bet amount: $" << currentAmount << std::endl;
	std::cout << "Generating and shuffling deck 1" << std::endl;
	createDeck(deck_1);
	//TESTCASE: Print last card
	//std::cout << static_cast<int>(deck_1[51].suit) << " " << static_cast<int>(deck_1[51].value) << std::endl;
	shuffleDeck(deck_1);
	//TESTCASE: Print last card for randomized choice
	//std::cout << static_cast<int>(deck_1[51].suit) << " " << static_cast<int>(deck_1[51].value) << std::endl;
	
	

	bool quitGame = false;
	int input = 11, playerIncrement = 0, dealerIncrement = 0; //FIXME: convert int increment into vector size increment
	std::cout << "Force Quit the game by setting '10' as an input" << std::endl;
	while (quitGame != true) {
	
		//TODO: add logic for doubling bets
		//FIXME: Reroute logic for calculating score
		
		 //draw beginning cards
		std::cout << "\nBeginning round" << std::endl;
		if (dealer_hand.empty()) {
			drawCard(deck_1, dealer_hand);
			std::cout << "Dealer's hand: " << std::endl;
			printCard(dealer_hand, dealerIncrement);
			dealerIncrement++;
		}

		std::cout << std::endl;

		if (player_hand.empty()) {	//populate 
			drawCard(deck_1, player_hand);
			drawCard(deck_1, player_hand);
			playerIncrement = 2;
			std::cout << "Player's hand: " << std::endl;
			for (int i = 0; i < player_hand.size(); i++) {
				printCard(player_hand, i);
			}
		}
			
		std::cout << "Select Option: " << std::endl;
		std::cout << "(0)Draw Card - (1)Stand - (2)Get Current Score" << std::endl;
		std::cin >> input;

		if (input == 10) {
			quitGame = true;
		}
		
		if (input == 0) {
			drawCard(deck_1, player_hand);
			playerIncrement++;
			std::cout << "\nPlayer's hand: " << std::endl;
			for (int i = 0; i < player_hand.size(); i++) {
				printCard(player_hand, i);
			}
		}

		if (input == 1) {
			int playerTally = checkHand(player_hand);
		}



	}

	return 0;
}
