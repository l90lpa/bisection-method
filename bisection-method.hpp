//  bisectionMethod.hpp
//  bisection-method
//
//  Created by Liam on 12/08/2016.
//  Copyright © 2016 Liam. All rights reserved.
//

#ifndef bisectionMethod_hpp
#define bisectionMethod_hpp

#include <iostream>
#include <cmath>


// This forward declaration is included in the header so that the functions in bisectionMethod.cpp can see it.
double function(double x);

// Check to ensure that the initial end points result in, f(a) and f(b) having opposite signs, or
// whether either of the initial end points is a solution.
char initialConditionsCheck(double a, double b);

// Determines the number of iterations required to meet the required accuracy.
void numberOfIterations(double a, double b, int n);

double midpoint(double a, double b);

double roundNumber(double x, int n);

// The main logic of the bisection method.
double bisectionMethod(double a, double b, int n);

#endif /* bisectionMethod_hpp */
