#ifndef BINARY_TREE_CPA_HPP
#define BINARY_TREE_CPA_HPP

#include <memory>
#include <vector>

class BinaryTree
{
public:
  using tree_ptr = std::shared_ptr<BinaryTree>;
  
  BinaryTree();
  BinaryTree(int element);
  virtual ~BinaryTree() = default;

  virtual void createVector(std::vector<int>&);

  template <typename TreeType>
  void add(int element);

protected:
  bool isEmpty_;

  int value_;
  tree_ptr left_;
  tree_ptr right_;
};

template <typename TreeType>
void BinaryTree::add(int element)
{
  if (isEmpty_)
  {
    value_ = element;
    isEmpty_ = false;
  }
  else
  {
    if (element < value_)
    {
      if (!left_)
      {
        left_ = std::make_shared<TreeType>();
      }
      left_->add<TreeType>(element);
    }
    else
    {
      if (!right_)
      {
        right_ = std::make_shared<TreeType>();
      }
      right_->add<TreeType>(element);
    }
  }
}

#endif
