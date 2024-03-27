#ifndef __BIGINT_H__
#define __BIGINT_H__

#include "AList.h"
#include <iostream>
#include <string>



class BigInt {
private:
  AList<int> digits; // stores the digits of the BigInt

public:
  /**
   * Construct a new BigInt object from string.
   *
   * @param val a string of unlimited digits; default is empty string
   */
  explicit BigInt(const std::string &val = "") {
    for (unsigned j = 0; j < val.length(); j++) {
      digits.addLast(val[j] - '0');
    }
  }

  /** Override `<<` to print all digits to os. */
  friend std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
    for (int i = 0; i < bi.digits.size(); i++)
      os << bi.digits.get(i);
    return os;
  }

  inline BigInt operator+(const BigInt &other) const;
  inline BigInt operator-(const BigInt &other) const;
};

/** Return the *sum* of this BigInt and the `other` BigInt. */
BigInt BigInt::operator+(const BigInt &other) const {
  // Reference: https://en.wikipedia.org/wiki/Addition
  // Example: 456 + 1123 = 1579
  // TODO:
  BigInt r;
  return r;
}

/** Return the *absolute difference* between this and the `other` BigInt. */
BigInt BigInt::operator-(const BigInt &other) const {
  // Reference: https://en.wikipedia.org/wiki/Absolute_difference
  // Example: 456 - 1123 = 667
  // TODO:
  BigInt r;
  return r;

}



#endif // __BIGINT_H__
