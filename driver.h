//
// Initial driver code given by Dr.Kramer on 3/2/2024.
//

#ifndef WSLFBTEST2_DRIVER_H
#define WSLFBTEST2_DRIVER_H

#include <string>
#include <map>
#include "YaccCode.tab.hpp"

#define YY_DECL yy::parser::symbol_type yylex(Driver &d)

YY_DECL;

class Driver {
public:
    Driver();

    std::map<std::string,int32_t>
            vars;

    int32_t
            result;

    std::string
            inFileName;

    bool
            traceParsing,
            traceScanning;

    yy::location
            location;

    int32_t
    parse(const std::string &fn);

    void
            scanBegin(),
            scanEnd();

};

#endif //WSLFBTEST2_DRIVER_H
