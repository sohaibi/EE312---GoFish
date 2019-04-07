//
// Created by khans on 4/5/2019.
//

#ifndef SIXTHLAB_DECK_H
#define SIXTHLAB_DECK_H

#include "card.h"


class Deck
{
    static const int SIZE = 52;

public:


    Deck();           // pristine, sorted deck
    ~Deck();

    void shuffle();   // shuffle the deck, all 52 cards present
    Card dealCard();   // get a card, after 52 are dealt, fail

    int  size() const; // # cards left in the deck

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
    int numCards;
    void Seed();
    void Swap(Card &c2, Card &c1);
};


#endif //SIXTHLAB_DECK_H
