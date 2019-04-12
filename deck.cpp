//
// Created by khans on 4/5/2019.
//

#include "deck.h"
#include <math.h>
#include <ctime>

using namespace std;

/* The default constructor creates an array of cards which serves to be your deck */
Deck::Deck() {
    myIndex = 0;   //index needed to be kept track of

    for(int s = 0; s < 4; s++){
        for(int r = 1; r < 14; r++){
            myCards[myIndex] = Card(r, (Card:: Suit) s);  //creates an array
            myIndex++;  //index increments
        }
    }




    Seed();  //initiates the random number generator
    myIndex = 0;  //keeps the current index at zero also used later for determining how many number of cards are remaining in the deck
}

/* PRE: no input parameters
 * POST: swaps the two cards in the myCards array
*/
void Deck:: shuffle(){
    const int shuffletimes = 7;
    for(int j = 0; j < shuffletimes; j++) {      //for loop needed to randomize the cards in the deck
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
    if(myIndex == SIZE){
        return Card("Joker");
    }
    else{
        Card top = myCards[myIndex];
        myIndex++;
        return top;
    }
}

//This function returns the number of cards that are currently in your deck
int Deck::size() const {
    return SIZE - myIndex;
}
Deck:: ~Deck(){}   //deck destructor


