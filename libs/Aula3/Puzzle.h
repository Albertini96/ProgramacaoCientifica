//
//  Puzzle.h
//  ProgramacaoCientifica
//
//  Created by Guilherme Albertini on 28/07/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef Puzzle_h
#define Puzzle_h
#define SIZE 3
#include "Domain.h"
#include <iostream>
#include "TemplateLDE.h"

class Puzzle {
private:
    int state[SIZE][SIZE];
public:
    
    Puzzle(){}
    Puzzle(int state[SIZE][SIZE]){
        assign_matrix(state, this->state);
    }
    
    //Set the current state of the puzzle
    void setState(int state[SIZE][SIZE]){
        assign_matrix(state, this->state);
    }
    
    //Return the current state of the puzzle
    void getState(int state[SIZE][SIZE]){
        assign_matrix(this->state, state);
    }
    
    //Return if equal to parameter
    bool equalTo(Puzzle second){
        int first_matrix[3][3];
        int second_matrix[3][3];
        bool equal = true;
        
        this->getState(first_matrix);
        second.getState(second_matrix);
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                equal *= first_matrix[i][j] == second_matrix[i][j];
            }
        }
        
        return equal;
    }
    
    TemplateLDE<Puzzle> getPossibleMoves(){
        TemplateLDE<Puzzle> possibleMoves;
        
        int temp_matrix[3][3];
        bool search_zero = false;
        int i = 0;
        int j = 0;
        
        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                if (this->state[i][j] == 0) {
                    search_zero = true;
                    break;
                }
            }
            
            if (search_zero)
                break;
        }
        
        switch (i)
        {
            case 0:
                switch (j)
            {
                case 0:
        
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[0][0] = temp_matrix[0][1];
                    temp_matrix[0][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[0][0] = temp_matrix[1][0];
                    temp_matrix[1][0] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                case 1:
            
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[0][1] = temp_matrix[0][0];
                    temp_matrix[0][0] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[0][1] = temp_matrix[0][2];
                    temp_matrix[0][2] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[0][1] = temp_matrix[1][1];
                    temp_matrix[1][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                case 2:
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[0][2] = temp_matrix[0][1];
                    temp_matrix[0][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[0][2] = temp_matrix[1][2];
                    temp_matrix[1][2] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                default:
                    break;
            }
                break;
            case 1:
                switch (j)
            {
                case 0:
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][0] = temp_matrix[0][0];
                    temp_matrix[0][0] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][0] = temp_matrix[2][0];
                    temp_matrix[2][0] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][0] = temp_matrix[1][1];
                    temp_matrix[1][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                case 1:
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][1] = temp_matrix[0][1];
                    temp_matrix[0][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][1] = temp_matrix[1][0];
                    temp_matrix[1][0] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][1] = temp_matrix[2][1];
                    temp_matrix[2][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][1] = temp_matrix[1][2];
                    temp_matrix[1][2] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                case 2:
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][2] = temp_matrix[0][2];
                    temp_matrix[0][2] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][2] = temp_matrix[1][1];
                    temp_matrix[1][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[1][2] = temp_matrix[2][2];
                    temp_matrix[2][2] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                default:
                    break;
            }
                break;
            case 2:
                switch (j)
            {
                case 0:
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[2][0] = temp_matrix[1][0];
                    temp_matrix[1][0] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[2][0] = temp_matrix[2][1];
                    temp_matrix[2][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                case 1:
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[2][1] = temp_matrix[0][2];
                    temp_matrix[0][2] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[2][1] = temp_matrix[1][1];
                    temp_matrix[1][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[2][1] = temp_matrix[2][2];
                    temp_matrix[2][2] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                case 2:
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[2][2] = temp_matrix[1][2];
                    temp_matrix[1][2] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    assign_matrix(this->state, temp_matrix);
                    temp_matrix[2][2] = temp_matrix[2][1];
                    temp_matrix[2][1] = 0;
                    possibleMoves.insertNodeFront(Puzzle(temp_matrix));
                    
                    break;
                default:
                    break;
            }
                break;
            default:
                break;
        }

        return possibleMoves;
    }
    
    void printPossibilities(){
        TemplateLDE<Puzzle> possibilities = getPossibleMoves();
        
        std::cout<<"ORIGINAL"<<std::endl;
        this->printState();
        
        while(!possibilities.isEmpty()){
            possibilities.removeFrontNode().printState();
        }
    }
    
    void printState(){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                std::cout<<state[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    
};


#endif /* Puzzle_h */
