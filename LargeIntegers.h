// Aviad Gottesman 311250484.

#ifndef ADV1_INFINT_H
#define ADV1_INFINT_H

//using namespace std;
#include <string>
#include <iostream>

class InfInt {
private:
    std::string _num;
    bool _sign;
public:

    /* Constructors */
    InfInt();
    InfInt(std::string);
    InfInt(const char*);
    InfInt(long);
    InfInt(const InfInt&);

    /* Input Validation */
    bool isValidInput(std::string&);

    /* Getters and Setters. */
    std::string getNum() const;
    //void setNum(string&);
    void setNum(std::string);
    bool getSign() const;
    void setSign(bool _sign);

    /* Convert decimal string to binary string. */
    std::string longDivision(std::string) const;
    void reverseStr(std::string&) const;
    std::string toBinaryPositive(std::string&) const;
    std::string toBinary() const;

    /* Convert binary string to decimal string. */
    std::string toDecimal(std::string&) const;

    /* Operators overload. */
    bool operator== (InfInt) const;
    bool operator!= (InfInt) const;
    bool operator>  (InfInt) const;
    bool operator<  (InfInt) const;
    bool operator>= (InfInt) const;
    bool operator<= (InfInt) const;

    InfInt operator+ (InfInt) const;
    InfInt operator- (InfInt) const;
    InfInt operator* (InfInt) const;
    InfInt operator/ (InfInt) const;
    InfInt operator% (InfInt) const;

    InfInt& operator+= (const InfInt&);
    InfInt& operator*= (const InfInt&);
    InfInt& operator++ ();
    InfInt operator++ (int);
    InfInt& operator-- ();
    InfInt operator-- (int);

    InfInt operator& (InfInt) const;
    InfInt operator| (InfInt) const;
    InfInt operator^ (InfInt) const;
    InfInt operator<< (int) const;
    InfInt operator>> (int) const;

    InfInt operator>>= (int);
    InfInt& operator&= (InfInt);

    friend std::ostream& operator<< (std::ostream&, const InfInt&);
    friend std::istream& operator>> (std::istream&, InfInt&);

    void* operator new (size_t size);
    void operator delete (void*);
    InfInt& operator= (const InfInt&);

    explicit operator int() const;

    /* Helpers methods. */
private:
    std::string plus(std::string, std::string ) const;
    std::string minus(std::string, std::string) const;
    std::string divide(InfInt, InfInt) const;
    std::string longDivide(InfInt, InfInt) const;
    std::string multiply(std::string, std::string) const;
    InfInt absoluteValue() const;
    InfInt bitsRequired() const;
    InfInt negativeInfInt() const;
};

#endif //ADV1_INFINT_H
