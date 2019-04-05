//
// Created by khans on 4/5/2019.
//

#include "card.h"
#include <iostream>

using namespace std;

    Card:: Card()
    {
        myRank = 1;
        mySuit = spades;

    }

    Card:: Card(int _rank, Suit _s)
    {
        myRank = _rank;
        mySuit = _s;
    }

    Card:: Card(const Card &c_old)
    {
        myRank = c_old.myRank;
        mySuit = c_old.mySuit;

    }

    int Card::getRank() const
    {
        return myRank;

    }
    string Card::suitString(Card::Suit s) const
    {
        switch(s) {
            case Card::spades:
                return "s";
            case Card::hearts:
                return "h";
            case Card::clubs:
                return "c";
            case Card:: diamonds:
                return "d";
        }

    }
    string Card::rankString(int r) const
    {
        switch(r){
            case 1:
                return "A";
            case 2:
                return "2";
            case 3:
                return "3";
            case 4:
                return "4";
            case 5:
                return "5";
            case 6:
                return "6";
            case 7:
                return "7";
            case 8:
                return "8";
            case 9:
                return "9";
            case 10:
                return "10";
            case 11:
                return "J";
            case 12:
                return "Q";
            case 13:
                return "K";

        }
    }

    bool Card::sameSuitAs(const Card &c) const
    {
        //string currentSuit = suitString(mySuit);
        //string CardSuit = suitString(c.mySuit);
        if(mySuit == c.mySuit){
            return true;
        }
        else{
            return false;
        }

    }

    string Card::toString() const
    {
        string rank = rankString(myRank);
        string suit = suitString(mySuit);
        return rank + suit;

    }

    bool Card::operator==(const Card &rhs) const
    {
        if(myRank == rhs.myRank){
            return true;
        }
        else{
            return false;
        }
    }

    bool Card::operator != (const Card &rhs) const
    {
        if(myRank != rhs.myRank){
            return true;
        }
        else{
            return false;
        }
    }








