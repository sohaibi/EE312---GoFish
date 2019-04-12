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
    //Creating the vector of players
    vector <Player> players;
    players.push_back(p1);
    players.push_back(p2);

    //Setting the turn index to 0
    int turn = 0;
    int specfic_suit = 0;  //Creating a card of a certain suit. This is used in the while loop to find the card that the
                           //opponent has in his hand if that opponent has the same ranking as the seeking card of the player
    bool found;

    ofstream log;
    log.open("logfile.txt");


    log << "WELCOME TO THE FIRST EDITION OF THE GO FISH CARD GAME WITH OUR CONTESTANTS " << players.at(0).getName() << " and " << players.at(1).getName() << endl;


    Deck d;  //create a deck of cards
    d.shuffle();  //shuffling a deck of cards


    for(int i = 0; i < 14; i++){
        turn = (turn+1) % 2;   //alternating turns between each player
        players.at(turn).addCard(d.dealCard()); //adding 7 cards to each player's hand
    }

    cout << "Player One " << players.at(0).showHand() << endl;
    cout << "Player Two " << players.at(1).showHand() << endl;

    Card pairA;  //these are just temporary card objects
    Card pairB;
    Card temp1;
    Card temp2;
    Card reserve;

    /* We first check whether each player has a book in their hand or not */
    while(players.at(0).checkHandForBook(pairA, pairB)){
        players.at(0).bookCards(players.at(0).removeCardFromHand(pairA), players.at(0).removeCardFromHand(pairB));
    }

    cout << "Player One Books " << players.at(0).showBooks() << endl;
    cout << players.at(0).getBookSize() << endl;

    while(players.at(1).checkHandForBook(pairA, pairB)){
        players.at(1).bookCards(players.at(1).removeCardFromHand(pairA), players.at(1).removeCardFromHand(pairB));
    }

    cout << "Player Two Books " << players.at(1).showBooks() << endl;
    cout << players.at(1).getBookSize() << endl;

    /* Actual Execution or driver for the Game */

    //This while loop will keep being executed until each player's book size adds up to greater than or equal
    //to 52 cards
    while((players.at(0).getBookSize() + players.at(1).getBookSize() < 52)){

        /* The two players show their books everytime */
        cout << players.at(0).getName() << " has " << "Books " << players.at(0).showBooks() << endl;
        cout << players.at(1).getName() << " has " << "Books " << players.at(1).showBooks() << endl;
        cout << endl;

        /* This is the case where it is important to check whether either of the players has no cards in their hand */
        /* If there are no cards in their hand remaining, then we must display the message that the player must draw another card
         * from their hand.
         * Note: They can't form a book in this case because they only chose one card only
         * The turn alternates to the next player
        */
        if(players.at(turn).getHandSize() == 0){
            log << players.at(turn).getName() << " has no cards in their hand" << " They must draw another card" << endl;
            Card must_draw = d.dealCard();
            log << players.at(turn). getName() << " draws" << " " << must_draw.toString() << endl;
            players.at(turn).addCard(must_draw);
            turn = (turn+1)%2;  //Since the player has drawn a card from their deck, it alternates the turn to the other player.
            continue;          //this will just continue the execution of the while loop. In other words, the game will still go on
        }


        Card seeking = players.at(turn).chooseCardFromHand(); //the player who has his or her turn chooses any one card from their hand
        int opponent = (turn + 1) % 2;  //opponent gets the alternating index
        found = false;   //Setting the boolean variable found to be false because we have not found the card from the opponent's hand that has
        //the same ranking as the seeking card

        log << players.at(turn).getName() << " asks - Do you have any" << " " << seeking.rankString(seeking.getRank()) << endl;
        //player asks the opponent for the card that has similar ranking to the seeking card

        if(players.at(opponent).rankInHand(seeking)){
        log << players.at(opponent).getName() << " says - Yes. I have a" << " " << seeking.rankString(seeking.getRank()) << endl;
        //Opponent has the card of the same ranking as the player who has his turn

        /* Now we need to find what card the opponent is holding in his hand that is of the same rank as the seeking card but
         * not the same suit as the seeking card. There are 3 possiblities that the opponent has the certain card of the same rank
         * The purpose for this while loop is to keep going through these possibilities so that once we find the card
         * We set the boolean variable found to be true
        */
            while(!found){
                Card match = Card(seeking.getRank(),(Card::Suit)specfic_suit);  //Creating a matching card that the opponent has in his hand
                if(players.at(opponent).cardInHand(match)){
                    log << players.at(turn).getName() << " books the" << " " << seeking.rankString(seeking.getRank()) << endl;
                    Card testSeeking = players.at(turn).removeCardFromHand(seeking);  //testSeeking is the seeking card that the player who has his turn is going to remove
                    Card testMatch = players.at(opponent).removeCardFromHand(match);  //testMatch is the card with the same rank as the seeking card that the opponent will remove
                    players.at(turn).bookCards(testMatch, testSeeking); //We use testMatch and testSeeking cards to form a book and add it to the book pile of the player who has his turn
                    found = true; //Since we formed a book, we will step out of this while loop
                }
                specfic_suit++;  //Increasing the specific suit variable which is to keep match the suit of the card in the
                                 //opponent's hand
            }
            specfic_suit = 0;   //We need to set the specific suit back to 0 after the while loop ends
        }

        /* If the opponent has doesn't have the card with the same ranking as the seeking card, then it will execute this part of the code
         * Here the opponent is going to draw a card from the deck and add it to his hand
         * If that card happens to have the same ranking as any one of the cards in his hand, he will book those pair of cards.
         * Also, the player will end his turn
        */
        else{
            log << players.at(opponent).getName() << " says - Go Fish" << endl;
            Card deal = d.dealCard();  //deals the card puts it in the temporary card object named deal
            log << players.at(turn). getName() << " draws" << " " << deal.toString() << endl;
            players.at(turn).addCard(deal); //adds it to the hand
            if(players.at(turn).checkHandForBook(pairA, pairB)) {
                players.at(turn).bookCards(players.at(turn).removeCardFromHand(pairA), players.at(turn).removeCardFromHand(pairB));
            }

            turn = (turn+1)%2;  //Alternating the turns between the players
        }
    }

    /* After the game ends, the player will show their books and their hands and the player who has formed the
     * most books will win the game
    */

    cout << players.at(0).getName() << " has " << players.at(0).showHand() << endl;
    cout << players.at(1).getName() << " has " << players.at(1).showHand() << endl;
    cout << players.at(0).getName() << " has " << "Books " << players.at(0).showBooks() << endl;
    cout << players.at(1).getName() << " has " << "Books " << players.at(1).showBooks() << endl;




