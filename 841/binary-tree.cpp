#include "binary-tree.hpp"

BinaryTree::BinaryTree() :
  isEmpty_(true),
  value_()
{ }

BinaryTree::BinaryTree(int element) :
  isEmpty_(false),
  value_(element)
{ }

void BinaryTree::createVector(std::vector<int>&)
{ }
