//
//  NumericalIntegration.h
//  ProgramacaoCientifica
//
//  Created by Guilherme Albertini on 25/08/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef NumericalIntegration_h
#define NumericalIntegration_h

#include <math.h>
#include "TemplateLDE.h"

class NumericalIntegration {
private:
    
public:
    
    //Calculates the factorial of n
    int factorial(int n){
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
    
    //Calculate the combinatory of n and k
    int comb(int n, int k){
        return (factorial(n))/(factorial(k) * factorial(n - k));
    }
    
    //Evaluate function 1 on point x
    float f1(float x){
        return exp(x);
    }
    
    //Evaluate function 2 on point x
    float f2(float x){
        return sqrt(1 - pow(x, 2));
    }
    
    //Evaluate function 3 on point x
    float f3(float x){
        return exp(-pow(x, 2));
    }
    
    //F1
    //Calculate the defined integral from _initial to _final for function 1 using MidPoint method
    float midPointIntegrationF1(float _initial, float _final){
        return (_final - _initial) * (f1((_final + _initial) / 2));
    }
    
    //Calculate the defined integral from _initial to _final for function 1 using Trapezoidal method
    float trapezoidalIntegrationF1(float _initial, float _final){
        return (_final - _initial) * ((f1(_initial) + f1(_final)) / 2);
    }
    
    //Calculate the defined integral from _initial to _final for function 1 using Simpson method
    float simpsonIntegrationF1(float _initial, float _final){
        return (_final - _initial) * ((f1(_initial) + (4* (f1((_final + _initial) / 2)) ) +  f1(_final)) / 6);
    }
    
    //F2
    //Calculate the defined integral from _initial to _final for function 2 using MidPoint method
    float midPointIntegrationF2(float _initial, float _final){
        return (_final - _initial) * (f2((_final + _initial) / 2));
    }
    
    //Calculate the defined integral from _initial to _final for function 2 using Trapezoidal method
    float trapezoidalIntegrationF2(float _initial, float _final){
        return (_final - _initial) * ((f2(_initial) + f2(_final)) / 2);
    }
    
    //Calculate the defined integral from _initial to _final for function 2 using Simpson method
    float simpsonIntegrationF2(float _initial, float _final){
        return (_final - _initial) * ((f2(_initial) + (4* (f2((_final + _initial) / 2)) ) +  f2(_final)) / 6);
    }
    
    //F3
    //Calculate the defined integral from _initial to _final for function 3 using MidPoint method
    float midPointIntegrationF3(float _initial, float _final){
        return (_final - _initial) * (f3((_final + _initial) / 2));
    }
    
    //Calculate the defined integral from _initial to _final for function 3 using Trapezoidal method
    float trapezoidalIntegrationF3(float _initial, float _final){
        return (_final - _initial) * ((f3(_initial) + f3(_final)) / 2);
    }
    
    //Calculate the defined integral from _initial to _final for function 3 using Simpson method
    float simpsonIntegrationF3(float _initial, float _final){
        return (_final - _initial) * ((f3(_initial) + (4* (f3((_final + _initial) / 2)) ) +  f3(_final)) / 6);
    }
    
    //Adaptative
    //Calculates the integral of f1 using mid point method and adaptative squares
    float midPointIntegrationF1(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += midPointIntegrationF1(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Calculates the integral of f2 using mid point method and adaptative squares
    float midPointIntegrationF2(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += midPointIntegrationF2(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Calculates the integral of f3 using mid point method and adaptative squares
    float midPointIntegrationF3(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += midPointIntegrationF3(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Calculates the integral of f1 using trapezoidal method and adaptative squares
    float trapezoidalIntegrationF1(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += trapezoidalIntegrationF1(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Calculates the integral of f2 using trapezoidal method and adaptative squares
    float trapezoidalIntegrationF2(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += trapezoidalIntegrationF2(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Calculates the integral of f3 using trapezoidal method and adaptative squares
    float trapezoidalIntegrationF3(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += trapezoidalIntegrationF3(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Calculates the integral of f1 using simpson method and adaptative squares
    float simpsonIntegrationF1(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += simpsonIntegrationF1(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Calculates the integral of f2 using simpson method and adaptative squares
    float simpsonIntegrationF2(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += simpsonIntegrationF2(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Calculates the integral of f3 using simpson method and adaptative squares
    float simpsonIntegrationF3(float _initial, float _final, int n_squares){
        
        //Define interval between squares
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        //Create a list with the intervals
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        //Calculate the integral with all the intervals from the list
        do {
            result += simpsonIntegrationF3(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
};

#endif /* NumericalIntegration_h */
