//
//  bookHelper.hpp
//  BookAnalyzer
//
//  Created by Anirudh Lath on 9/3/21.
//

#ifndef bookHelper_hpp
#define bookHelper_hpp

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

// Search word statistical data
struct userWordStat {
    int location = 0;
    std::string wordsAround;
    
};

// Search proper noun statistical data
struct properNounStat {
    int location = 0;
    std::string wordsAround;
};

// Content data of the given book
struct content {
    std::vector<std::string> words;
    int totalWords = 0;
    int totalCharacters = 0;
    std::string userWord;
    std::string shortestWord;
    std::string longestWord;
    std::vector<userWordStat> userWordStats;
    std::vector<properNounStat> properNounStats;
    
};

// Structure of the book
struct book {
    content bookData;
    std::string title;
    std::string author;
    std::string releaseDate;
    
};

// Definitions that will be used in main() in analyser.cpp
book readData(std::ifstream &infile, std::string userWord);
void printStatistics(book book1);
void encodeData(std::ofstream& myStream, book &book1, int encodeKey);

#endif /* bookHelper_hpp */
