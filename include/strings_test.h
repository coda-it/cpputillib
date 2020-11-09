#include "strings.h"
#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("split") {
  SECTION("should split string with all delimiters") {
    std::vector<std::string> v = coda::split("Some text about it.", " ");
    REQUIRE(v[0] == "Some");
    REQUIRE(v[1] == "text");
    REQUIRE(v[2] == "about");
    REQUIRE(v[3] == "it.");
  }

  SECTION("should return one element when no delimiters are found") {
    std::vector<std::string> v = coda::split("one", " ");
    REQUIRE(v[0] == "one");
    REQUIRE(v.size() == 1);
  }

  SECTION("should split for particular delimiter number") {
    std::vector<std::string> v = coda::split("Some text about it.", " ", 2);
    REQUIRE(v[0] == "Some");
    REQUIRE(v[1] == "text about it.");
    REQUIRE(v.size() == 2);
  }
}