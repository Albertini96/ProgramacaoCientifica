//
//  DynamicStack.cpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#include "DynamicStack.hpp"

//Constructors and destructors

DynamicStack::DynamicStack():LDE(){};
DynamicStack::~DynamicStack(){};

//Methods

bool DynamicStack::push(int a){
    return this->insertNodeBack(a);
}

int DynamicStack::pop(){
    return this->removeBackNode();
}

bool DynamicStack::isStackEmpty(){
    return this->isEmpty();
}

void DynamicStack::top(){
    this->peekBack();
}

void DynamicStack::test(){
    std::cout<< "Testing DynamicStack: " << std::endl;
    
    this->push(1);
    this->push(2);
    this->push(3);
    this->push(4);
    
    this->top();
    
    this->pop();
    this->pop();
    this->pop();
    
    this->top();
    
    std::cout<< "-------------------------------" << std::endl<< std::endl;
}
