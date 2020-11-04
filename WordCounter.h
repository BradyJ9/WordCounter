//
//  WordCounter.h
//  WordCounter
//
//  Created by Brady Bess on 3/21/18.
//  Copyright © 2018 Brady Bess. All rights reserved.
//

#ifndef WordCounter_h
#define WordCounter_h
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordCounter {
private:
    const vector<char> ILLEGAL_PUNCT = {',', '.', '?', ':', ';', '!', '\n', '\t','"','\'', ')','(','[',']', '\v', '\r', ' ', '\0'};
    int numWords;
    map<string, int> wordFreq;
public:
    void parsePassage(string contents);
    void processWord(string word);
    string isoWord(string word);
    void printWords();
};


#endif /* WordCounter_h */
