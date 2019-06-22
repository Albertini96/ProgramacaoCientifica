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
    
    DynamicQueue();
    ~DynamicQueue();
    
    bool enqueue(int a);
    int dequeue();
    bool isQueueEmpty();
    void front();
    void test();
};

#endif /* DynamicQueue_hpp */
