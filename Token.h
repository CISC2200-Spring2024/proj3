#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <ostream>
#include <string>



class Token {
public:
  enum class Kind {
    Number,
    LeftParen,
    RightParen,
    Plus,
    Minus,
    Asterisk,
    End,
    Unexpected
  };

  Kind kind{}; //EZ: WHy {} ? 
  std::string lexeme{};

  //Contrsuctor 1 
  explicit Token(Kind k=Kind::Number) : kind(k) {}

  //Contrsuctor 2
  Token(Kind k, const std::string &s) : kind(k), lexeme(s) {}

  //Contrsuctor 3, what's the second parameter?, take part of the string interator?  
  // Change to use indices for readability...
  Token(Kind k, std::string::const_iterator beg, size_t len)
      : kind(k), lexeme(beg, beg + len) {}

  //Constructor 4 : take parts of the string? 
  Token(Kind k, std::string::const_iterator beg,
        std::string::const_iterator end)
      : kind(k), lexeme(beg, end) {}

  //output operator 
  friend std::ostream &operator<<(std::ostream &os, const Token &token) {
    static const char *const names[]{
        "Number", "LeftParen", "RightParen", "Plus",
        "Minus",  "Asterisk",  "End",        "Unexpected",
    };
    return os << names[static_cast<int>(token.kind)] << "("
              << token.lexeme + ")";
  }

  // helper functions to check the kind of a token
  bool is(Kind k) const { return kind == k; }

  bool is_one_of(Kind k1, Kind k2) const { return is(k1) || is(k2); }

  //EZ: Allow a varying number of parameters? 
  template <typename... Ts> bool is_one_of(Kind k1, Kind k2, Ts... ks) const {
    return is(k1) || is_one_of(k2, ks...);
  }
};



#endif // __TOKEN_H__
