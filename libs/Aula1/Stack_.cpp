//
//  Stack.cpp
//  StackFila
//
//  Created by Guilherme Albertini on 11/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#include "./Stack.hpp"
#include <iostream>

//Stack Constructor
Stack::~Stack(){};

//Stack Destructor
Stack::Stack(int qs, int qe, int* qc) : stackSize(qs), qtElements(qe), stackContent(qc)  {
    
    //If number of elements in initialization is not 0 then initialize all empty with -1
    if(qe != 0){
        for(int i = qe; i<qs; i++){
            stackContent[i] = -1;
        }
    }//If number of elements in initialization is 0 then initialize all with -1
    else{
        for(int i = 0; i<qs; i++){
            stackContent[i] = -1;
        }
    }
    
}


void Stack::showContent(){
    
    for(int i = 0; i<qtElements; i++){
        std::cout<< stackContent[i];
        std::cout<< std::endl;
    }
    
}

int Stack::push(int el){
    int ret = 0;
    
    if(qtElements < stackSize){
        stackContent[qtElements] = el;
        qtElements++;
        ret = 0;
    }else{
        ret = -1;
    }
    
    return ret;
}

int Stack::pop(){
    int ret = 0;
    
    if(qtElements == 0){
        ret = -1;
    }else{
        ret = stackContent[qtElements - 1];
        qtElements--;
    }
    
    return ret;
}
