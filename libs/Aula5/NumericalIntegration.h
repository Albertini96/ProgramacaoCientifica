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
    
    int factorial(int n){
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
    
    int comb(int n, int k){
        return (factorial(n))/(factorial(k) * factorial(n - k));
    }
    
    float f1(float x){
        return exp(x);
    }
    
    float f2(float x){
        return sqrt(1 - pow(x, 2));
    }
    
    float f3(float x){
        return exp(-pow(x, 2));
    }
    
    //F1
    float midPointIntegrationF1(float _initial, float _final){
        return (_final - _initial) * (f1((_final + _initial) / 2));
    }
    
    float trapezoidalIntegrationF1(float _initial, float _final){
        return (_final - _initial) * ((f1(_initial) + f1(_final)) / 2);
    }
    
    float simpsonIntegrationF1(float _initial, float _final){
        return (_final - _initial) * ((f1(_initial) + (4* (f1((_final + _initial) / 2)) ) +  f1(_final)) / 6);
    }
    
    //F2
    float midPointIntegrationF2(float _initial, float _final){
        return (_final - _initial) * (f2((_final + _initial) / 2));
    }
    
    float trapezoidalIntegrationF2(float _initial, float _final){
        return (_final - _initial) * ((f2(_initial) + f2(_final)) / 2);
    }
    
    float simpsonIntegrationF2(float _initial, float _final){
        return (_final - _initial) * ((f2(_initial) + (4* (f2((_final + _initial) / 2)) ) +  f2(_final)) / 6);
    }
    
    //F3
    float midPointIntegrationF3(float _initial, float _final){
        return (_final - _initial) * (f3((_final + _initial) / 2));
    }
    
    float trapezoidalIntegrationF3(float _initial, float _final){
        return (_final - _initial) * ((f3(_initial) + f3(_final)) / 2);
    }
    
    float simpsonIntegrationF3(float _initial, float _final){
        return (_final - _initial) * ((f3(_initial) + (4* (f3((_final + _initial) / 2)) ) +  f3(_final)) / 6);
    }
    
    //Adaptative
    float midPointIntegrationF1(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += midPointIntegrationF1(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    float midPointIntegrationF2(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += midPointIntegrationF2(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    float midPointIntegrationF3(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += midPointIntegrationF3(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    float trapezoidalIntegrationF1(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += trapezoidalIntegrationF1(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    float trapezoidalIntegrationF2(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += trapezoidalIntegrationF2(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    float trapezoidalIntegrationF3(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += trapezoidalIntegrationF3(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    float simpsonIntegrationF1(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += simpsonIntegrationF1(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    float simpsonIntegrationF2(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += simpsonIntegrationF2(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    float simpsonIntegrationF3(float _initial, float _final, int n_squares){
        
        float interval = (_final - _initial) / n_squares;
        float temp = _initial;
        TemplateLDE<float> integration_intervals;
        float result = 0;
        
        integration_intervals.insertNodeFront(_initial);
        while (temp != _final) {
            temp = temp + interval;
            integration_intervals.insertNodeFront(temp);
            integration_intervals.insertNodeFront(temp);
        }
        integration_intervals.removeFrontNode();
        
        do {
            result += simpsonIntegrationF3(integration_intervals.removeBackNode(), integration_intervals.removeBackNode());
        } while (!integration_intervals.isEmpty());
        
        return result;
    }
    
    //Errors
    
    float midPointErrorF1(int n_squares, float a, float b){
        
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 2;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i < order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f1(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = (pow(h, 3)/24)*derivate;
        
        return result;
    }
    
    float midPointErrorF2(int n_squares, float a, float b){
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 2;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i <= order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f2(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = (pow(h, 3)/24)*derivate;
        
        return result;
    }
    
    float midPointErrorF3(int n_squares, float a, float b){
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 2;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i <= order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f3(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = (pow(h, 3)/24)*derivate;
        
        return result;
    }
    
    float trapezoidalErrorF1(int n_squares, float a, float b){
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 2;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i <= order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f1(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = -(pow(b - a, 3)/12)*derivate;
        
        return result;
    }
    
    float trapezoidalErrorF2(int n_squares, float a, float b){
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 2;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i <= order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f2(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = -(pow(b - a, 3)/12)*derivate;
        
        return result;
    }
    
    float trapezoidalErrorF3(int n_squares, float a, float b){
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 2;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i <= order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f3(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = -(pow(b - a, 3)/12)*derivate;
        
        return result;
    }
    
    float simpsonErrorF1(int n_squares, float a, float b){
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 4;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i <= order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f1(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = -(pow(b - a, 5)/2880)*derivate;
        
        return result;
    }
    
    float simpsonErrorF2(int n_squares, float a, float b){
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 4;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i <= order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f2(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = -(pow(b - a, 5)/2880)*derivate;
        
        return result;
    }
    
    float simpsonErrorF3(int n_squares, float a, float b){
        float result = 0;
        float h = (b-a)/n_squares;
        int order = 4;
        float small_number = 0.00000001;
        
        float derivate = 0;
        float sum = 0;
        for (int i = 0; i <= order; i++) {
            sum += pow(-1, i+order) * comb(order, i) * f3(h + (i* small_number));
        }
        
        derivate = (1/(pow(small_number, order))) * sum;
        
        result = -(pow(b - a, 5)/2880)*derivate;
        
        return result;
    }
    
    float adaptativeMidPointF1(float _initial, float _final, float error){
        int n_squares = 1;
        while (abs(midPointErrorF1(n_squares, _initial, _final)) > error) {
            n_squares++;
        }
        return midPointIntegrationF1(_initial, _final, n_squares);
    }
    
};

#endif /* NumericalIntegration_h */
