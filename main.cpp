//
// Created by Nicholas Helco on 2/1/2024.
//

#include <iostream>
#include <FlexLexer.h>
#include <map>

#include "driver.h"


void doubleArr(char*, int&);
void addToLexSymbolTable(std::string, char*, int&, int&, std::map<std::string, std::pair<uint32_t, uint32_t> > &);


int main(int argc, char *argv[]){

    int32_t res = 0;
    Driver d;

    for (int32_t i=1; i<argc; i++)

        if (argv[i] == std::string("-p"))
            d.traceParsing = true;

        else if (argv[i] == std::string("-s"))
            d.traceScanning = true;

        else if (!d.parse(argv[i]))
            std::cout << d.result << '\n';

        else
            res = 1;

    d.parse(argv[0]);
    d.printTree();

    return res;
}


/* Function to double the length of
   a char array that begins at pointer old
   and is currently n elements long */
void doubleArr(char* old, int &n){

    // create new c-string of doubled size
    int newSize = n * 2;
    char* tempData = new char[newSize];

    // copy old data to new data
    for(int i=0; i<n; i++){
        tempData[i] = old[i];
    }

    // move old terminator character to the end!
    tempData[n-1] = 0;
    tempData[newSize-1] = '\0';

    // delete the old c-string
    delete[] old;

    // copy new pointer to old c-string
    old = tempData;
    n = newSize;
}


/* Function to add an entry to the lexical symbol table.
 *
 * nLexeme - the new lexeme to be added
 * lexemes - the c-string containing all lexemes
 * curOffset - first available index in lexemes
 * lexemesLength - the current length of lexemes
 * LexemeTable - the lexical symbol table
 *
 * This function will double the length of lexemes array if
 * nLexeme will not fit in the current array.
 * */
void addToLexSymbolTable(std::string nLexeme, char* lexemes, int &curOffset, int &lexemesLength, std::map<std::string, std::pair<uint32_t, uint32_t> > &LexemeTable){

    // if nLexeme will not fit in remaining space in lexemes:
    if(lexemesLength - curOffset < nLexeme.size() ){

        // double the length of lexemes
        doubleArr(lexemes, lexemesLength);
    }

    // Now add nLexeme to lexemes
    int strLen = nLexeme.size();
    for(int i=0; i<strLen; i++){
        lexemes[curOffset] = nLexeme[i];
        curOffset++;
    }

    // Create new entry in symbol table                         // This 0 should be the token type of nLexeme!
    std::pair<uint32_t, uint32_t> newPair (curOffset-strLen, 0);
    // map.insert requires a single argument - pair<key, value>
    LexemeTable.insert(std::pair<std::string, std::pair<uint32_t, uint32_t> > (nLexeme, newPair) );

}


