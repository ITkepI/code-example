#include "network.hpp"

#include <iostream>

Network::Network(const std::vector<Network::ip_address>& array) :
  array_(array)
{ }

void Network::add(const ip_address& address)
{
  array_.push_back(address);
}

void Network::print()
{
  for (const auto i : array_)
  {
    std::cout << i.data << '\n';
  }
}
