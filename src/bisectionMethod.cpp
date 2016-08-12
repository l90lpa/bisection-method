//  bisectionMethod.cpp
//  biscetion-method
//
//  Created by Liam on 12/08/2016.
//  Copyright © 2016 Liam. All rights reserved.
//

#include "bisectionMethod.hpp"

// Check to ensure that the initial end points result in, f(a) and f(b) having opposite signs, or
// whether either of the initial end points is a solution.
char initialConditionsCheck(double a, double b)
{
    std::cout << "For a = " << a << ", b = " << b << '\n';
    std::cout << "f(a) = " << function(a) << ", f(b) = " << function(b) << '\n';
    
    if(function(a) * function(b) > 0)
    {
        std::cout << "The end points of the interval [a, b] need to be adjusted so that f(a) and f(b) have opposite signs." << '\n';
        return 'f';
    }
    else if(function(a) == 0)
    {
        std::cout << "a = " << a << ", is a root of the equation.";
        return 'a';
    }
    else if(function(b) == 0)
    {
        std::cout << "b = " << b << ", is a root of the equation.";
        return 'b';
    }
    else
        return 't';
}

// Determines the number of iterations required to meet the required accuracy.
void numberOfIterations(double a, double b, int n)
{
    double j = ((std::log10l(b - a)) + n)/(std::log10l(2));
    int k = static_cast<int>(j);
    if(k < j)
        ++k;
    std::cout << "For an accuracy of " << n << " decimal places this method will require " << k << " iterations." <<'\n';
}

double midpoint(double a, double b)
{
    double c = 0.5 * (a + b);
    return c;
}

double roundNumber(double x, int n)
{
    int tempOne = static_cast<int>(x * std::pow(10, n));
    int tempTwo = static_cast<int>(x * std::pow(10, n + 1));
    if((tempTwo - (tempOne * 10)) > 4)
        return static_cast<double>((tempOne + 1) * std::pow(10, -n));
    else
        return static_cast<double>((tempOne) * std::pow(10, -n));
}

// The main logic of the bisection method.
double bisectionMethod(double a, double b, int n)
{
    int r = 0; //This is the iteration counter.
    double c = midpoint(a,b);
    
    while((b-a) > std::pow(10, -n))
    {
        c = midpoint(a,b);
        double fc = function(c);
        
        if(fc == 0)
        {
            std::cout << "f(c) = " << fc << ", thus c = " << c << ", is a root of the equation.";
            break;
        }
        
        if(fc * function(b) > 0)
            b = c;
        else
            a = c;
        
        std::cout << "Iteration: " << ++r << ", c = " << c << ", f(c) = " << fc << ", a = " << a << ", b = " << b << '\n';
    }
    
    // When the iteration leads to a interval for which the end points are equal when rounded to
    // n decimal places then this is the root.
    
    if(roundNumber(a, n) == roundNumber(b, n))
        return roundNumber(a, n);
    
    // When the iteration leads to a interval for which the end points are not equal when rounded to
    // n decimal places then to determine the solution to n decimal places the following check is used.
    // Let a' and b' be the final iteration end points rounded to n decimal places, and let c' = 0.5*(a'+b')
    // then if f(c') has the same sign as f(a) then b' is the solution to n decimal places and vise vera.
    
    if(function(0.5 * (roundNumber(a, n) + roundNumber(b, n))) * function(roundNumber(b, n)) > 0)
        return roundNumber(a, n);
    else
        return roundNumber(b, n);
}
