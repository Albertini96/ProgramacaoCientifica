//
//  main.cpp
//  Aula2
//
//  Created by Guilherme Albertini on 18/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#include <iostream>
//#include "Stack.hpp"
#include "Queue.hpp"
#include "DynamicStack.hpp"
#include "DynamicQueue.hpp"
#include "TemplateLDE.h"
#include "Tree.h"
#include "Puzzle.h"
#include "GradientDescent.hpp"
#include "NumericalIntegration.h"

int main(int argc, const char * argv[]) {
    
    try {
        //Aula 2
        DynamicStack pilha;
        DynamicQueue fila;

        pilha.test();
        fila.test();

        //Aula 3
        int initial_state[3][3];

        initial_state[0][0] = 4;
        initial_state[0][1] = 1;
        initial_state[0][2] = 6;
        initial_state[1][0] = 3;
        initial_state[1][1] = 2;
        initial_state[1][2] = 8;
        initial_state[2][0] = 7;
        initial_state[2][1] = 0;
        initial_state[2][2] = 5;

        int goal_state[3][3];

        goal_state[0][0] = 1;
        goal_state[0][1] = 2;
        goal_state[0][2] = 3;
        goal_state[1][0] = 4;
        goal_state[1][1] = 5;
        goal_state[1][2] = 6;
        goal_state[2][0] = 7;
        goal_state[2][1] = 8;
        goal_state[2][2] = 0;

        Puzzle start_state = Puzzle(initial_state);
        Puzzle final_state = Puzzle(goal_state);

        Tree<Puzzle> arvore(start_state);
        arvore.dfs_traversal(final_state);
        arvore.bfs_traversal(final_state);
        arvore.hill_climbing(final_state);
        arvore.a_star_search(final_state);


        //Aula 4
        GradientDescent* gd = new GradientDescent();
        gd->testFindMinimumA();
        
        //Aula 5
        NumericalIntegration ni;
        
        float mid_pointF1 = ni.midPointIntegrationF1(0, 1, 4);
        float trapezoidalF1 = ni.trapezoidalIntegrationF1(0, 1, 4);
        float simpsonF1 = ni.simpsonIntegrationF1(0, 1, 4);

        float mid_pointF2 = ni.midPointIntegrationF2(0, 1, 4);
        float trapezoidalF2 = ni.trapezoidalIntegrationF2(0, 1, 4);
        float simpsonF2 = ni.simpsonIntegrationF2(0, 1, 4);

        float mid_pointF3 = ni.midPointIntegrationF3(0, 1, 4);
        float trapezoidalF3 = ni.trapezoidalIntegrationF3(0, 1, 4);
        float simpsonF3 = ni.simpsonIntegrationF3(0, 1, 4);


        float teste = ni.adaptativeMidPointF1(0, 1, 0.001);
        
    } catch (std::ios_base::failure& e) {
    
        std::cout<< "The program encountered a runtime error : " << std::endl << e.what();
    
    }
    
    return 0;
}
