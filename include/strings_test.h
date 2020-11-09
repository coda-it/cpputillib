#include "strings.h"
#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("split") {
  std::vector<std::string> v = coda::split("Some text about it.", " ");
  REQUIRE(v[0] == "Some");
  REQUIRE(v[1] == "text");
  REQUIRE(v[2] == "about");
  REQUIRE(v[3] == "it.");
}