#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
        for (int second = first + 1; second < n; ++second)
            max_product = std::max(max_product, (long long) numbers[first] * numbers[second]);

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
  int max_index = -1;
  int max_index2 = -1;

  for (int i = 0; i < numbers.size(); i++)
    if ((max_index == -1) || (numbers[i] > numbers[max_index]))
      max_index = i;

  for (int i = 0; i < numbers.size(); i++)
    if ((i != max_index) && ((max_index2 == -1) || (numbers[i] > numbers[max_index2])))
      max_index2 = i;

  return (long long) numbers[max_index] * numbers[max_index2];
}

int main() {
    // while(true) {
    //   int n = std::rand() % 1000 + 2;
    //   std::cout << n << '\n';
    //   std::vector<int> a;

    //   for (int i = 0; i < n; i++)
    //     a.push_back(rand() % 100000);

    //   for (int i = 0; i < n; i++)
    //     std::cout << a[i] << ' ';
    //   std::cout << '\n';

    //   long long res1 = MaxPairwiseProduct(a);
    //   long long res2 = MaxPairwiseProductFast(a);

    //   if (res1 != res2) {
    //     std::cout << "Wrong answer: " << res1 << ' ' << res2 << '\n';
    //     break;
    //   } 
    //   else
    //     std::cout << "OK\n";
    // }
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
        std::cin >> numbers[i];

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
