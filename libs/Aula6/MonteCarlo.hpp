//
//  MonteCarlo.hpp
//  ProgramacaoCientifica
//
//  Created by Guilherme Albertini on 14/09/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef MonteCarlo_hpp
#define MonteCarlo_hpp

#include <stdio.h>
#include <math.h>
#include <random>
#include <iostream>
class MonteCarlo {

public:
    
    float Equation(float x){
        return 4 / (1 + pow(x, 2));
    }
    
    float IntegrateEquation(float from, float to, int attempts){
        
        float average = 0;
        
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(from, to);
        
        for (int i = 0; i < attempts; i++) {
            average += this->Equation(dist(mt));
        }
        
        average = average / attempts;
        
        return (to - from) * average;
    }
    
    float Toroide(float x, float y, float z){
        return pow(z, 2) + pow(( sqrt(pow(x, 2) + pow(y, 2) ) - 3 ), 2) <= 1 ? 1 : 0;
    }
    
    double IntegrateToroide( double x_from,
                  double x_to,
                  double y_from,
                  double y_to,
                  double z_from,
                  double z_to,
                  int attempts
            ){
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist_x(x_from, x_to);
        std::uniform_real_distribution<double> dist_y(y_from, y_to);
        std::uniform_real_distribution<double> dist_z(z_from, z_to);
        
        double average = 0;
        double n = 0;
        double cube_volume = (x_to - x_from) * (y_to - y_from) * (z_to - z_from);
        double x = 0;
        double y = 0;
        double z = 0;
        int count = 0;
        
        while (count < attempts){
            
            x = dist_x(mt);
            y = dist_y(mt);
            z = dist_z(mt);
            
            n = Toroide(x, y, z);
            
            if (n <= 1 && x > 1 && y >= -3 ) {
                average += n;
                count++;
            }
            
        }
        
        return cube_volume * (average / attempts);
    }
    
    void test_integrate_equation(){
        std::cout<< "Equation Integral - > " << IntegrateEquation(0, 1, 1000000)<< std::endl;
    }
    
    void test_integrate_toroide(){
        std::cout<< "Toroide Integral - > " << IntegrateToroide(1, 4, -3, 4, -1, 1, 100000000)<< std::endl;
    }
    
};

#endif /* MonteCarlo_hpp */
