#include <bits/stdc++.h>
#include "utils.hpp"
using namespace std;

#ifdef FMT_ENABLED
#include <fmt/ranges.h>
#define FMTPRINT(...) fmt::print(__VA_ARGS__)
#else
#define FMTPRINT(...) ;
#endif

void solve1(const string& inpath) {
  auto lines = read_file_lines(inpath);
  long long sum = 0;

  for (auto& line : lines) {
    std::vector<int> digits(2, 0);
    size_t i = 0;
    size_t j = line.size() - 1;

    while ((digits[0] == 0 || digits[1] == 0) && i <= line.size() - 1 && j >= 0) {
      if (digits[0] == 0 && isdigit(line[i]))
        digits[0] = line[i] - '0';
      else i++;

      if (digits[1] == 0 && isdigit(line[j]))
        digits[1] = line[j] - '0';
      else j--;
    }

    sum += digits[0] * 10 + digits[1];
  }

  FMTPRINT("{}\n", sum);
}

void solve2(const string& inpath) {
  map<string, int> digits{
      {"one", 1},
      {"two", 2},
      {"three", 3},
      {"four", 4},
      {"five", 5},
      {"six", 6},
      {"seven", 7},
      {"eight", 8},
      {"nine", 9}};

  auto lines = read_file_lines(inpath);
  auto p2 = [&](auto const& s) {
    pair<size_t, size_t> left = {string::npos, 0};
    pair<size_t, size_t> right = {0, 0};

    // Handle digit case
    for (size_t i = 0; i < s.size(); i++) {
      if (isdigit(s[i])) {
        if (left.first > i) left = {i, s[i] - '0'};
        if (right.first <= i) right = {i, s[i] - '0'};
      }
    }

    // Handle word case
    for (auto& [k, v] : digits) {
      // Search for the word until it can't find it
      for (auto p = s.find(k); p != string::npos; p = s.find(k, p + 1)) {
        if (left.first > p) left = {p, v};
        if (right.first <= p) right = {p, v};
      }
    }

    return left.second * 10 + right.second;
  };

  FMTPRINT("{}\n", transform_reduce(lines.begin(), lines.end(), 0, plus{}, p2));
}

int main() {
  //   vector<string> files1 = {"tests/day1_1_sample.txt", "tests/day1_1.txt"};

  //   for (auto& file : files1)
  //     solve1(file);

  vector<string> files2 = {"tests/day1_2.txt", "tests/day1_2_sample.txt"};

  for (auto& file : files2)
    solve2(file);

  return 0;
}