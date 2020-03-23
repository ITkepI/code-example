#ifndef MANAGER_CPA_HPP
#define MANAGER_CPA_HPP

#include <map>

class Manager
{
public:
  struct member_t
  {
    std::string name;
    size_t monthsLeft;
  };

  Manager() = default;

  void create(size_t id, const std::string& name);
  void remove(size_t id);
  void extend(size_t id, size_t months);
  void cancel(size_t id);

  void print();

private:
  std::map<size_t, member_t> subscriptions_;
};

#endif
