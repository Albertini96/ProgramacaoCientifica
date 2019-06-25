//
//  LDE.cpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#include "LDE.hpp"

//Constructors and destructors
LDE::LDE(){
    
    this->firstNode = nullptr;
    this->numberOfNodes = 0;
    
};

LDE::~LDE(){};

//Methods

//Return whether the list is empty
bool LDE::isEmpty(){
    return this->numberOfNodes == 0 ? true : false;
}

//Prints all elements of list
void LDE::showList(){
    
    if(!this->isEmpty()){
        Node* current = firstNode;
        
        do{
            std::cout<<current->getContent()<<std::endl;
            current = current->getNextNode();
        }while(current != nullptr);
    }
    
}

//Insert a node on the front of list
bool LDE::insertNodeFront(int a){
    
    bool ret = false;
    
    if(this->isEmpty()){
        
        Node* firstN = nullptr;
        
        try {
            firstN = new Node(a);
        } catch (std::exception& e) {
            std::ios_base::failure(e.what());
        }
        
        this->firstNode = firstN;
        this->numberOfNodes++;
        
    }else{
        
        Node* newNode = nullptr;
        
        try {
            newNode = new Node(a, this->firstNode);
        } catch (std::exception& e) {
            std::ios_base::failure(e.what());
        }
        
        this->firstNode = newNode;
        this->numberOfNodes++;
    }
    
    return ret;
}

//Insert a node on the back of list
bool LDE::insertNodeBack(int a){
    bool ret = false;
    
    if(this->isEmpty()){
        
        Node* firstN = nullptr;
        
        try {
            firstN = new Node(a);
        } catch (std::exception& e) {
            std::ios_base::failure(e.what());
        }
        
        this->firstNode = firstN;
        this->numberOfNodes++;
        
    }else{
        
        Node* current = firstNode;
        Node* newNode = nullptr;
        
        try {
            newNode = new Node(a);
        } catch (std::exception& e) {
            std::ios_base::failure(e.what());
        }
        
        while(current->getNextNode() != nullptr){
            current = current->getNextNode();
        };
        
        current->setNextNode(newNode);
        this->numberOfNodes++;
    }
    
    return ret;
}

//Remove a node from front of list
int LDE::removeFrontNode(){
    
    int ret = 0;
    
    if(!this->isEmpty()){
        if(numberOfNodes == 1){
            
            ret = this->firstNode->getContent();
            
            delete this->firstNode;
            this->firstNode = nullptr;
            this->numberOfNodes--;
            
        }else{
            Node* firstNode = this->firstNode;
            Node* secondNode = nullptr;
            
            ret = this->firstNode->getContent();
            
            secondNode = firstNode->getNextNode();
            this->firstNode = secondNode;
            
            delete firstNode;
            this->numberOfNodes--;
            
        }
    }
    
    return ret;
}

//Remove a node from back of list
int LDE::removeBackNode(){
    
    int ret = 0;
    
    if(!this->isEmpty()){
        if(numberOfNodes == 1){
            
            ret = this->firstNode->getContent();
            
            delete this->firstNode;
            this->firstNode = nullptr;
            this->numberOfNodes--;
            
        }else{
            Node* lastNode = firstNode;
            Node* lastlastNode = nullptr;
            
            do{
                lastlastNode = lastNode;
                lastNode = lastNode->getNextNode();
            }while(lastNode->getNextNode() != nullptr);
            
            ret = lastNode->getContent();
            
            lastlastNode->setNextNode(nullptr);
            
            delete lastNode;
            this->numberOfNodes--;
        }
    }
    
    return ret;
}

//Prints the back element of list on console
void LDE::peekBack(){
    
    if(this->isEmpty()){
        std::cout<< "List is empty."<< std::endl;
    }else{
        Node* lastNode = firstNode;
        
        while(lastNode->getNextNode() != nullptr){
            lastNode = lastNode->getNextNode();
        }
        
        std::cout<< "Back of list value: " <<lastNode->getContent() << std::endl;
    }
    
}

//Prints the front element of list on console
void LDE::peekFront(){
    if(this->isEmpty()){
        std::cout<< "List is empty."<< std::endl;
    }else{
        std::cout<< "Front of list value: " <<this->firstNode->getContent() << std::endl;
    }
}
