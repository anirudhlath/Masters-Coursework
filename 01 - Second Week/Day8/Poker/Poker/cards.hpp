//
//  cards.hpp
//  Poker
//
//  Created by Anirudh Lath on 8/31/21.
//

#ifndef cards_hpp
#define cards_hpp

#include <stdio.h>
#include <string>
#include <vector>

struct cards {
    int rank;
    std::string color;
    bool joker;
    std::string house;
};

std::vector<cards> CreateDeck(int jokerCount);
void PrintDeck(std::vector<cards> deck);
void swapCards(cards & i, cards & j);
void ShuffleDeck(std::vector<cards> & deck, int & randomSeed);
std::vector<cards> dealFiveCards(std::vector<cards> deck);
bool isStraight(std::vector<cards> cardsInHand);

#endif /* cards_hpp */
