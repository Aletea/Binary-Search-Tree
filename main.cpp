#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Tree.h"
#include <stdlib.h> //for char->int conversion 

int main() {
  //get file/manual input
  cout << "would you like to use a file or manual input? (enter 'file' for file, and 'manual' for manual input" << endl;
  char input[80];
  cin.get(input, 80);
  cin.get();
  //check for valid file input
  while (strcmp(input,"file") != 0 && strcmp(input, "manual") != 0) {
    cout << "invalid input" << endl;
    cin.get(input, 80);
    cin.get();
  }
  //keeps track of numbers
  int list[200];
  int index = 0;
  //if file
  if (strcmp(input, "file") == 0) {
    //get file path
    cout << "enter file path" << endl;
    char newFilePath[100];
    cin.get(newFilePath, 100);
    cin.get();
    //GET DIRECTORY
    ifstream textFile;
    textFile.open(newFilePath);
    while (!textFile) {
      cout << "File Destination Not Found. Please Reneter" << endl;
      cin.get(newFilePath, 100);
      cin.get();
      textFile.open(newFilePath);
    }
    //get file length
      textFile.seekg(0, textFile.end);
      int length = textFile.tellg();
      textFile.seekg(0, textFile.beg);
      //run through new file and add to int array list
      char charArray[100];
      for (int i = 0; i < length; i++) {
	charArray[i] = textFile.get();
      }
      //convert characters to numbers and add to list
      for (int i = 0; i < length; i++) {
	char number[10];
	int count = 0;
	while (charArray[i] != ' ' && i < length) {
	  number[count] = charArray[i];
	  i++;
	  count++;
	}
	number[count] = '\0';
	int newNum = atoi(number);
	list[index] = newNum;
	index++;
      }
  }
  //if manual input
  else {
    bool stillEntering = true;
    //continuously get number input and add it to the list until user says they don't wanna keep entering numbers
    while (stillEntering == true) {
    cout << "Input Number: ";
    int Number;
    cin >> Number;
    cin.ignore();
    list[index] = Number;
    index++;
    cout << "Would you like to enter again? (y/n) ";
    char input2[10];
    cin.get(input2, 10);
    cin.get();
    if (strcmp(input2, "n") == 0) {
	stillEntering = false;
    }
    }
  }
  //create binary search tree
  cout << "Index: " << index << endl;
  Tree* binaryTree = new Tree();
  for (int i = 0; i < index; i++) {
    Node* newNode = new Node();
    newNode->number = list[i];
    binaryTree->insert(newNode);
  }
  bool stillGoing = true;
  while (stillGoing == true) {
    cout << "Would you like to remove, display, or quit?" << endl;
    char action[20];
    cin.get(action, 20);
    cin.get();
    while (strcmp(action, "remove") != 0 && strcmp(action, "display") != 0 && strcmp(action, "quit") != 0) {
      cout << "Invalid Input. Type one of the options" << endl;
      cin.get(action,20);
      cin.get();
    }
    if (strcmp(action, "remove") == 0) {
      cout << "Please type the number you would like to remove" << endl;
      int number;
      cin >> number;
      cin.ignore();
      binaryTree->remove(number);
    }
    else if(strcmp(action, "display") == 0) {
      if (binaryTree->getHead() == NULL) {
	cout << "No tree to print" << endl;
      }
      else {
	binaryTree->display(binaryTree->getHead(), 1);
      }
    }
    else {
      stillGoing = false;
    }
  }
  
  return 0;
}
