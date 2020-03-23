#ifndef TOWERS_OF_HANOI_HPP
#define TOWERS_OF_HANOI_HPP

#include <array>
#include <deque>
#include <exception>

class TowersOfHanoi
{
public:
  struct towers_exception : public std::exception
  {
    virtual const char* what() = 0;
  };

  struct out_of_range : public towers_exception
  {
    const char* what() { return "One or both towers are not in 1-3 range."; };
  };

  struct incorrect_size : public towers_exception
  {
    const char* what() { return "The disk moved is bigger than the one in the target rod."; };
  };

  struct empty_rod : public towers_exception
  {
    const char* what() { return "There are no disks on the source rod."; };
  };

  TowersOfHanoi();

  void move(int from, int to);
  void move(int value);

  void print();

private:
  static const size_t NumberOfTowers = 3;
    
  std::array<std::deque<int>, NumberOfTowers> towers_;
};

#endif
