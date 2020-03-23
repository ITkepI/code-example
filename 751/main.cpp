#include "towers-of-hanoi.hpp"

#include <iostream>

int main()
{
  try
  {
    TowersOfHanoi towers;

    int num;
    while (std::cin >> num)
    {
      towers.move(num);
    }

    towers.print();

    return 0;
  }
  catch (TowersOfHanoi::towers_exception& e)
  {
    std::cerr << e.what() << "\n";
  }
}
