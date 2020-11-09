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

  SECTION("should split for 1 delimiter") {
    std::vector<std::string> v = coda::split("Some text about it.", " ", 1);
    REQUIRE(v[0] == "Some");
    REQUIRE(v.size() == 1);
  }

  SECTION("should split for 2 delimiters") {
    std::vector<std::string> v = coda::split("Some text about it.", " ", 2);
    REQUIRE(v[0] == "Some");
    REQUIRE(v[1] == "text about it.");
    REQUIRE(v.size() == 2);
  }

  SECTION("should split for 3 delimiters and ignore last delimiter") {
    std::vector<std::string> v = coda::split("See a te xt", " ", 3);
    REQUIRE(v[0] == "See");
    REQUIRE(v[1] == "a");
    REQUIRE(v[2] == "te xt");
    REQUIRE(v.size() == 3);
  }
}