#include <string>
#include <vector>

#ifndef CODA_STRINGS_H
#define CODA_STRINGS_H

namespace coda {
std::vector<std::string> split(std::string text, std::string delimiter,
                               int number = -1) {
  std::vector<std::string> split;
  int i = 0;
  std::size_t start = 0;
  std::size_t end = text.find(delimiter);

  while (true) {
    split.push_back(text.substr(start, end - start));

    if (end == std::string::npos || (number != -1 && i >= number - 1)) {
      break;
    }

    start = end + 1;

    if (number == -1 || (number != -1 && i != number - 2)) {
      end = text.find(delimiter, end + 1);
    } else {
      end = text.length();
    }

    i++;
  }

  return split;
}
} // namespace coda

#endif /* CODA_STRINGS_H */