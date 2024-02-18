//
// Created by Nicholas Helco on 2/1/2024.
//

#include <iostream>
#include <FlexLexer.h>
#include <map>

void doubleArr(char*, int&);
void addToLexSymbolTable(std::string, char*, int&, std::map<std::string, std::pair<uint32_t, uint32_t> > &);

int main(int argc, char *argv[]){

    // The lexical symbol table:
    int lexemesLength = 1024;  // start with 1024 chars
    char* lexemes = new char[lexemesLength];
    lexemes[255] = '\0';
    std::map<std::string, std::pair<uint32_t, uint32_t> > LexemeTable;
    //                             <offset,   tokenType>

    // Add all keywords to the symbol table


    // load the c file named in argv


    // pass the file to the parser





    return 0;
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
 * lexemesLength - the length of lexemes
 * LexemeTable - the lexical symbol table
 *
 * This function will double the length of lexemes array if
 * nLexeme will not fit in the current array.
 * */
void addToLexSymbolTable(std::string nLexeme, char* lexemes, int &lexemesLength, std::map<std::string, std::pair<uint32_t, uint32_t> > &LexemeTable){

    // if nLexeme will not fit in lexemes:
    if(){

        // double the length of lexemes
        doubleArr(lexemes, lexemesLength);
    }

    // Now add nLexeme to lexemes


    // Create new entry in symbol table

}


