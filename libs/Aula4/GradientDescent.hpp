//
//  GradientDescent.hpp
//  ProgramacaoCientifica
//
//  Created by Guilherme Albertini on 13/08/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef GradientDescent_hpp
#define GradientDescent_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
class GradientDescent {
    
public:
    
    GradientDescent(){};
    
    float derivatePointA(float x){
        return 2*x;
    }
    
    float derivatePointB(float x){
        return (3*pow(x, 2)) - (4 * x);
    }
    
    float findMinimumA(float x0, float learning_rate, float error){
        
        float x = x0;
        
        while(derivatePointA(x) >= error){
            x = x - (learning_rate * derivatePointA(x));
        }
        
        std::cout<<"Learning Rate: " << learning_rate<<std::endl;
        std::cout<<"Final X: " << x<<std::endl;
        std::cout<<"Derivate: " << derivatePointA(x)<<std::endl<<std::endl;
        
        return x;
    }
    
    float findMinimumB(float x0, float learning_rate, float error){
        
        float x = x0;
        
        while(derivatePointB(x) >= error){
            x = x - (learning_rate * derivatePointB(x));
        }
        
        std::cout<<"Learning Rate: " << learning_rate<<std::endl;
        std::cout<<"Final X: " << x<<std::endl;
        std::cout<<"Derivate: " << derivatePointB(x)<<std::endl<<std::endl;
        
        return x;
    }
    
    void testFindMinimumA(){
        
        for (float i = 0.1; i <= 1; i+= 0.1) {
            findMinimumA(2, i, pow(10, -20));
        }
        
    }
    
    void testFindMinimumB(){
        
        for (float i = 0.2; i <= 1; i+= 0.1) {
            findMinimumB(2, i, pow(10, -20));
        }
        
    }
    
};



#endif /* GradientDescent_hpp */
