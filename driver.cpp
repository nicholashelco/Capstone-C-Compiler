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


void Driver::makeNode(int32_t type, int32_t l, int32_t r, std::string lex){
    st.makeNode(type, l, r, lex);
}


void Driver::makeDummy(){
    st.makeDummy();
}


// Make a leaf node
void Driver::makeLeaf(int32_t type, std::string lex){
    st.makeLeaf(type, lex);
}


void Driver::printTree(){
    st.printTree();
}