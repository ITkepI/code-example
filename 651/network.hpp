#ifndef NETWORK_CPA_HPP
#define NETWORK_CPA_HPP

#include <string>
#include <vector>

class Network
{
public:
  struct ip_address
  {
    std::string data;
  };

  Network() = default;
  Network(const std::vector<ip_address>& array);
  
  void add(const ip_address& address);

  void print();

private:
  std::vector<ip_address> array_;
};

#endif
