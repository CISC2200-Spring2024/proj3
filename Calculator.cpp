#include "Calculator.h"



/**
 * Calculate the result of expression in postfix notation.
 *
 * @param postfixStk the stack of postfix tokens
 * @return BigInt the result as BigInt
 */
BigInt Calculator::calculate(stack<Token> &postfixStk) {
  // Example:
  // https://docs.google.com/presentation/d/1NO2ZKEVu3IZ07Oy-QNxdAell_FThC6RylEWDEGRim6U/edit#slide=id.geefd7e6b55_0_16
  // Pseudocode: 
  /* One beautiful thing about postfix notation is that it is easily implemented in programming by using a stack. Here's how to do it.
    Read in one symbol at a time from the postfix expression.

    Any time you see an operand, push it onto the stack.
    Any time you see a binary operator (+, -, *, /) or unary (square root, negative sign) operator,
    If the operator is binary, pop two elements off of the stack.
    If the operator is unary, pop one element off the stack.
    Evaluate those operands with that operator
    Push the result back onto the stack.
    When you're done with the entire expression, the only thing left on the stack should be the final result. If there are zero or more than 1 operands left on the stack, either your program is flawed, or the expression was invalid.  BigInt r;
  */
   BigInt r;
   return r;
}


