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
    
    std::cout<< "Enqueuing number 1 " << std::endl;
    this->enqueue(1);
    std::cout<< "Enqueuing number 2 " << std::endl;
    this->enqueue(2);
    std::cout<< "Enqueuing number 3 " << std::endl;
    this->enqueue(3);
    std::cout<< "Enqueuing number 4 " << std::endl;
    this->enqueue(4);
    
    this->front();
    
    
    std::cout<< "Dequeued number " << this->dequeue() << std::endl;
    std::cout<< "Dequeued number " << this->dequeue() << std::endl;
    
    this->front();
    
    std::cout<< "-------------------------------" << std::endl;
}
