#include "traversal.hpp"

#include <algorithm>
#include <iterator>

void Inorder::createVector(std::vector<int>& v)
{
  if (left_)
  {
    left_->createVector(v);
  }

  v.push_back(value_);

  if (right_)
  {
    right_->createVector(v);
  }
}

int Inorder::operator [](size_t index)
{
  std::vector<int> v{};
  createVector(v);

  return v[index];
}

void Postorder::createVector(std::vector<int>& v)
{
  if (left_)
  {
    left_->createVector(v);
  }

  if (right_)
  {
    right_->createVector(v);
  }

  v.push_back(value_);
}

int Postorder::operator [](size_t index)
{
  std::vector<int> v{};
  createVector(v);

  return v[index];
}

void Preorder::createVector(std::vector<int>& v)
{
  v.push_back(value_);

  if (left_)
  {
    left_->createVector(v);
  }

  if (right_)
  {
    right_->createVector(v);
  }
}

int Preorder::operator [](size_t index)
{
  std::vector<int> v{};
  createVector(v);

  return v[index];
}

/*----Operators----*/

std::ostream& operator <<(std::ostream& output, Inorder& tree)
{
  std::vector<int> v{};
  tree.createVector(v);

  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(output, " "));

  return output;
}

std::ostream& operator <<(std::ostream& output, Postorder& tree)
{
  std::vector<int> v{};
  tree.createVector(v);

  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(output, " "));

  return output;
}

std::ostream& operator <<(std::ostream& output, Preorder& tree)
{
  std::vector<int> v{};
  tree.createVector(v);

  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(output, " "));

  return output;
}
