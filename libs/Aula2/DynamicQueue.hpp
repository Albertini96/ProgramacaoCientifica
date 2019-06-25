//
//  DynamicQueue.hpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef DynamicQueue_hpp
#define DynamicQueue_hpp

#include "LDE.hpp"

class DynamicQueue : public LDE{
public:
    
    //Constructor and Destructors
    DynamicQueue();
    ~DynamicQueue();
    
    //Enqueue an element on queue
    bool enqueue(int a);
    //Dequeue an element on queue
    int dequeue();
    //Check whether the queue is empty
    bool isQueueEmpty();
    //Print front element on console
    void front();
    //Perform basic queue operations
    void test();
};

#endif /* DynamicQueue_hpp */
