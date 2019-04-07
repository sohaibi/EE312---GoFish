#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <vector>

using namespace std;
// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p);
vector <Player> numPlayers(2); //containing two players
Player alternatePlayer(int &currindex);   //function which will be used to alternate each player's turn

int main() {


    int numCards = 5;

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


    //std::cout << "Hello, World!" << std::endl;
    //return 0;
}

/* PRE: Passing the deck and the player to be able to have cards in each player's hand
 * POST: There are supposed to be 5 cards in each player's hand. In this case, the size of the myHand vector
 * for each player should be 5 cards
*/
void dealHand(Deck &d, Player &p)
{
    p.addCard(d.dealCard());
}

/* This function is used to alternate between the players in the players vector */
/* PRE: Passing a valid index to this function. currindex has to be greater than zero.
 * POST: returns the player whose turn shall take place
*/
Player alternatePlayer(int &currindex){
    Player currentPlayer = numPlayers[ currindex % numPlayers.size()];
    return currentPlayer;
}
