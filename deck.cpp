//
// Created by khans on 4/5/2019.
//

#include "deck.h"
#include <math.h>

using namespace std;

Deck::Deck() {
    int i = 0;   //index needed to be kept track of

    for(int r = 0; r < 13; r++){
        for(int s = 0; s < 4; s++){
            myCards[i] = Card(r, (Card:: Suit) s);
            i++;  //index increments
        }
    }

    Seed();
}
void Deck:: shuffle(){
    int num1 = rand() % SIZE;
    int num2 = rand() % SIZE;

    Card card1 = myCards[num1];
    Card card2 = myCards[num2];



}
