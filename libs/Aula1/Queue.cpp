//
//  Queue.cpp
//  PilhaFila
//
//  Created by Guilherme Albertini on 17/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#include "Queue.hpp"
#include <iostream>

//Queue Destructor
Queue::~Queue(){};

//Queue Constructor
Queue::Queue(int qs, int qe, int* qc) : queueSize(qs), qtElements(qe), queueContent(qc)  {
    
    //If number of elements in initialization is not 0 then initialize all empty with -1
    if(qe != 0){
        for(int i = qe; i<qs; i++){
            queueContent[i] = -1;
        }
    }//If number of elements in initialization is 0 then initialize all with -1
    else{
        for(int i = 0; i<qs; i++){
            queueContent[i] = -1;
        }
    }
    
}

//Iterate through the queue printing the values
void Queue::showContent(){

    for(int i = 0; i<qtElements; i++){
        std::cout<< queueContent[i];
        std::cout<< std::endl;
    }
    
}

//Insert element in the queue, return -1 if full or 0 if successful
int Queue::enqueue(int el){
    int ret = 0;
    
    if(qtElements < queueSize){
        queueContent[qtElements] = el;
        qtElements++;
    }else{
        ret = -1;
    }
    
    return ret;
}

//Remove element from queue, return -1 if empty or the dequeued number
int Queue::dequeue(){
    int ret = 0;
    int i;
    
    if(qtElements != 0){
        ret = queueContent[0];
        
        for(i = 0; i < qtElements; i++){
            if(queueContent[i + 1] == -1){
                break;
            }else{
                queueContent[i] = queueContent[i + 1];
            }
        }
        
        qtElements--;
    }else{
        ret = -1;
    }
    
    return ret;
}
