#include "towers-of-hanoi.hpp"

#include <iostream>

TowersOfHanoi::TowersOfHanoi() :
  towers_({ std::deque<int>{3, 2, 1}, std::deque<int>{}, std::deque<int>{} })
{ }

void TowersOfHanoi::move(int from, int to)
{
  if ((from > 3) || (from < 1) || (to > 3) || (to < 1))
  {
    throw out_of_range();
  }

  if (towers_[from - 1].empty())
  {
    throw empty_rod();
  }

  if (!towers_[to - 1].empty() && (towers_[from - 1].back() > towers_[to - 1].back()))
  {
    throw incorrect_size();
  }

  int tmp = towers_[from - 1].back();
  towers_[from - 1].pop_back();
  towers_[to - 1].push_back(tmp);
}

void TowersOfHanoi::move(int value)
{
  move(value / 10, value % 10);
}

void TowersOfHanoi::print()
{
  for (size_t i = 0; i < NumberOfTowers; ++i)
  {
    std::cout << "tower_" << i + 1 << ":";
    
    if (towers_[i].empty())
    {
      std::cout << " empty";
    } 
    else 
    {
      for (const auto& j : towers_[i])
      {
        std::cout << " " << j;
      }
    }

    std::cout << "\n";
  }
}
