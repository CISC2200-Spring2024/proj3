#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Calculator.h"
#include "Transformer.h"
#include "doctest.h"
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("All") {
  string inputExpr = "456 + (1123 - 1) + 1";

  stack<Token> postfixStk = InfixToPostfixTransformer::transform(inputExpr);

  stringstream ss1;
  stack<Token> postfixStkCopy = postfixStk;
  while (!postfixStkCopy.empty()) {
    Token top = postfixStkCopy.top();
    postfixStkCopy.pop();
    ss1 << top << " ";
  }
  REQUIRE(ss1.str() == "Plus(+) Number(1) Plus(+) Minus(-) "
                       "Number(1) Number(1123) Number(456) ");

  BigInt res = Calculator::calculate(postfixStk);
  stringstream ss2;
  ss2 << res;
  REQUIRE(ss2.str() == "1579");
}
