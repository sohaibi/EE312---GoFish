//
// Created by khans on 4/5/2019.
//
#include "player.h"
#include <vector>


void Player::addCard(Card c) {        //adds the card to the end of the vector myHand
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);      //adds the two cards to the end of the vector push_back
    myBook.push_back(c2);
}


/* PRE: Making sure it is valid card with an appropriate rank and suit
 * POST: returns the last card in your hand which had the similar ranking as Card c
*/
Card Player::removeCardFromHand(Card c) {
    Card seeking;
    for(vector<Card>::iterator it = myHand.begin(); it!= myHand.end(); it++) {
        if (it->getRank() == c.getRank()) {
            seeking = *it;  //assignment operator for card needed
            myHand.erase(it);
        }
    }
    return seeking;
}

//RETURNS THE SIZE OF THE VECTOR myBook
int Player::getBookSize() const {
    return myBook.size();  //accessor function that returns the book size
}

//Returns the size of the vector myHand
int Player::getHandSize() const {
    return myHand.size();
}

//for the moment the player just asks for whatever card they got last
Card Player::chooseCardFromHand() const {
    return myHand.back();
}







