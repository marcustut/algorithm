#include <fstream>
#include <iostream>
#include <string>

std::vector<std::string> read_file_lines(const std::string& path) {
  std::ifstream file(path);
  std::string line;
  std::vector<std::string> lines;

  if (!file.is_open()) throw std::runtime_error("Failed to open file '" + path + "'");

  while (getline(file, line))
    lines.push_back(line);

  return lines;
}