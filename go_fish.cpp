#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include <vector>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

int main() {
    Player p1("Alice");
    Player p2("Bob");
    vector <Player> players;
    players.push_back(p1);
    players.push_back(p2);
    int turn = 0;

    Deck d;  //create a deck of cards
    d.shuffle();

    ofstream log;
    log.open("logfile.txt");


    for(int i = 0; i < 7; i++){
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }
    Card pairA;
    Card pairB;

    while(p1.checkHandForBook(pairA, pairB)){
        p1.bookCards(pairA, pairB);
    }

    while(p2.checkHandForBook(pairA, pairB)){
        p2.bookCards(pairA, pairB);
    }

    while(p1.getBookSize() + p2.getBookSize() < 26){
        //update whose turn it is
        int opponent = turn;
        turn = (turn + 1)%2;
        //pick "seeking card"
        Card seeking = players.at(turn).chooseCardFromHand();
        log << players.at(turn).getName() << "asks 'do you have any" << seeking.rankString(seeking.getRank()) << endl;
        //check for match from opponent
        if(players.at(opponent).rankInHand(seeking)){
           //if there is a match, book seeking and the discovered match
        }
        //otherwise draw card and book if a match is discovered
        else{
            players.at(turn).addCard(d.dealCard());
            if(p1.checkHandForBook(pairA, pairB)){
                players.at(turn).bookCards(pairA, pairB);
            }
        }
    }

    return EXIT_SUCCESS;


    //std::cout << "Hello, World!" << std::endl;
    //return 0;
}

