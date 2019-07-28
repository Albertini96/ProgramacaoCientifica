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
    
    TreeNode<T>* dfs_traversal(T search){
        this->dfsStack->push(this->rootNode);
        
        TreeNode<T>* ret = new TreeNode<T>();
        
        while (!this->dfsStack->isEmpty()) {
            TreeNode<T>* currentNode = this->dfsStack->pop();
            
            currentNode->getContent().printState();
            
            if(search.equalTo(currentNode->getContent())){
                ret = currentNode;
                break;
            }else{
                
                TemplateLDE<Puzzle> children = currentNode->getContent().getPossibleMoves();
                
                while(!children.isEmpty()){
                    currentNode->insertChild(children.removeFrontNode());
                }
                
                TreeNode<T>* firstChild = currentNode->getChildrenList()->getFrontNode();
                
                //Verificar quais estados ja foram testados antes de inserir na pilha
                this->dfsStack->push(firstChild);
            }
                
        }
        return ret;
    }
    
    void test(){
        
//        TreeNode<T>* root = new TreeNode<T>();
//        this->rootNode = root;
//
//        root->setContent(1);
//        root->insertChild(2);
//        root->insertChild(3);
//        root->insertChild(4);
//        root->insertChild(5);
        
    }
};

#endif /* Tree_h */
