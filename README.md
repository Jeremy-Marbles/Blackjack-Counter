# Blackjack-Counter
## A subtle C++ program on terminals for playing Blackjack. ~~And learning how to count cards.~~
The Hi-Lo system is implemented directly within the game.
### How to launch:
1. Simply launch the exe, which opens your terminal. Instructions to play are built in (Input "-1" at any time to quit out).
If building directly from code, note that there are no other external libraries needed. 
### Current features
- Generating and shuffling a deck (vector)
- Setting a betting amount
- Drawing cards into player hands
- Checking scores per draw
- Print out hands for both dealer and player
### To Be (Potentially) Implimented
- Wait signals 
- More decks (i.e not one deck)
- Double downs and other betting variables 
### More Info
Youtube recommended the series of videos by https://www.youtube.com/@QuattroAP as I was really considering how I can get the most out of yearly family trips to Las Vegas. As I don't play card games as often, I thought about the way I can apply what I've read online about blackjack and started programming this as a means to practice for both. 
**By no means is Blackjack-Counter meant to be an all-in-one learning program.** There are far more requirements - outside of code - needed to actually understand the nuances of blackjack in real life and I recommend reading/watching as much as you can to minimize the risk from gambling.
### Notes:
- There are no limiters/edge-case detection for bad inputs, i.e setting negative values for putting a bet in. 