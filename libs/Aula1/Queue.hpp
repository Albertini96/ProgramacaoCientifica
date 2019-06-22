//
//  Queue.hpp
//  PilhaFila
//
//  Created by Guilherme Albertini on 17/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

class Queue {
    
private:
    int queueSize;
    int qtElements;
    int* queueContent;
    
public:
    
    Queue(int queueSize = 50, int qtElements = 0, int* queueContent = new int[50]{});
    ~Queue();
    void showContent();
    int enqueue(int el);
    int dequeue();
};

#endif /* Queue_hpp */
