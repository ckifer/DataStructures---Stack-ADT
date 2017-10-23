//
//  stackType.h
//  ProgAssignTwo
//
//  Created by Coltin Kifer on 10/18/17.
//  Copyright © 2017 Coltin Kifer. All rights reserved.
//

#ifndef stackType_h
#define stackType_h

#include <iostream>
#include <cassert>
#include "stackADT.hpp"

using namespace std;

//Array implementation of a stack
//functions defined and implemented in stackType.hpp
template <class ItemType>
class stackType : public stackADT<ItemType> {
public:

    const stackType<ItemType>& operator=(const stackType<ItemType>&);
    //initialize an empty stack
    void initializeStack();
    //check if stack is empty
    bool isEmptyStack() const;
    //check if stack is full
    bool isFullStack() const;
    //push an item onto the stack
    void push(const ItemType&);
    //look at the top value of the stack
    ItemType top() const;
    //pop an item off of the stack
    void pop();
    //constructors/destructor
    stackType(int stackSize = 100);
    stackType(const stackType<ItemType>&);
    ~stackType();
private:
  int maxStackSize;
  int stackTop;
  ItemType *list;
  void copyStack(const stackType<ItemType>&);
};

template <class ItemType>
void stackType<ItemType>::initializeStack(){
  stackTop = 0;
}

template <class ItemType>
bool stackType<ItemType>::isEmptyStack() const{
  return (stackTop == 0);
}

template <class ItemType>
bool stackType<ItemType>::isFullStack() const{
  return (stackTop == maxStackSize);
}

template <class ItemType>
void stackType<ItemType>::push(const ItemType& item){
  if(!isFullStack()){
    list[stackTop] = item;
    stackTop++;
  } else{
    cout << "The Stack is full" << endl;
  }
}

template <class ItemType>
ItemType stackType<ItemType>::top() const{
  assert(stackTop != 0);
  return list[stackTop-1];
}

template <class ItemType>
void stackType<ItemType>::pop(){
  if(!isEmptyStack()){
    stackTop--;
  } else{
    cout << "The stack is empty" << endl;
  }
}

template <class ItemType>
void stackType<ItemType>::copyStack(const stackType<ItemType>& other){
  delete   [] list;
  maxStackSize = other.maxStackSize;
  stackTop = other.stackTop;
  list = new ItemType[maxStackSize];
  for(int i = 0; i < stackTop; i++){
    list[i] = other.list[i];
  }
}

template <class ItemType>
stackType<ItemType>::stackType(int stackSize){
  if(stackSize == 0){
    cout << "Size must be positive.  Creating default size of 100";
  } else{
    maxStackSize = stackSize;
  }
  stackTop = 0;
  list = new ItemType[maxStackSize];
}

template <class ItemType>
stackType<ItemType>::~stackType(){
  delete [] list;
}

template <class ItemType>
stackType<ItemType>::stackType(const stackType<ItemType>& other){
  list = NULL;
  copyStack(other);
}

template <class ItemType>
const stackType<ItemType>& stackType<ItemType>::operator =(const stackType<ItemType>& other){
  if(this != &other){
    copyStack(other);
  }
  return *this;
}


#endif /* stackType_h */
