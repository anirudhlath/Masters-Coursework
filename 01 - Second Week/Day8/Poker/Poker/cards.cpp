//
//  cards.cpp
//  Poker
//
//  Created by Anirudh Lath on 8/31/21.
//

#include "cards.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

vector<cards> CreateDeck(int jokerCount){
    // Assign the variables
    cards card;
    vector<cards> deckOfCards;
    vector<string> houses = {"clubs", "diamonds", "hearts", "spades"};
    vector<int> ranks = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    
    // Populate the deck
    for( string house: houses) {
        card.house = house;
        if (house == "clubs" or house == "spades") {
            card.color = "black";
        } else {
            card.color = "red";
        }
        for(int rank: ranks){
            card.rank = rank;
            deckOfCards.push_back(card);
        }
    }
    
    // Check for Jokers and populate the deck if there are any.
    if (jokerCount > 0) {
        cards joker;
        for (int j = 0; j < jokerCount; j++) {
            joker.joker = true;
            joker.rank = 0;
            joker.house = "";
            joker.color = "";
            deckOfCards.push_back(joker);
        }
    }
    return deckOfCards;
}

void PrintDeck(vector<cards> deck){
    for(cards card: deck){
        if (!card.joker) {
            if(card.house == "spades"){
                card.house = "♠";
            } else if(card.house == "hearts"){
                card.house = "♥";
            } else if(card.house == "diamonds"){
                card.house = "♦";
            } else if(card.house == "clubs"){
                card.house = "♣";
            }
            if (card.rank == 11) {
                cout << "J " << card.house << " of color " << card.color << endl;
            } else if (card.rank == 12) {
                cout << "Q " << card.house << " of color " << card.color << endl;
            } else if (card.rank == 13) {
                cout << "K " << card.house << " of color " << card.color << endl;
            } else if (card.rank == 1) {
                cout << "A " << card.house << " of color " << card.color << endl;
            } else {
                cout << card.rank << " " << card.house << " of color " << card.color << endl;
            }
        }
        if (card.joker) {
            cout << "Joker" << endl;
        }
    }
}

void swapCards(cards & i, cards & j) {
    cards num = j;
    j = i;
    i = num;
}

void ShuffleDeck(vector<cards> & deck, int & randomSeed){ /* Seed added for later improvements */
    for(int i = deck.size() - 1; i > 0; i-- ){
        int random = (rand() % (deck.size() - 1));
        int x = i;
        cards card = deck[i];
        deck[x] = deck[random];
        deck[random] = card;
//        swapCards(deck[i], deck[rand() % deck.size() - 1]);
    }
}

vector<cards> dealFiveCards(vector<cards> deck) {
    vector<cards> cardsInHand;
    for (int i = 0; i < 5; i++) {
        int x = rand() % (deck.size() - 1);
        cardsInHand.push_back(deck[x]);
    }
    return cardsInHand;
}

bool isFlush(vector<cards> cardsInHand) {
    int DiamondsCount = 0;
    int HeartsCount = 0;
    int SpadesCount = 0;
    int ClubsCount = 0;
    int jokerCount = 0;
    bool isFlush = false;
    
    for(cards card: cardsInHand){
        if (card.house == "diamonds") {
            DiamondsCount++;
        } else if (card.house == "hearts") {
            HeartsCount++;
        } else if (card.house == "clubs") {
            ClubsCount++;
        } else if (card.house == "spades") {
            SpadesCount++;
        } else if (card.joker) {
            jokerCount++;
        }
    }
    if (DiamondsCount == (5 - jokerCount)
        or HeartsCount == (5 - jokerCount)
        or ClubsCount == (5 - jokerCount)
        or SpadesCount == (5 - jokerCount))
    {
        isFlush = true;
    }
    return isFlush;
}

bool isStraight(vector<cards> cardsInHand) {
    vector<int> numStack;
    
    for(cards card: cardsInHand){
        numStack.push_back(card.rank);
    }

    sort(numStack.begin(), numStack.end());
    
    for(int i = 0; i < numStack.size() - 1; i++){
        int r = i + 1;
        int check = numStack[r] - 1;
        if(numStack[i] != check and numStack[i] != 0){
            return false;
        }
    }
    return true;
}
