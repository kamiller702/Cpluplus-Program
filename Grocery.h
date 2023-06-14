/******************************************************************************
Kevin Miller
Project 3 
6/11/23
*******************************************************************************/
#ifndef GROCERY_H
#define GROCERY_H

#include <map>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Grocery {
  public:
    void Begin(); // please refer to Grocery.cpp for definition
    void DisplayMenu(); // please refer to Grocery.cpp for definition
    void OptionOne(); // please refer to Grocery.cpp for definition
    void OptionTwo(); // please refer to Grocery.cpp for definition
    void OptionThree(); // please refer to Grocery.cpp for definition
    void HandleFile(); // please refer to Grocery.cpp for definition
    
  private:
    string itemName = "None"; // string for produce item
    int itemCount =0; // int for item count
    int userOption =0; // int for user logic during menu selection
    ifstream inFS; // declares input File Stream
    ofstream outFS; // declares output File Stream
    map<string, int> item; // map item to hold key and values
};
#endif