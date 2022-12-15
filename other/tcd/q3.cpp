#include <stdexcept>
#include <iostream>

int minimalNumberOfPackagesSlow(int items, int availableLargePackages, int availableSmallPackages)
{
  int numOfLarge = 0;
  int numOfSmall = 0;

  while (items > 0) {
    if (items % 5 == 0 && availableLargePackages > 0) {
      numOfLarge++;
      availableLargePackages--;
      items -= 5;
    } else if (items % 1 == 0 && availableSmallPackages > 0) {
      numOfSmall++;
      availableSmallPackages--;
      items -= 1;
    } else {
      return -1;
    }
  }

  return numOfLarge + numOfSmall;
}

// large can hold 5 items
// small can hold 1 item

int minimalNumberOfPackages(int items, int availableLargePackages, int availableSmallPackages)
{
  int numOfLarge = std::min(items / 5, availableLargePackages);
  items = items - (numOfLarge * 5);
  int numOfSmall = std::min(items / 1, availableSmallPackages);
  items = items - (numOfSmall * 1);

  if (items != 0) return -1;

  return numOfLarge + numOfSmall;
}

#ifndef RunTests
int main()
{
    std::cout << minimalNumberOfPackages(10000, 2, 10) << std::endl;
}
#endif
