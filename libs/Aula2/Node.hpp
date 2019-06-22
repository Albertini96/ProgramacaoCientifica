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
    
    Node();
    Node(int a);
    Node(int a, Node* ne);
    Node(Node* ne);
    ~Node();
    
    
    Node* getNextNode();
    bool setNextNode(Node* next);
    int getContent();
    
};

#endif /* Node_hpp */
