//
//  WordCounter.cpp
//  WordCounter
//
//  Created by Brady Bess on 3/21/18.
//  Copyright © 2018 Brady Bess. All rights reserved.
//
#include "WordCounter.h"
#include <stdio.h>
#include <vector>
#include <algorithm>

bool comparer(pair<int, string> p1, pair<int, string> p2) {return p1.first > p2.first;}

bool comparer2(pair<int, string> p1, pair<int, string> p2) {return p1.second > p2.second;}


void WordCounter::parsePassage(string contents) {
    unsigned long index = 0;
    contents += ' '; //ensures every passage ends in a space (prevents infinite while loop on the second while loop)
    unsigned long contSize = contents.size();
    
    while (index != contSize) { //parse through whole passage
        string tempWord;
        while (contents[index] != ' ' && contents[index] != '\n') { //parse word to word
            tempWord += contents[index];
            index++;
        }
        processWord(tempWord);
        index++;
    }
    printWords();
}

void WordCounter::processWord(string word) {
    
    //cout << word << endl; //Debugging
    if (word == "\0") {
        return;
    }
    
    if (find(ILLEGAL_PUNCT.begin(), ILLEGAL_PUNCT.end(), word[0]) != ILLEGAL_PUNCT.end()) { //illegal space
        return;
    }
    
    char beginChar = word[0];
    char endChar = word[word.size() - 1];
    if (find(ILLEGAL_PUNCT.begin(), ILLEGAL_PUNCT.end(), beginChar) != ILLEGAL_PUNCT.end()
        || find(ILLEGAL_PUNCT.begin(), ILLEGAL_PUNCT.end(), endChar) != ILLEGAL_PUNCT.end()) {
        word = isoWord(word);  //eliminates punctuation before and after word so it is not classified as a separate word
    }

    if (wordFreq.find(word) != wordFreq.end()) { //if word has already been used
        ++wordFreq.find(word)->second;
    } else { //word is unique
        pair<string, int> unique;
        unique = make_pair(word, 1);
        wordFreq.insert(unique);
    }
    
    numWords++;
}

string WordCounter::isoWord(string word) {
    char begin = word.at(0);
    if (find(ILLEGAL_PUNCT.begin(), ILLEGAL_PUNCT.end(), begin) != ILLEGAL_PUNCT.end()) { //if first char isn't alphabet erase it
        word = word.erase(0, 1); //cut it off
        word = isoWord(word); //check again
    }
    char end = word[word.size() - 1];
    if (find(ILLEGAL_PUNCT.begin(), ILLEGAL_PUNCT.end(), end) != ILLEGAL_PUNCT.end()) { //if last char isn't alphabet erase it
        word = word.erase(word.size() - 1); //cut it off
        word = isoWord(word);  //check again
    }

    return word; //base case
    
}


void WordCounter::printWords() {
    cout << "Total Words: " << numWords << endl << endl;
    cout << "-Number of Times Used-" << endl;
    vector<pair<int , string>> invertFreq;
    for (auto word : wordFreq) { //flips map to sort numerically
        pair<int, string> inv; //number of occurrences first, word second to sort
        inv = make_pair(word.second, word.first);
        invertFreq.push_back(inv);
    }
    
    //sort(invertFreq.begin(), invertFreq.end(), comparer2);

    //sort(invertFreq.begin(), invertFreq.end(), comparer);
    

    
    for (int i = 0; i < invertFreq.size(); i++) {
        cout << invertFreq.at(i).second << ": " << invertFreq.at(i).first << endl;
    }
}
