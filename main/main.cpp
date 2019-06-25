//
//  main.cpp
//  Aula2
//
//  Created by Guilherme Albertini on 18/06/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"
#include "DynamicStack.hpp"
#include "DynamicQueue.hpp"

int main(int argc, const char * argv[]) {
    
    try {
        DynamicStack pilha;
        DynamicQueue fila;
        
        pilha.test();
        fila.test();
        
    } catch (std::ios_base::failure& e) {
    
        std::cout<< "The program encountered a runtime error : " << std::endl << e.what();
    
    }
    
    return 0;
}
