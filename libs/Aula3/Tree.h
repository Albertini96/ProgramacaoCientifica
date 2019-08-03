//
//  Tree.h
//  ProgramacaoCientifica
//
//  Created by Guilherme Albertini on 25/07/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include "TreeNode.h"
#include "TemplateDynamicQueue.h"
#include "TemplateDynamicStack.h"
#include "Puzzle.h"
#include <iostream>

template <typename T>
class Tree {
private:
    int numberOfNodes;
    TreeNode<T>* rootNode;
    TemplateDynamicStack<TreeNode<T>*>* dfsStack;
    TemplateDynamicQueue<TreeNode<T>*>* bfsQueue;
    
public:
    
    Tree():numberOfNodes(0),
            rootNode(nullptr),
            dfsStack(new TemplateDynamicStack<T>),
            bfsQueue(new TemplateDynamicQueue<T>){}
    
    Tree(T content){
        this->numberOfNodes = 1;
        this->dfsStack = new TemplateDynamicStack<TreeNode<T>*>();
        this->bfsQueue = new TemplateDynamicQueue<TreeNode<T>*>();
        TreeNode<T>* root = new TreeNode<T>();
        root->setContent(content);
        this->rootNode = root;
    }
    
    //Perform DFS tree traversal
    TreeNode<Puzzle>* dfs_traversal(T search){
        
        //Node that has the answer
        TreeNode<Puzzle>* ret = new TreeNode<Puzzle>();
        
        //Setting the root of tree on stack
        this->dfsStack->push(this->rootNode);
        
        //Declaring explored nodes list
        TemplateLDE<TreeNode<Puzzle>*>* explored = new TemplateLDE<TreeNode<Puzzle>*>();
        
        //Expanding tree
        while (!this->dfsStack->isEmpty()) {
            //Setting current node
            TreeNode<Puzzle>* currentNode = this->dfsStack->pop();
            
            //Inserting current node to explored nodes
            explored->insertNodeFront(currentNode);
            
            //Priting on console current state
            std::cout<<"============================"<<std::endl;
            std::cout<<"NODE BEING EXPLORED"<<std::endl;
            std::cout<<"NODE DEPTH > "<< currentNode->getDepth()<<std::endl;
            currentNode->getContent().printState();
            
            //If node has the answer stop, else create new possibilities
            if(search.equalTo(currentNode->getContent())){
                ret = currentNode;
                std::cout<<"============================"<<std::endl;
                std::cout<<"ANSWER FOUND!"<<std::endl;
                currentNode->getContent().printState();
                break;
            }else{
                
                //Obtaining possible moves
                TemplateLDE<Puzzle> children = currentNode->getContent().getPossibleMoves();
                
                std::cout<<"CHILDREN"<<std::endl;
                //Inserting possible moves as tree nodes
                while(!children.isEmpty()){
                    Puzzle temp = children.removeFrontNode();
                    temp.printState();
                    currentNode->insertChild(temp);
                }
                
                TemplateNode<TreeNode<T>*>* node_children_ptr = currentNode->getChildrenList()->getFirstNode();
                
                //ForEach child in children
                do{
                    TemplateNode<TreeNode<T>*>* stack_ptr = this->dfsStack->getFirstNode();
                    TemplateNode<TreeNode<T>*>* explored_ptr = explored->getFirstNode();
                    bool in_stack = false;
                    bool in_explored = false;
                    
                    //ForEach node in stack
                    if(stack_ptr != nullptr){
                        if(stack_ptr->getNextNode() == nullptr){
                            in_stack += node_children_ptr->getContent()->getContent().equalTo(stack_ptr->getContent()->getContent());
                        }else{
                            do{
                                in_stack += node_children_ptr->getContent()->getContent().equalTo(stack_ptr->getContent()->getContent());
                                stack_ptr = stack_ptr->getNextNode();
                            }while(stack_ptr != nullptr);
                        }
                    }
                    
                    //ForEach node in explored list
                    if(explored_ptr != nullptr){
                        if(explored_ptr->getNextNode() == nullptr){
                            in_explored += node_children_ptr->getContent()->getContent().equalTo(explored_ptr->getContent()->getContent());
                        }else{
                            do{
                                in_explored += node_children_ptr->getContent()->getContent().equalTo(explored_ptr->getContent()->getContent());
                                explored_ptr = explored_ptr->getNextNode();
                            }while(explored_ptr != nullptr);
                        }
                    }
                    
                    // If not in stack and not in explored add to stack
                    if(!(in_stack || in_explored))
                       this->dfsStack->push(node_children_ptr->getContent());
                    
                    node_children_ptr = node_children_ptr->getNextNode();
                }while(node_children_ptr != nullptr);
                
            }
                
        }
        return ret;
    }
    
