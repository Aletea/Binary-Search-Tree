#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Node.h"

using namespace std;

class Tree {
 public: 
  Tree();
  ~Tree();
  void insert(Node* newNode);
  void remove(int remNode);
  void display(Node* printNode, int height);
  Node* getHead();
private:
  Node* head;

};
#endif
