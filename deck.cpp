//
// Created by khans on 4/5/2019.
//

#include "deck.h"
#include <math.h>
#include <ctime>

using namespace std;

/* The default constructor creates an array of cards which serves to be your deck */
Deck::Deck() {
    int i = 0;   //index needed to be kept track of

    for(int r = 1; r < 14; r++){
        for(int s = 0; s < 4; s++){
            myCards[i] = Card(r, (Card:: Suit) s);  //creates an array
            i++;  //index increments
        }
    }

    Seed();  //initiates the random number generator
    numCards = 0;  //Later for determining how many number of cards are remaining in the deck
    myIndex = 0;  //keeps the current index at zero
}

/* PRE: no input parameters
 * POST: swaps the two cards in the myCards array
*/
void Deck:: shuffle(){
    for(int j = 0; j < SIZE; j++) {      //for loop needed to randomize the cards in the deck
        int num1 = rand() % SIZE;
        int num2 = rand() % SIZE;
        Swap(myCards[num2], myCards[num1]);
    }
}

/* PRE: This is a helper function where two valid cards with an appropriate rank and suit
 * POST: swaps the two cards in the myCards array
*/
void Deck::Swap(Card &c2, Card &c1) {
    Card temp = c1;
    c1 = c2;
    c2 = temp;
}

//PRE: No input parameters
//POST: initates the random number generator by giving it a seed
void Deck::Seed() {
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
}

//PRE: No input parameters
//POST: returns the topmost card in your deck and increments the number of cards used.
Card Deck::dealCard() {
    if(numCards == SIZE){
        return Card();
    }
    else{
        Card top = myCards[myIndex];
        myIndex++;
        numCards++;
        return top;
    }
}

//This function returns the number of cards that are currently in your deck
int Deck::size() const {
    return SIZE - numCards;
}
Deck:: ~Deck(){}   //deck destructor


