#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <cmath>
#include <iostream>
#include <fstream>

std::vector<bool> flip(std::vector<bool> arr)
{
  std::vector<bool> ans;
  for (int i = 0; i < arr.size(); i++)
    ans.push_back(!arr[i]);
  return ans;
}

int bits_to_dec(std::vector<bool> arr)
{
  int ans = 0;
  for (int i = arr.size() - 1; i >= 0; i--)
    if (arr[i])
      ans += pow(2, (arr.size() - 1) - i);
  return ans;
}

int binary_diagnostic(std::string input_path)
{
  std::ifstream input(input_path);
  std::string str;
  std::vector<std::vector<bool>> arr;

  while (getline(input, str))
  {
    std::vector<bool> bits;
    for (char c : str)
      bits.push_back(c == '1' ? true : false);
    arr.push_back(bits);
  }

  std::map<int, int> map;

  for (int i = 0; i < arr.size(); i++)
    for (int j = 0; j < arr[i].size(); j++)
      if (arr[i][j])
        map[j]++;

  std::string gamma = "";

  for (auto x : map)
    if (x.second > arr.size() / 2)
      gamma += '1';
    else
      gamma += '0';

  std::vector<bool> gamma_bits;
  std::vector<bool> epsilon_bits;

  for (char c : gamma)
    gamma_bits.push_back(c == '0' ? false : true);

  epsilon_bits = flip(gamma_bits);

  input.close();

  return bits_to_dec(gamma_bits) * bits_to_dec(epsilon_bits);
}

int calc_o2_rating(std::vector<std::vector<bool>> arr)
{
  int i = 0;

  while (arr.size() != 1)
  {
    int ones = 0;

    for (int j = 0; j < arr.size(); j++)
      if (arr[j][i])
        ones++;

    if (ones >= arr.size() - ones)
      arr.erase(std::remove_if(arr.begin(), arr.end(), [i](std::vector<bool> x){return !x[i];}), arr.end());
    else
      arr.erase(std::remove_if(arr.begin(), arr.end(), [i](std::vector<bool> x){return x[i];}), arr.end());

    i++;
  }

  return bits_to_dec(arr[0]);
}

int calc_co2_rating(std::vector<std::vector<bool>> arr)
{
  int i = 0;
  
  while (arr.size() != 1)
  {
    int zeroes = 0;

    for (int j = 0; j < arr.size(); j++)
      if (!arr[j][i])
        zeroes++;

    if (zeroes <= arr.size() - zeroes)
      arr.erase(std::remove_if(arr.begin(), arr.end(), [i](std::vector<bool> x){return x[i];}), arr.end());
    else
      arr.erase(std::remove_if(arr.begin(), arr.end(), [i](std::vector<bool> x){return !x[i];}), arr.end());

    i++;
  }

  return bits_to_dec(arr[0]);
}

int binary_diagnostic_part_two(std::string input_path)
{
  std::ifstream input(input_path);
  std::string str;
  std::vector<std::vector<bool>> arr;

  while (getline(input, str))
  {
    std::vector<bool> bits;
    for (char c : str)
      bits.push_back(c == '1' ? true : false);
    arr.push_back(bits);
  }

  int o2_rating = calc_o2_rating(arr);
  int co2_rating = calc_co2_rating(arr);

  input.close();

  return o2_rating * co2_rating;
}

int main() 
{
  // std::cout << binary_diagnostic("../../input/day3_2.txt") << '\n';
  std::cout << binary_diagnostic_part_two("../../input/day3_2.txt") << '\n';
}

