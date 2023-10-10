#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include <fstream>

#include "catch.hpp"
#include "../includes/Parser.hpp"

TEST_CASE("Parsing file should return right character counts") {
    std::ifstream f("test/sample.txt");
    Parser p(f);

    p.parse();

    REQUIRE(p.count_of('X') == 333);
    REQUIRE(p.count_of('t') == 223000);
    REQUIRE(p.count_of('?') == 2976);
    REQUIRE(p.count_of('_') == 2070);
}
