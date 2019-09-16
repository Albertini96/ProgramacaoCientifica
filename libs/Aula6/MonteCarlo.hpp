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
    
    //Evaluates the equation on point x
    float Equation(float x){
        return 4 / (1 + pow(x, 2));
    }
    
    //Integrate equation defined between the from and to variables
    float IntegrateEquation(float from, float to, int attempts){
        
        float average = 0;
        
        //Defines a random generator
        std::random_device rd;
        std::mt19937 mt(rd());
        
        //Defines boundries of random numbers to be generated
        std::uniform_real_distribution<double> dist(from, to);
        
        //Evaluates the equation with random numbers as many times as defined in the variable attempts
        for (int i = 0; i < attempts; i++) {
            average += this->Equation(dist(mt));
        }
        
        //Calculates the average of evaluations
        average = average / attempts;
        
        return (to - from) * average;
    }
    
    //Evaluate the toroidal equation on points x, y, z
    float Toroide(float x, float y, float z){
        return pow(z, 2) + pow(( sqrt(pow(x, 2) + pow(y, 2) ) - 3 ), 2) <= 1 ? 1 : 0;
    }
    
    //Integrate the toroidal equation finding the volume of the figure
    double IntegrateToroide( double x_from,
                  double x_to,
                  double y_from,
                  double y_to,
                  double z_from,
                  double z_to,
                  int attempts
            ){
        //Defines a random generator
        std::random_device rd;
        std::mt19937 mt(rd());
        
        //Defines boundries of random numbers to be generated on x
        std::uniform_real_distribution<double> dist_x(x_from, x_to);
        //Defines boundries of random numbers to be generated on y
        std::uniform_real_distribution<double> dist_y(y_from, y_to);
        //Defines boundries of random numbers to be generated on z
        std::uniform_real_distribution<double> dist_z(z_from, z_to);
        
        double average = 0;
        double n = 0;
        double x = 0;
        double y = 0;
        double z = 0;
        int count = 0;
        
        //Calculates the volume of the cube that involves the figure
        double cube_volume = (x_to - x_from) * (y_to - y_from) * (z_to - z_from);
        
        //Loop to evaluate the equation with random numbers
        while (count < attempts){
            
            //Find a random number for x
            x = dist_x(mt);
            //Find a random number for y
            y = dist_y(mt);
            //Find a random number for z
            z = dist_z(mt);
            
            //Evaluate the equation with random numbers
            n = Toroide(x, y, z);
            
            //Check if the point evaluated is inside the figure
            //if so, add one to averge variable
            if (n <= 1 && x > 1 && y >= -3 ) {
                average += n;
                count++;
            }
            
        }
        
        //Return the value of the figure volume
        return cube_volume * (average / attempts);
    }
    
    //Execute the equation integration with monte carlo method
    void test_integrate_equation(){
        std::cout<< "Equation Integral - > " << IntegrateEquation(0, 1, 1000000)<< std::endl;
    }
    
    //Execute the toroidal equation integration with monte carlo method
    void test_integrate_toroide(){
        std::cout<< "Toroide Integral - > " << IntegrateToroide(1, 4, -3, 4, -1, 1, 100000000)<< std::endl;
    }
    
};

#endif /* MonteCarlo_hpp */
