/******************************************************************************
Kevin Miller
Project 3 
6/11/23
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Grocery.h"
using namespace std;
// Begin simply calls DisplayMenu in a while loop until user wishes to quit
void Grocery::Begin(){
    while(1){
        DisplayMenu();
    }
}
/*
DisplayMenu displays the menu to user. It also handles the logic based on user
input. Depending on which option the user selects, display menu logic will call 
respective function.
*/
void Grocery::DisplayMenu(){
    cout << "**********MENU**********" << endl;
    cout << "1. Get Item Frequency" << endl;
    cout << "2. Display Frequency of All Items" << endl;
    cout << "3. Display Frequency of All Items Using Histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "************************" << endl;
    
    cin >> userOption;
    
    if (userOption == 1){
        OptionOne();
    } 
    else if (userOption == 2){
        OptionTwo();
    }
    else if (userOption == 3){
        OptionThree();
    }
    else if (userOption == 4){
        cout << "Goodbye!" << endl;
        exit(0);
    }
    else {
        cout << "ERROR: Please only enter digits 1-4" << endl;
    }
    
}
/*
OptionOne prompts user to enter a produce item. Option one will then count the 
number of times that produce item is contained in our map named item and display 
to user. If it is not found will display to user "not found".
*/
void Grocery::OptionOne(){
    cout << "Please enter item name." << endl;
    cin >> itemName;
    if (item.count(itemName) > 0) {
        cout << "Frequncy: " << item.at(itemName) << endl;
    }
    else {
        cout << itemName << " not found." << endl;
    }
}
// OptionTwo prints out our entire map item to user.
void Grocery::OptionTwo(){
    for (auto produce : item) {
        cout << produce.first << " " << produce.second << endl;
    }
}
//OptionThree prints out our entire map item but instead of displaying number
//it will display a histogram using the * char.
void Grocery::OptionThree(){
    for (auto produce : item) {
        cout << produce.first << " ";
        for (int i = 0; i < produce.second; ++i) {
            cout <<"*";
        }
        cout << endl;
    }
}
/*
HandleFile opens our input file and creates a new file named frequency.dat to 
hold our data. The user doesnt need to do anything for this to happen and will 
happen prior to Begin being called. This is important because HandleFile fills
map item for us to be used in other functions. After populating our map it will
display organized list to frequency.dat for later use. Closes both files.
*/
void Grocery::HandleFile(){
    inFS.open("CS210_Project_Three_Input_File.txt");
    if(!inFS.is_open()) {
        cout << "Could not open CS210_Project_Three_Input_File.txt" << endl;
    }
    
    outFS.open("frequency.dat");
    if (!outFS.is_open()) {
        cout << "Could not open frequency.dat" << endl;
    }
    
    while (inFS >> itemName) {
            ++item[itemName];
    } 
    for (auto produce : item) {
            outFS << produce.first << " " << produce.second << endl;
    }
    inFS.close();
    outFS.close();
}
    
    
