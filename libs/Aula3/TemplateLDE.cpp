//
//  TemplateLDE.hpp
//  Aula2
//
//  Created by Guilherme Albertini on 22/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef TemplateLDE_hpp
#define TemplateLDE_hpp

#include <stdio.h>
#include "TemplateNode.cpp"
#include <iostream>

template <typename T>
class TemplateLDE {
    
private:
    TemplateNode<T>* firstNode;
    int numberOfNodes;
    
public:
    
    //Empty constructor
    TemplateLDE();
    //Empty destructor
    ~TemplateLDE();
    
    //Return whether the list is empty
    bool isEmpty(){
        return this->numberOfNodes == 0 ? true : false;
    }
    
    //Insert a TemplateNode on the front of list
    bool insertNodeFront(T a){
        
        bool ret = false;
        
        if(this->isEmpty()){
            
            TemplateNode<T>* firstN = nullptr;
            
            try {
                firstN = new TemplateNode<T>(a);
            } catch (std::exception& e) {
                std::ios_base::failure(e.what());
            }
            
            this->firstNode = firstN;
            this->numberOfNodes++;
            
        }else{
            
            TemplateNode<T>* newNode = nullptr;
            
            try {
                newNode = new TemplateNode<T>(a, this->firstNode);
            } catch (std::exception& e) {
                std::ios_base::failure(e.what());
            }
            
            this->firstNode = newNode;
            this->numberOfNodes++;
        }
        
        return ret;
    }
    
    //Insert a TemplateNode on the back of list
    bool insertNodeBack(T a){
        bool ret = false;
        
        if(this->isEmpty()){
            
            TemplateNode<T>* firstN = nullptr;
            
            try {
                firstN = new TemplateNode<T>(a);
            } catch (std::exception& e) {
                std::ios_base::failure(e.what());
            }
            
            this->firstNode = firstN;
            this->numberOfNodes++;
            
        }else{
            
            TemplateNode<T>* current = firstNode;
            TemplateNode<T>* newNode = nullptr;
            
            try {
                newNode = new TemplateNode<T>(a);
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
    
    //Remove a TemplateNode from front of list
    T removeFrontNode(){
        
        T ret = NULL;
        
        if(!this->isEmpty()){
            if(numberOfNodes == 1){
                
                ret = this->firstNode->getContent();
                
                delete this->firstNode;
                this->firstNode = nullptr;
                this->numberOfNodes--;
                
            }else{
                TemplateNode<T>* firstNode = this->firstNode;
                TemplateNode<T>* secondNode = nullptr;
                
                ret = this->firstNode->getContent();
                
                secondNode = firstNode->getNextNode();
                this->firstNode = secondNode;
                
                delete firstNode;
                this->numberOfNodes--;
                
            }
        }
        
        return ret;
    }
    
    //Remove a TemplateNode from back of list
    T removeBackNode(){
        
        T ret = NULL;
        
        if(!this->isEmpty()){
            if(numberOfNodes == 1){
                
                ret = this->firstNode->getContent();
                
                delete this->firstNode;
                this->firstNode = nullptr;
                this->numberOfNodes--;
                
            }else{
                TemplateNode<T>* lastNode = firstNode;
                TemplateNode<T>* lastlastNode = nullptr;
                
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

};


#endif /* TemplateLDE_hpp */
