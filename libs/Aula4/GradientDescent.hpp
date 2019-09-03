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
    
    //Derivate point using function A
    float derivatePointA(float x){
        return 2*x;
    }
    
    //Derivate point using function B
    float derivatePointB(float x){
        return (3*pow(x, 2)) - (4 * x);
    }
    
    //Find the minimum on function A
    float findMinimumA(float x0, float learning_rate, float error){
        
        float x = x0;
        
        //While derivate of point A is bigger than error
        while(derivatePointA(x) >= error){
            //Refresh value of X
            x = x - (learning_rate * derivatePointA(x));
        }
        
        //Print Out Results
        std::cout<<"Learning Rate: " << learning_rate<<std::endl;
        std::cout<<"Final X: " << x<<std::endl;
        std::cout<<"Derivate: " << derivatePointA(x)<<std::endl<<std::endl;
        
        return x;
    }
    
    //Find the minimum on function B
    float findMinimumB(float x0, float learning_rate, float error){
        
        float x = x0;
        
        //While derivate of point B is bigger than error
        while(derivatePointB(x) >= error){
            //Refresh value of X
            x = x - (learning_rate * derivatePointB(x));
        }
        
        //Print Out Results
        std::cout<<"Learning Rate: " << learning_rate<<std::endl;
        std::cout<<"Final X: " << x<<std::endl;
        std::cout<<"Derivate: " << derivatePointB(x)<<std::endl<<std::endl;
        
        return x;
    }
    
    //Test finding minimum on function A with multiple values of Beta
    void testFindMinimumA(){
        
        for (float i = 0.1; i <= 1; i+= 0.1) {
            findMinimumA(2, i, pow(10, -20));
        }
        
    }
    
    //Test finding minimum on function B with multiple values of Beta
    void testFindMinimumB(){
        
        for (float i = 0.2; i <= 1; i+= 0.1) {
            findMinimumB(2, i, pow(10, -20));
        }
        
    }
    
};



#endif /* GradientDescent_hpp */
