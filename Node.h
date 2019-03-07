#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

struct Node {
  Node* left = NULL;
  Node* right = NULL;
  Node* parent = NULL;
  int number = 0; 
};
#endif
