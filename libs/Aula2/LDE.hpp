//
//  LDE.hpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef LDE_hpp
#define LDE_hpp

#include <stdio.h>
#include "Node.hpp"
#include <iostream>


class LDE {
    
private:
    Node* firstNode;
    int numberOfNodes;
    
public:
    
    //Empty constructor
    LDE();
    //Empty destructor
    ~LDE();
    
    //Is list empty
    bool isEmpty();
    //Print list
    void showList();
    //Insert node on the front of list
    bool insertNodeFront(int a);
    //Insert node on the back of list
    bool insertNodeBack(int a);
    //Remove front node
    int removeFrontNode();
    //Remove back node
    int removeBackNode();
    //Peek front
    void peekFront();
    //Peek back
    void peekBack();
};


#endif /* LDE_hpp */
