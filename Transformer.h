#ifndef __TRANSFORMER_H__
#define __TRANSFORMER_H__

#include "Tokenizer.h"
#include <stack>

using namespace std;



class InfixToPostfixTransformer {
public:
  /**
   * Helper method to do the transformation.
   */
  static stack<Token> transform(const string &code) {
    AList<Token> infix = tokenStreamToList(code);
    return infixToPostfix(infix);
  }

private:
  /**
   * Convert stream of tokens to a list.
   */
  static AList<Token> tokenStreamToList(const string &code) {
    Tokenizer lexer(code);
    AList<Token> res;
    for (Token token = lexer.next();
         !token.is_one_of(Token::Kind::End, Token::Kind::Unexpected);
         token = lexer.next())
      res.addLast(token);
    return res;
  }

  static stack<Token> infixToPostfix(const AList<Token> &infix);
};



#endif // __TRANSFORMER_H__
