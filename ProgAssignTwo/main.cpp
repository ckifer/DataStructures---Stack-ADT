//
//  main.cpp
//  ProgAssignTwo
//
//  Created by Coltin Kifer on 10/17/17.
//  Copyright © 2017 Coltin Kifer. All rights reserved.
//

#include <iostream>
#include "stackType.hpp"

using namespace std;

// function prints stack forwards using recursion
void printForwards(stackType<char> stack);

//main function
int main(int argc, const char * argv[]) {
   //initialize the stack
   stackType<char> stack(50);
   stack.initializeStack();
   int i = 0;
   char letter;
   cout << "Please enter 10 letters in alpabetical order.  Enter the minus sign \'-\' if you wish to remove the"
            " previous character from the list." << endl;

  //check the 10 characters for flag '-' that tells to erase previous entry.  Else keep adding letters to the stack.
   while (i < 10) {
     cout << "Please enter a letter: ";
     cin >> letter;
     if(letter == '-'){
       stack.pop();
     } else{
       stack.push(letter);
       i++;
     }
   }
   //print the stack
   printForwards(stack);
   cout << endl;
}

void printForwards(stackType<char> stack){
  if(stack.isEmptyStack()){
    return;
  } else{
    char temp = stack.top();

    stack.pop();
    printForwards(stack);

    cout << temp << " ";

  }
}
