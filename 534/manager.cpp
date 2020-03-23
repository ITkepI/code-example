#include "manager.hpp"

#include <algorithm>
#include <iostream>

const std::string InvMsg = "Cannot perform this operation: ";

void Manager::create(size_t id, const std::string& name)
{
  if (id == 0)
  {
    std::cout << InvMsg << "ID must be non-zero.\n";
  }

  auto it = subscriptions_.find(id);

  if (it != subscriptions_.end())
  {
    std::cout << InvMsg << "User with such id is already present.\n";
  }

  subscriptions_.emplace(id, member_t{name, 0});
}

void Manager::remove(size_t id)
{
  auto it = subscriptions_.find(id);

  if (it == subscriptions_.end())
  {
    std::cout << InvMsg << "User with such id does not exist.\n";
  }

  subscriptions_.erase(it);
}

void Manager::extend(size_t id, size_t months)
{
  auto it = subscriptions_.find(id);

  if (it == subscriptions_.end())
  {
    std::cout << InvMsg << "User with such id does not exist.\n";
  }

  it->second.monthsLeft += months;
}

void Manager::cancel(size_t id)
{
  auto it = subscriptions_.find(id);

  if (it == subscriptions_.end())
  {
    std::cout << InvMsg << "User with such id does not exist.\n";
  }

  it->second.monthsLeft = 0;
}

void Manager::print()
{
  if (subscriptions_.empty())
  {
    std::cout << "No members in the system.\n";
  }

  std::for_each(subscriptions_.begin(), subscriptions_.end(),
      [](const auto& e)
        { 
          std::cout << "Member " << e.first << " : "
                    << e.second.name
                    << ", subscription valid for "
                    << e.second.monthsLeft << " months.\n";
        });
}
