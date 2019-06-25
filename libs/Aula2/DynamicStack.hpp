//
//  DynamicStack.hpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef DynamicStack_hpp
#define DynamicStack_hpp

#include "LDE.hpp"

class DynamicStack : public LDE{
public:
    
    //Constructor and Destructors
    DynamicStack();
    ~DynamicStack();
    
    //Push a new element on the stack
    bool push(int a);
    //Pop the top element of the stack
    int pop();
    //Check if stack is empty
    bool isStackEmpty();
    //Prints top element on console
    void top();
    //Perform basic operations
    void test();
};

#endif /* DynamicStack_hpp */
