//
// Created by khans on 4/5/2019.
//
#include "player.h"
#include <vector>

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(vector<Card>::iterator first = myHand.begin(); first != myHand.end(); first++){
        for(vector<Card>::iterator second = myHand.begin(); second != myHand.end(); second++){
            if((first -> getRank() == second -> getRank()) && !(first -> sameSuitAs(*second)))
                c1 = *first;
                c2 = *second;
                return true;
        }
    }
 return false;
}

bool Player::cardInHand(Card c) const {
    for(int k = 0; k < myHand.size(); k++){
        if(myHand[k] == c){
            return true;
        }
    }
    return false;
}
void Player::addCard(Card c) {        //adds the card to the end of the vector myHand
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);      //adds the two cards to the end of the vector myBook
    myBook.push_back(c2);
}


/* PRE: Making sure it is valid card with an appropriate rank and suit
 * POST: returns the last card in your hand which had the similar ranking as Card c
*/
Card Player::removeCardFromHand(Card c) {

    Card seeking;
    for(vector<Card>::iterator it = myHand.begin(); it!= myHand.end(); it++) {
        if (it->getRank() == c.getRank() && it->sameSuitAs(c))  {
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
    int num = rand() % myHand.size();
    return myHand[num];
}
string Player::showHand() const {
    string hand = "";
    for(int show = 0; show < myHand.size(); show++){
        hand = hand + myHand[show].toString() + " ";
    }
    return hand;
}

string Player::showBooks() const {
    string book = "";
    for(int showBook = 0; showBook < myBook.size(); showBook++){
        book = book + myBook[showBook].toString() + " ";
    }
    return book;

}







