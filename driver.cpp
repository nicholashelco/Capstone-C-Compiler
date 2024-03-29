//
// Initial driver code given by Dr.Kramer on 3/2/2024.
//

#include "driver.h"
#include "YaccCode.tab.hpp"

Driver::Driver() {

    traceParsing = traceScanning = false;

    result = 0;
}

int32_t Driver::parse(const std::string &fn) {

    inFileName = fn;

    location.initialize(&inFileName);

    scanBegin();

    yy::parser
            parse(*this);

    parse.set_debug_level(traceParsing);

    int32_t
            res = parse();

    scanEnd();

    return res;
}
