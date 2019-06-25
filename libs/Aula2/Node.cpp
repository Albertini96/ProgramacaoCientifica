//
//  Node.cpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#include "Node.hpp"

//Constructors and destructors
Node::Node():content(0), nextNode(nullptr){}
Node::Node(int a):content(a), nextNode(nullptr){}
Node::Node(int a, Node* ne):content(a), nextNode(ne){}
Node::Node(Node* ne):content(0), nextNode(ne){}
Node::~Node(){}

//Methods

Node* Node::getNextNode(){
    return this->nextNode;
};

int Node::getContent(){
    return this->content;
}

bool Node::setNextNode(Node* next){
    
    this->nextNode = next;
    return true;
};
