#include <iostream>
#include <sstream>

#include "manager.hpp"

const std::string InvMsg = "Cannot perform this operation: ";

int main()
{
  Manager manager;

  manager.print();
  std::string line;
  while (std::getline(std::cin, line))
  {
    std::stringstream input(line);

    std::string command;
    input >> command;

    if (command == "create")
    {
      size_t id;
      input >> id;

      if (input.fail())
      {
        std::cout << InvMsg << "Invalid create parameters.\n";
      }

      std::string name;
      std::getline(input >> std::ws, name);

      if (name.empty())
      {
        std::cout << InvMsg << "Invalid create parameters.\n";
      }

      manager.create(id, name);
    }
    else if (command == "delete")
    {
      size_t id;
      input >> id;

      if (!input.eof() && input.fail())
      {
        std::cout << InvMsg << "Invalid ID.\n";
      }

      std::string data;
      std::getline(input, data);

      if (!data.empty())
      {
        std::cout << InvMsg << "Too much data for the command.\n";
      }
      
      manager.remove(id);
    }
    else if (command == "extend")
    {
      size_t id;
      input >> id;

      if (input.fail())
      {
        std::cout << InvMsg << "Invalid extend parameters.\n";
      }

      size_t months;
      input >> months;

      if (!input.eof() && input.fail())
      {
        std::cout << InvMsg << "Invalid months to extend.\n";
      }

      std::string data;
      std::getline(input, data);

      if (!data.empty())
      {
        std::cout << InvMsg << "Too much data for the command.\n";
      }
      
      manager.extend(id, months);
    }
    else if (command == "cancel")
    {
      size_t id;
      input >> id;

      if (!input.eof() && input.fail())
      {
        std::cout << InvMsg << "Invalid ID.\n";
      }

      std::string data;
      std::getline(input, data);

      if (!data.empty())
      {
        std::cout << InvMsg << "Too much data for the command.\n";
      }
      
      manager.cancel(id);
    } 
    else if (command == "quit")
    {
      return 0;
    }
    else
    {
      std::cout << InvMsg << "Invalid command.\n";
    }

    manager.print();
  }

  return 0;
}
