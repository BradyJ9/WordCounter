//
//  main.cpp
//  WordCounter
//
//  Created by Brady Bess on 3/21/18.
//  Copyright © 2018 Brady Bess. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "WordCounter.h"

using namespace std;

string processStringFromFile(string fileName) {

    ifstream fileContents;
    fileContents.open(fileName.c_str());

    if (!fileContents.is_open()) {
        cout << "Error: Failed to open file" << endl;
        return "error";
    }

    stringstream contents;
    contents << fileContents.rdbuf();

    return contents.str();
}

int main(int argc, const char * argv[]) {

    WordCounter instance;

    string strContents = processStringFromFile(argv[1]);
    //string strContents = processStringFromFile("WordsToCount.txt"); //for debugging

    if (strContents == "error") {
        return 0;
    }
    //cout << strContents << endl; //Debugging

    instance.parsePassage(strContents);

    return 0;
}
