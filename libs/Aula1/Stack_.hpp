//
//  Stack.hpp
//  StackFila
//
//  Created by Guilherme Albertini on 11/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

class Stack {

private:
    int stackSize;
    int qtElements;
    int* stackContent;
    
public:
    
    Stack(int stackSize = 50, int qtElements = 0, int* stackContent = new int[50]{});
    ~Stack();
    void showContent();
    int push(int el);
    int pop();
};

#endif /* Stack_hpp */
