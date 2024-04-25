//
// Initial driver code given by Dr.Kramer on 3/2/2024.
//

#ifndef WSLFBTEST2_DRIVER_H
#define WSLFBTEST2_DRIVER_H

#include <string>
#include <map>
#include "YaccCode.tab.hpp"
#include "SyntaxTree.h"

#define YY_DECL yy::parser::symbol_type yylex(Driver &d)

YY_DECL;

class Driver {
public:
    Driver();

    std::map<std::string,int32_t> vars;

    int32_t result;

    std::string inFileName;

    bool traceParsing, traceScanning;

    yy::location location;

    int32_t parse(const std::string &fn);

    void scanBegin(), scanEnd();

    SyntaxTree st;

    // Wrapper functions for the syntax tree:

    int makeNode(int32_t type, int32_t l, int32_t r, std::string lex);

    void makeDummy();

    // Make a leaf node
    int makeLeaf(int32_t type, std::string lex);

    void printTree();
};

#endif //WSLFBTEST2_DRIVER_H
