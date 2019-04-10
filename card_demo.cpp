#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <vector>
#include <fstream>

using namespace std;
// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p);
//vector <Player> numPlayers(2); //containing two players
//Player alternatePlayer(int &currindex);   //function which will be used to alternate each player's turn

int main() {

    Player p1("Alice");
    Player p2("Bob");
    vector<Player> players;
    players.push_back(p1);
    players.push_back(p2);
    int turn = 0;

    Deck d;  //create a deck of cards
    d.shuffle();


    for (int i = 0; i < 14; i++) {
        turn = (turn + 1) % 2;
        players.at(turn).addCard(d.dealCard());
    }
    //check both players hands for existing pairs and remove to book
    Card pairA;
    Card pairB;
    while (players.at(0).checkHandForBook(pairA, pairB)) {
        players.at(0).bookCards(players.at(0).removeCardFromHand(pairA), players.at(0).removeCardFromHand(pairB));
    }
    while (players.at(1).checkHandForBook(pairA, pairB)) {
        players.at(1).bookCards(players.at(1).removeCardFromHand(pairA), players.at(1).removeCardFromHand(pairB));
    }
    while ((players.at(0).getBookSize() + players.at(1).getBookSize() < 52)) {
        Card seeking = players.at(turn).chooseCardFromHand();
        int opponent = (turn + 1) % 2;
        if (players.at(opponent).rankInHand(seeking)) {
            for (int i = 0; i < 4; i++) {
                Card match = Card(seeking.getRank(), (Card::Suit) i);
                if (players.at(opponent).cardInHand(match)) {
                    players.at(turn).bookCards(players.at(opponent).removeCardFromHand(match), seeking);
                    players.at(turn).removeCardFromHand(seeking);
                }
            }
        } else {
            players.at(turn).addCard(d.dealCard());
            if (p1.checkHandForBook(pairA, pairB)) {
                players.at(turn).bookCards(players.at(turn).removeCardFromHand(pairA),
                                           players.at(turn).removeCardFromHand(pairB));
            }
            turn = (turn + 1) % 2;
        }

    }




//    while((p1.getBookSize() / 2) + (p2.getBookSize() / 2) < 26){
//        //update whose turn it is
//        int opponent = turn;
//        turn = (turn + 1)%2;
//        duration = true;
//        //pick "seeking card"
//
//        Card seeking = players.at(turn).chooseCardFromHand();
//        //check for match from opponent
//        if(players.at(opponent).rankInHand(seeking)){
//            //if there is a match, book seeking and the discovered match
//        }
//            //otherwise draw card and book if a match is discovered
//        else{
//            players.at(turn).addCard(d.dealCard());
//            if(p1.checkHandForBook(pairA, pairB)){
//                players.at(turn).bookCards(pairA, pairB);
//                temp1 = players.at(turn).removeCardFromHand(pairA);
//                temp2 = players.at(turn).removeCardFromHand(pairB);
//            }
//            duration = false;
//        }
//    }

    return EXIT_SUCCESS;

    /*


    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    numPlayers[0] = p1;
    numPlayers[1] = p2;



    Deck d;  //create a deck of cards
    d.shuffle();


    int playerIndex = 0;
    Player Player1 = alternatePlayer(playerIndex);
    playerIndex++;
    Player Player2 = alternatePlayer(playerIndex);
    playerIndex++;
    Player Player3 = alternatePlayer(playerIndex);
    playerIndex++;
    Player Player4 = alternatePlayer(playerIndex);


    for(int i = 0; i < numCards; i++){
        dealHand(d, p1);
        dealHand(d, p2);
    }

    int remCards = d.size();


    cout << remCards << endl;
    cout << p1.getName() << endl;
    cout << p2.getName() << endl;



    return EXIT_SUCCESS;

 */
    //std::cout << "Hello, World!" << std::endl;
    //return 0;
}

/* PRE: Passing the deck and the player to be able to have cards in each player's hand
 * POST: There are supposed to be 5 cards in each player's hand. In this case, the size of the myHand vector
 * for each player should be 5 cards
*/

/*
void dealHand(Deck &d, Player &p)
{
    p.addCard(d.dealCard());
}
*/

/* This function is used to alternate between the players in the players vector */
/* PRE: Passing a valid index to this function. currindex has to be greater than zero.
 * POST: returns the player whose turn shall take place
*/

/*
Player alternatePlayer(int &currindex){
    Player currentPlayer = numPlayers[ currindex % numPlayers.size()];
    return currentPlayer;
}
*/
