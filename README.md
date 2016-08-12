# bisection-method
C++, bisection method for numerical solution of nonlinear equations of the form f(x) = 0, in the initial interval [a, b].
In this implementation, prior to carrying out the bisection method, first the condition that f(a) and f(b) have opposite signs is checked - along with checking if either of the initial end points a and b is a solution. Then secondly the number of iterations required to find a result to a given number of decimal places is determined and the option is provided to abort.

## setup
All setup is done in main.cpp.
- The function, function(double), needs to be altered to return f(x) which is the function intended to be solved.
- The variables, "a" and "b", should be set to the values of end points of the initial interval.
- The variables, "n", should be set to the required number of decimal places for which the solution is to be found.