//    Player p1("Alice");
//    Player p2("Bob");
//    vector <Player> players;
//    players.push_back(p1);
//    players.push_back(p2);
//    int turn = 0;
//    bool duration;
//
//    Deck d;  //create a deck of cards
//    d.shuffle();
//
//    ofstream log;
//    log.open("logfile.txt");
//
//
//    for(int i = 0; i < 7; i++){
//        p1.addCard(d.dealCard());
//        p2.addCard(d.dealCard());
//    }
//    Card pairA;
//    Card pairB;
//    Card temp1;
//    Card temp2;
//
//    while(p1.checkHandForBook(pairA, pairB)){
//        p1.bookCards(pairA, pairB);
//        temp1 = p1.removeCardFromHand(pairA);
//        temp2 = p1.removeCardFromHand(pairB);
//    }
//
//    while(p2.checkHandForBook(pairA, pairB)){
//        p2.bookCards(pairA, pairB);
//        temp1 = p2.removeCardFromHand(pairA);
//        temp2 = p2.removeCardFromHand(pairB);
//    }
//
//    while(p1.getBookSize() + p2.getBookSize() < 26){
//        //update whose turn it is
//        int opponent = turn;   //initially, the first player is the opponent
//        turn = (turn + 1)%2;   //and the second player has his turn first
//        duration = true;
//        //pick "seeking card"
//        Card seeking = players.at(turn).chooseCardFromHand();
////        log << players.at(turn).getName() << "asks 'do you have any" << seeking.rankString(seeking.getRank()) << endl;
//        //check for match from opponent
//        if(players.at(opponent).rankInHand(seeking)){
//           //if there is a match, book seeking and the discovered match
//        }
//        //otherwise draw card and book if a match is discovered
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
//
    return EXIT_SUCCESS;
}
//
