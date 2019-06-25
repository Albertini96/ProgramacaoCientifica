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
    
    std::cout<< "Pushing number 1 " << std::endl;
    this->push(1);
    std::cout<< "Pushing number 2 " << std::endl;
    this->push(2);
    std::cout<< "Pushing number 3 " << std::endl;
    this->push(3);
    std::cout<< "Pushing number 4 " << std::endl;
    this->push(4);
    
    this->top();
    
    std::cout<< "Poppin number " << this->pop() << std::endl;
    std::cout<< "Poppin number " << this->pop() << std::endl;
    std::cout<< "Poppin number " << this->pop() << std::endl;
    
    this->top();
    
    std::cout<< "-------------------------------" << std::endl<< std::endl;
}
