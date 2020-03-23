#include "network.hpp"

#include <iostream>

int main()
{
  Network::ip_address ip1{};
  Network::ip_address ip2{};
  Network::ip_address ip3{};
  Network::ip_address ip4{};
  Network::ip_address ip5{};

  std::cin >> ip1.data >> ip2.data >> ip3.data >> ip4.data >> ip5.data;

  Network network1(std::vector<Network::ip_address>{ip1, ip2, ip3});
  Network network2(std::vector<Network::ip_address>{ip3, ip4, ip5});

  std::cout << "Network 1:\n";
  network1.print();
  std::cout << "Network 2:\n";
  network2.print();

  return 0;
}
