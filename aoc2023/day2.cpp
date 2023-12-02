#include <bits/stdc++.h>
#include "utils.hpp"
using namespace std;

#ifdef FMT_ENABLED
#include <fmt/ranges.h>
#define FMTPRINT(...) fmt::print(__VA_ARGS__)
#else
#define FMTPRINT(...) ;
#endif

#define GAME_REGEX "Game (\\d+): (.*)"
#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

void solve1(const string& inpath) {
  auto lines = read_file_lines(inpath);
  long long sum = 0;
  for_each(
      lines.begin(),
      lines.end(),
      [&](string line) {
        long long id = 0;
        regex game_regex(GAME_REGEX);
        smatch matches;

        if (regex_search(line, matches, game_regex))
          id = stoi(matches[1].str());

        auto tokens = split(matches[2].str(), ";");
        for (auto& token : tokens) {
          smatch m;
          long long red(0), green(0), blue(0);
          if (regex_search(token, m, regex("(\\d+) red"))) red = stoi(m[1].str());
          if (regex_search(token, m, regex("(\\d+) green"))) green = stoi(m[1].str());
          if (regex_search(token, m, regex("(\\d+) blue"))) blue = stoi(m[1].str());
          if (red > MAX_RED || green > MAX_GREEN || blue > MAX_BLUE) return;
        }
        sum += id;
      });
  FMTPRINT("{}\n", sum);
}

void solve2(const string& inpath) {
  auto lines = read_file_lines(inpath);
  long long sum = 0;
  for_each(
      lines.begin(),
      lines.end(),
      [&](string line) {
        regex game_regex(GAME_REGEX);
        smatch matches;
        regex_search(line, matches, game_regex);

        auto tokens = split(matches[2].str(), ";");
        int red(0), green(0), blue(0);
        for (auto& token : tokens) {
          smatch m;
          if (regex_search(token, m, regex("(\\d+) red"))) red = max(red, stoi(m[1].str()));
          if (regex_search(token, m, regex("(\\d+) green"))) green = max(green, stoi(m[1].str()));
          if (regex_search(token, m, regex("(\\d+) blue"))) blue = max(blue, stoi(m[1].str()));
        }
        sum += red * green * blue;
      });
  FMTPRINT("{}\n", sum);
}

int main() {
  // vector<string> files1 = {"tests/day2_1_sample.txt", "tests/day2_1.txt"};

  // for (auto& file : files1)
  //   solve1(file);

  vector<string> files2 = {"tests/day2_1_sample.txt", "tests/day2_1.txt"};

  for (auto& file : files2)
    solve2(file);

  return 0;
}