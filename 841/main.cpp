#include <iostream>

#include "traversal.hpp"

int main()
{
  Inorder in_tree{};
  Postorder post_tree{};
  Preorder pre_tree{};

  int num;
  while (std::cin >> num)
  {
    in_tree.add<Inorder>(num);
    post_tree.add<Postorder>(num);
    pre_tree.add<Preorder>(num);
  }

  std::cout << in_tree << "\n" << post_tree << "\n" << pre_tree << "\n";

  return 0;
}
