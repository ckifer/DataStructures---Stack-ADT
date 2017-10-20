//
//  stackADT.hpp
//  ProgAssignTwo
//
//  Created by Coltin Kifer on 10/18/17.
//  Copyright © 2017 Coltin Kifer. All rights reserved.
//

#ifndef stackADT_hpp
#define stackADT_hpp

#include <stdio.h>

template <class ItemType>
class stackADT {
    
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack() const = 0;
    virtual bool isFullStack() const = 0;
    virtual void push(const ItemType&) = 0;
    virtual ItemType top() const = 0;
    virtual void pop() = 0;
};

#endif /* stackADT_hpp */
