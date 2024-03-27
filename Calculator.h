#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "BigInt.h"
#include "Token.h"
#include <stack>

using namespace std;



class Calculator {
public:
  static BigInt calculate(stack<Token> &postfixStk);
};



#endif // __CALCULATOR_H__