    //Perform BFS tree traversal
    TreeNode<T>* bfs_traversal(T search){
        //Node that has the answer
        TreeNode<Puzzle>* ret = new TreeNode<Puzzle>();
        
        //Setting the root of tree on stack
        this->bfsQueue->enqueue(this->rootNode);
        
        //Declaring explored nodes list
        TemplateLDE<TreeNode<Puzzle>*>* explored = new TemplateLDE<TreeNode<Puzzle>*>();
        
        //Expanding tree
        while (!this->bfsQueue->isEmpty()) {
            //Setting current node
            TreeNode<Puzzle>* currentNode = this->bfsQueue->dequeue();
            
            //Inserting current node to explored nodes
            explored->insertNodeFront(currentNode);
            
            //Priting on console current state
            std::cout<<"============================"<<std::endl;
            std::cout<<"NODE BEING EXPLORED"<<std::endl;
            std::cout<<"NODE DEPTH > "<< currentNode->getDepth()<<std::endl;
            currentNode->getContent().printState();
            
            //If node has the answer stop, else create new possibilities
            if(search.equalTo(currentNode->getContent())){
                ret = currentNode;
                std::cout<<"============================"<<std::endl;
                std::cout<<"ANSWER FOUND!"<<std::endl;
                currentNode->getContent().printState();
                break;
            }else{
                
                //Obtaining possible moves
                TemplateLDE<Puzzle> children = currentNode->getContent().getPossibleMoves();
                
                std::cout<<"CHILDREN"<<std::endl;
                //Inserting possible moves as tree nodes
                while(!children.isEmpty()){
                    Puzzle temp = children.removeFrontNode();
                    temp.printState();
                    currentNode->insertChild(temp);
                }
                
                TemplateNode<TreeNode<T>*>* node_children_ptr = currentNode->getChildrenList()->getFirstNode();
                
                //ForEach child in children
                do{
                    TemplateNode<TreeNode<T>*>* queue_ptr = this->bfsQueue->getFirstNode();
                    TemplateNode<TreeNode<T>*>* explored_ptr = explored->getFirstNode();
                    bool in_queue = false;
                    bool in_explored = false;
                    
                    //ForEach node in queue
                    if(queue_ptr != nullptr){
                        if(queue_ptr->getNextNode() == nullptr){
                            in_queue += node_children_ptr->getContent()->getContent().equalTo(queue_ptr->getContent()->getContent());
                        }else{
                            do{
                                in_queue += node_children_ptr->getContent()->getContent().equalTo(queue_ptr->getContent()->getContent());
                                queue_ptr = queue_ptr->getNextNode();
                            }while(queue_ptr != nullptr);
                        }
                    }
                    
                    //ForEach node in explored list
                    if(explored_ptr != nullptr){
                        if(explored_ptr->getNextNode() == nullptr){
                            in_explored += node_children_ptr->getContent()->getContent().equalTo(explored_ptr->getContent()->getContent());
                        }else{
                            do{
                                in_explored += node_children_ptr->getContent()->getContent().equalTo(explored_ptr->getContent()->getContent());
                                explored_ptr = explored_ptr->getNextNode();
                            }while(explored_ptr != nullptr);
                        }
                    }
                    
                    // If not in queue and not in explored add to queue
                    if(!(in_queue || in_explored))
                        this->bfsQueue->enqueue(node_children_ptr->getContent());
                    
                    node_children_ptr = node_children_ptr->getNextNode();
                }while(node_children_ptr != nullptr);
                
            }
            
        }
        return ret;
    }
    
    //Perform hill climbing search
    TreeNode<T>* hill_climbing(T search){
        return nullptr;
    }
    
    //Perform A* search
    TreeNode<T>* a_star_search(T search){
        return nullptr;
    }
    
    
};

#endif /* Tree_h */
