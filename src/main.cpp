//  main.cpp
//  bisection-method
//
//  Created by Liam on 01/08/2016.
//  Copyright © 2016 Liam. All rights reserved.
//



//BISECTION METHOD, single variable, nonlinear equation.

#include <iostream>
#include <cmath>
#include "bisectionMethod.hpp"

//Must set the function to be solved prior to running the program. Note there is a forward declartion for this function
//in bisectionMethod.hpp.
double function(double x)
{
    return ((x*std::exp(-x)-0.25));
}


int main()
{
    //Must set the values of a and b prior to running program for the closed interval [a, b].
    double a = 2;
    double b = 2.8;
    //Must set required accuracy of the solution to n decimal places prior to running program.
    int n = 6;
    
    char checkResult = initialConditionsCheck(a, b);
    switch (checkResult)
    {
        case 'f':
            return 0;
            break;
        case 'a':
            return 0;
            break;
        case 'b':
            return 0;
            break;
        case 't':
            break;
    }
    
    numberOfIterations(a, b, n);
    char choice = 'a';
    std::cout << "Do you want to continue? For no enter \"n\" for yes enter any other key: ";
    std::cin >> choice;
    if(choice == 'n')
        return 0;
    
    double solution = bisectionMethod(a, b, n);
    std::cout << std::setprecision(n);
    std::cout << "To " << n << " decimal places the solution " << solution << '\n';
  
    return 0;
}
