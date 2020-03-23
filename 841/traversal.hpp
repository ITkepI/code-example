#ifndef TRAVERSAL_CPA_HPP
#define TRAVERSAL_CPA_HPP

#include <ostream>

#include "binary-tree.hpp"

class Inorder : public BinaryTree
{
public:
  Inorder() : BinaryTree() { };
  Inorder(int element) : BinaryTree(element) { };

  void createVector(std::vector<int>& v) override;

  int operator [](size_t index);

  friend std::ostream& operator <<(std::ostream& output, Inorder& tree);
};

class Postorder : public BinaryTree
{
public:
  Postorder() : BinaryTree() { };
  Postorder(int element) : BinaryTree(element) { };

  void createVector(std::vector<int>& v) override;

  int operator [](size_t index);

  friend std::ostream& operator <<(std::ostream& output, Postorder& tree);
};

class Preorder : public BinaryTree
{
public:
  Preorder() : BinaryTree() { };
  Preorder(int element) : BinaryTree(element) { };

  void createVector(std::vector<int>& v) override;

  int operator [](size_t index);

  friend std::ostream& operator <<(std::ostream& output, Preorder& tree);
};

#endif
