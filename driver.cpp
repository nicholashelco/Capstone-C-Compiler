//
// Initial driver code given by Dr.Kramer on 3/2/2024.
//

#include "driver.h"
#include "YaccCode.tab.hpp"

Driver::Driver() {

    traceParsing = traceScanning = false;

    st = SyntaxTree();

    result = 0;
}

int32_t Driver::parse(const std::string &fn) {

    inFileName = fn;

    location.initialize(&inFileName);

    scanBegin();

    yy::parser parse(*this);

    parse.set_debug_level(traceParsing);

    int32_t res = parse();

    scanEnd();

    return res;
}


int Driver::makeNode(int TokenType, yy::parser::value_type& leftNode, yy::parser::value_type& rightNode){
    return st.makeNode(TokenType, leftNode.as<int>(), rightNode.as<int>() );
}


void Driver::makeDummy(int32_t r, int32_t n){
    st.makeDummy(r, n);
}


// Make a leaf node
int Driver::makeLeaf(int32_t type, std::string lex){
    return st.makeLeaf(type, lex);
}


void Driver::printTree(){
    st.printTree();
}