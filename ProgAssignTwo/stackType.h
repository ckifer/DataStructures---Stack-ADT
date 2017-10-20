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

template <class ItemType>
class stackType : public stackADT<ItemType> {
public:
    const stackType<ItemType>& operator=(const stackType<ItemType>&);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const ItemType&);
    ItemType top() const;
    void pop();
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
ItemType stackType<ItemType>::top(){
  assert(stackTop != 0);
  return list[stackTop-1];
}

template <class ItemType>
void stackType<ItemType>::pop(){
  if(!isEmptyStack()){
    stackTop--;
  } else{
    cout << "The stack is empty"; << endl;
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
  if(!this != &other){
    copyStack(other);
  }
  return *this;
}


#endif /* stackType_h */
