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
    
    DynamicStack();
    ~DynamicStack();
    
    bool push(int a);
    int pop();
    bool isStackEmpty();
    void top();
    void test();
};

#endif /* DynamicStack_hpp */
