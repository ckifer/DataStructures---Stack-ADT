//
//  main.cpp
//  ProgAssignTwo
//
//  Created by Coltin Kifer on 10/17/17.
//  Copyright © 2017 Coltin Kifer. All rights reserved.
//

#include <iostream>
#include "stackType.h"

void test(stackType<int>);

int main(int argc, const char * argv[]) {
   stackType<int> stack(50), copyStack(50), dummyStack(100);
   stack.initializeStack();
   stack.push(12);
   stack.push(16);
   stack.push(36);
   stack.push(13);
   copyStack = stack;
   cout << "copyStack = ";
   while (!copyStack.isEmptyStack()) {
     cout << copyStack.top(); << " ";
     copyStack.pop();
   }
   cout << endl;
   copyStack = stack;
   test(stack);
   if(!stack.isEmptyStack()){
     cout << "Original stack is not empty." << endl
          << "Top element of original stack = " << copyStack.top() << endl;
   }
   dummyStack = stack;
   cout << "dummyStack = ";
   while(!dummyStack.isEmptyStack()){
     cout << dummyStack.top() << " ";
     dummyStack.pop();
   }
   cout << endl;
   system("PAUSE");
   return 0;
}

void test(stackType<int> other){
  if(!other.isEmptyStack()){
    cout << "Other is not empty" << endl
         << "top element of other is = "
         << other.top() << endl;
  }
}
