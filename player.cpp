//
// Created by khans on 4/5/2019.
//
#include "player.h"
#include <vector>


void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

Card Player::removeCardFromHand(Card c) {
    Card seeking;
    for(vector<Card>::iterator it = myHand.begin(); it!= myHand.end(); it++) {
        if (it->getRank() == c.getRank()) {
            seeking = *it;
            myHand.erase(it);
        }
    }
    return seeking;
}

int Player::getBookSize() const {
    return myBook.size();
}

int Player::getHandSize() const {
    return myHand.size();
}

//for the moment the player just asks for whatever card they got last
Card Player::chooseCardFromHand() const {
    return myHand.back();
}







