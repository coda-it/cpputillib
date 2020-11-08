#include <iostream>
#include <string>
#include <vector>

namespace coda {
std::vector<std::string> split(std::string text, std::string delimiter) {
  std::size_t start;
  std::size_t end;
  std::vector<std::string> split;

  start = 0;
  end = text.find(delimiter);
  while (true) {
    split.push_back(text.substr(start, end - start));

    if (end == std::string::npos) {
      break;
    }

    start = end + 1;
    end = text.find(delimiter, end + 1);
  }

  return split;
}
} // namespace coda