//
//  Node.hpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>

class Node {
private:
    Node* nextNode;
    int content;
    
public:
    
    //Constructor and Destructors
    Node();
    Node(int a);
    Node(int a, Node* ne);
    Node(Node* ne);
    ~Node();
    
    //Get pointer to next linked node
    Node* getNextNode();
    //Set the pointer to next linked node
    bool setNextNode(Node* next);
    //Return content of node
    int getContent();
    
};

#endif /* Node_hpp */
