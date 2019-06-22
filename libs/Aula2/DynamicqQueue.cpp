//
//  DynamicQueue.cpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#include "DynamicQueue.hpp"

//Constructors and destructors

DynamicQueue::DynamicQueue() : LDE(){};
DynamicQueue::~DynamicQueue(){};

//Methods

bool DynamicQueue::enqueue(int a){
    return this->insertNodeBack(a);
}

int DynamicQueue::dequeue(){
    return this->removeFrontNode();
}

bool DynamicQueue::isQueueEmpty(){
    return this->isEmpty();
}

void DynamicQueue::front(){
    this->peekFront();
}

void DynamicQueue::test(){
    std::cout<< "Testing DynamicQueue: " << std::endl;
    
    this->enqueue(1);
    this->enqueue(2);
    this->enqueue(3);
    this->enqueue(4);
    
    this->front();
    
    this->dequeue();
    this->dequeue();
    
    this->front();
    
    std::cout<< "-------------------------------" << std::endl;
}
