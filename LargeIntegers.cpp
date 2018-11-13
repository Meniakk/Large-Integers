// Aviad Gottesman 311250484.

#include <string>
#include <iostream>
#include "LargeIntegers.h"
//#include <climits>

using namespace std;

/* Constructors */

/**
 * The default constructor, set's the value to '0' and sign to false.
 */
InfInt::InfInt() {
    _num = "0";
    _sign = false;
}

/**
 * A constructor that accept string.
 * @param str the value to set.
 */
InfInt::InfInt (string str) {

    /* Checks if the input is valid, if it ain't use default values. */
    if (!isValidInput(str)) {
        _num = "0";
        _sign = false;
    } else {
        /**
        * If the first char is a number continue regularly.
        * else. check if its -/+ and adjust the _sign accordingly,
        * and set the value to the substring w/o the sign char.
        */
        if (isdigit(str[0])) {
            _num = str;
            _sign = false;
        } else {
            _sign = (str[0] == '-');
            _num = str.substr(1);
        }
    }
}

/**
 * A constructor that accept char*.
 * @param strC the value to set.
 */
InfInt::InfInt(const char * strC) {

    string str = strC;
    /* Checks if the input is valid, if it ain't use default values. */
    if (!isValidInput(str)) {
        _num = "0";
        _sign = false;
    } else {
        /**
        * If the first char is a number continue regularly.
        * else. check if its -/+ and adjust the _sign accordingly,
        * and set the value to the substring w/o the sign char.
        */
        if (isdigit(str[0])) {
            _num = str;
            _sign = false;
        } else {
            _sign = (str[0] == '-');
            _num = str.substr(1);
        }
    }
}

/**
 * A constructor that accept long.
 * @param val the value to set.
 */
InfInt::InfInt (long val) {
    /* Converting long to string */
    string temp = to_string(val);

    /**
     * If the first char is a number continue regularly.
     * else. check if its -/+ and adjust the _sign accordingly,
     * and set the value to the substring w/o the sign char.
     */
    if (isdigit(temp[0])) {
        _num = temp;
        _sign = false;
    } else {
        _num = temp.substr(1);
        _sign = (temp[0] == '-');
    }
}

/**
 * Copying InfInt object properties to a new object.
 * @param original The object to copy from.
 */
InfInt::InfInt(const InfInt& original) {
    this->setNum(  original.getNum()  );
    this->setSign( original.getSign() );
}

/* Input Validation */
/**
 * Checks if the input is valid.
 * @param str the input to check.
 * @return bool - is input valid.
 */
bool InfInt::isValidInput(string & str) {

    /* If the number begins with a sign, save it and work w/o it. */
    char tempChar = '+';
    if (str[0] == '-' || str[0] == '+') {
        tempChar = str[0];
        str = str.substr(1);
    }

    /* Removes all the '0's before the actual value begins. */
    while (str[0] == '0') {
        str = str.substr(1);
    }

    /* Checks that all the remaining chars are digits. */
    for (char a : str) {
        if (!(std::isdigit(a))) {
            return false;
        }
    }

    /* If we deleted all the zeroes and nothing is left, keep one zero. */
    if (str.length() == 0) {
        str += "0";
    }

    /* Adding back the sign value. */
    str = tempChar + str;

    return true;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* Getters and Setters */
/**
 * Returns the number.
 * @return _num value.
 */
string InfInt::getNum() const {
    string number = _num;
    return number;
}

/**
 * Sets the value of _num.
 * @param newNum the new value.
 */
void InfInt::setNum(string newNum) {
_num = newNum;
}

/**
 * Returns the sign of the number..
 * @return bool value.
 */
bool InfInt::getSign() const {
    return _sign;
}

/**
 * Sets the value of the sign.
 * @param newSign the new value.
 */
void InfInt::setSign(bool newSign) {
    _sign = newSign;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* Operators overload. */

/**
 * Checks if the two objects are equal.
 * @param b the IntInt to compare to.
 * @return bool - if the two objects are equal.
 */
bool InfInt::operator==(const InfInt b) const {
    return ((this->_num ==(b.getNum())) && (this->_sign == b.getSign()));
}

/**
 * Checks if the two objects are unequal.
 * @param b the IntInt to compare to.
 * @return bool - if the two objects are unequal.
 */
bool InfInt::operator!=(const InfInt b) const {
    return (!(*this == b));
}

/**
 * Checks if this is smaller than b.
 * @param b the IntInt to compare to.
 * @return bool - if this<b.
 */
bool InfInt::operator<(const InfInt b) const {

    if ((this->_sign) && (b.getSign())) { /* both negative. */
        /* Check which one is longer. */
        if (this->_num.length() < b.getNum().length()) {
            return false;
        } else if (this->_num.length() > b.getNum().length()) {
            return true;
        }
        /* If they have the same size, use the string operator. */
        return this->_num > b.getNum();
    } else if (!(this->_sign) && !(b.getSign())) { /* both positive. */
        /* Check which one is longer. */
        if (this->_num.length() < b.getNum().length()) {
            return true;
        } else if (this->_num.length() > b.getNum().length()) {
            return false;
        }
        /* If they have the same size, use the string operator. */
        return this->_num < b.getNum();
    } else if ((this->_sign) && (!b.getSign())) { /* this is negative and b isn't. */
        return true;
    } else if ((!this->_sign) && (b.getSign())) { /* this is positive and b isn't. */
        return false;
    }

}

/**
 * Checks if this is bigger than b.
 * @param b the IntInt to compare to.
 * @return bool - if this>b.
 */
bool InfInt::operator>(const InfInt b) const {
    /* if a<b and a=b are false, than a>b */
    return ((!(*this < b)) && (!(*this == b)));
}

/**
 * Checks of this is greater or equal to b.
 * @param b the IntInt to compare to.
 * @return bool - if this>=b.
 */
bool InfInt::operator>=(const InfInt b) const {
    return ((*this > b) || (*this == b));
}

/**
 * Checks of this is smaller or equal to b.
 * @param b the IntInt to compare to.
 * @return bool - if this<=b.
 */
bool InfInt::operator<=(const InfInt b) const {
    return ((*this < b) || (*this == b));
}

/**
 * Sums two numbers.
 * @param b the number to add to.
 * @return InfInt - the sum.
 */
InfInt InfInt::operator+(const InfInt b) const {

    /* Holds the new InfInt object */
    InfInt result;

    /* Both has the same sign. */
    if (this->_sign == b.getSign()) {
        string sum = plus(this->_num, b.getNum());
        result.setNum(sum);
        result.setSign(this->_sign);
    } else { /* Has different signs */
        /* this is positive and b is negative */
        if ( this->absoluteValue() > b.absoluteValue() ) {
            string temp = minus(this->_num, b.getNum());
            result.setNum(temp);
            result.setSign(this->_sign);
        } else if (this->absoluteValue() == b.absoluteValue()) {
            /* If the we have x-x the return 0. */
            result.setNum("0");
            result.setSign(false);
        } else { /* this is negative and b is positive */
            string temp = minus(b.getNum(), this->_num);
            result.setNum(temp);
            result.setSign(b.getSign());
        }
    }

    /* Making sure we won't get -0 value. */
    if (result.getNum() == "0") {
        result.setSign(false);
    }

    return result;
}

/**
 * Subtract two numbers.
 * @param b the number to subtract from.
 * @return InfInt - the difference.
 */
InfInt InfInt::operator-(const InfInt b) const {

    /* Change b's sign and use addition. */
    return (*this + b.negativeInfInt());
}

/**
 * Multiply two numbers.
 * @param b the number to multiply by.
 * @return InfInt - the product.
 */
InfInt InfInt::operator*(const InfInt b) const {

    InfInt result;

    string product = multiply(this->_num, b.getNum());
    result.setNum(product);

    /* if both have the same sign, the product is positive. */
    result.setSign((this->_sign != b.getSign()));

    /* Making sure we won't get -0 value. */
    if (result.getNum() == "0") {
        result.setSign(false);
    }

    return result;
}

/**
 * Divide two numbers.
 * @param b the denominator.
 * @return InfInt - the quotient.
 */
InfInt InfInt::operator/(const InfInt b) const {
    InfInt result;

    string quotient = divide(*this, b);
    result.setNum(quotient);

    /* if both have the same sign, the product is positive. */
    result.setSign((this->_sign != b.getSign()));

    /* Making sure we won't get -0 value. */
    if (result.getNum() == "0") {
        result.setSign(false);
    }

    return result;
}

/**
 * Gets the residue of two numbers.
 * @param b the denominator.
 * @return InfInt - the residue.
 */
InfInt InfInt::operator%(const InfInt b) const {
    InfInt remaining =  minus(this->_num, (((*this) / b) * b).getNum());

    /* if both have the same sign, the product is positive. */
    remaining.setSign((this->_sign != b.getSign()));

    /* Making sure we won't get -0 value. */
    if (remaining.getNum() == "0") {
        remaining.setSign(false);
    }

    return  remaining;
}

/**
 * Sums two numbers.
 * @param b the number to add.
 * @return InfInt - this + b's value.
 */
InfInt &InfInt::operator+=(const InfInt& b) {
    (*this) = (*this) + b;
    return (*this);
}

/**
 * Multiply two numbers.
 * @param b the number to multiply by.
 * @return InfInt - (this * b)'s value.
 */
InfInt &InfInt::operator*=(const InfInt &b) {
    (*this) = (*this) * b;
    return (*this);
}

/**
 * Increments the number.
 * @return Change the current object.
 */
InfInt& InfInt::operator++() {
    (*this) = (*this) + 1;
    return (*this);
}

/**
 * Increments the number.
 * @return The original value.
 */
InfInt InfInt::operator++(int) {
    InfInt original = (*this);
    (*this) = (*this) + 1;
    return original;
}

/**
 * Decrements the number.
 * @return Change the current object.
 */
InfInt &InfInt::operator--() {
    (*this) = (*this) - 1;
    return (*this);
}

/**
 * Decrements the number.
 * @return The original value.
 */
InfInt InfInt::operator--(int) {
    InfInt original = (*this);
    (*this) = (*this) - 1;
    return original;
}

/**
 * Doing biw-wise AND(&) between two numbers.
 * @param b The number to & with.
 * @return InfInt - AND(&) between two numbers.
 */
InfInt InfInt::operator&(const InfInt b) const {

    /* The InfInt as binary string. */
    string thisB = toBinary();
    string bB = b.toBinary();

    /* Holds the final binary string. */
    string result;
    InfInt answer;

    /* Making sure that the strings has the same length. */
    if(thisB.length() > bB.length()) {

        /* Filling the binary string with the correct char (0/1) */
        unsigned int delta = thisB.length() - bB.length();
        if (b.getSign()) {
            bB.insert(0, delta, '1');
        } else { // +ve
            bB.insert(0, delta, '0');
        }
    } else if (thisB.length() < bB.length()) {

        /* Filling the binary string with the correct char (0/1) */
        unsigned int delta = bB.length() - thisB.length();
        if (this->_sign) {
            thisB.insert(0, delta, '1');
        } else {
            thisB.insert(0, delta, '0');
        }
    }

    /* doing & on each pair of bits. */
    for (int i = 0; i < thisB.length(); ++i) {
        // AND
        if ( (thisB[i] == '1') && (bB[i] == '1') ) {
            result += '1';
        } else {
            result += '0';
        }
    }

    /* Checking if the result should be positive. */
    if ( (this->_sign) && (b.getSign()) ) { /* Both negative. */
        result.insert(0, 1, '1');
        answer.setSign(true);
    } else {
        result.insert(0, 1, '0');
    }

    /* Making sure we won't get -0 value. */
    if (result == "0") {
        answer.setSign(false);
    }

    /* Converting the binary string to a decimal string. */
    result = toDecimal(result);
    answer.setNum(result);

    return answer;
}

/**
 * Doing biw-wise OR(|) between two numbers.
 * @param b The number to | with.
 * @return InfInt - OR(|) between two numbers.
 */
InfInt InfInt::operator|(const InfInt b) const {

    /* The InfInt as binary string. */
    string thisB = toBinary();
    string bB = b.toBinary();

    /* Holds the final binary string. */
    string result;
    InfInt answer;

    /* Making sure that the strings has the same length. */
    if(thisB.length() > bB.length()) {

        /* Filling the binary string with the correct char (0/1) */
        unsigned int delta = thisB.length() - bB.length();
        if (b.getSign()) {
            bB.insert(0, delta, '1');
        } else { // +ve
            bB.insert(0, delta, '0');
        }
    } else if (thisB.length() < bB.length()) {

        /* Filling the binary string with the correct char (0/1) */
        unsigned int delta = bB.length() - thisB.length();
        if (this->_sign) {
            thisB.insert(0, delta, '1');
        } else {
            thisB.insert(0, delta, '0');
        }
    }

    /* doing | on each pair of bits. */
    for (int i = 0; i < thisB.length(); ++i) {
        // OR
        if ( (thisB[i] == '1') || (bB[i] == '1') ) {
            result += '1';
        } else {
            result += '0';
        }
    }

    /* Checking if the result should be positive. */
    if ( (this->_sign) || (b.getSign()) ) { /* if one or more is negative. */
        result.insert(0, 1, '1');
        answer.setSign(true);
    } else { /* else, the number is positive. */
        result.insert(0, 1, '0');
    }

    /* Making sure we won't get -0 value. */
    if (result == "0") {
        answer.setSign(false);
    }

    /* Converting the binary string to a decimal string. */
    result = toDecimal(result);
    answer.setNum(result);

    return answer;
}

/**
 * Doing biw-wise XOR(^) between two numbers.
 * @param b The number to ^ with.
 * @return InfInt - XOR(^) between two numbers.
 */
InfInt InfInt::operator^(const InfInt b) const {

    /* The InfInt as binary string. */
    string thisB = toBinary();
    string bB = b.toBinary();

    /* Holds the final binary string. */
    string result;
    InfInt answer;

    /* Making sure that the strings has the same length. */
    if(thisB.length() > bB.length()) {

        /* Filling the binary string with the correct char (0/1) */
        unsigned int delta = thisB.length() - bB.length();
        if (b.getSign()) {
            bB.insert(0, delta, '1');
        } else { // +ve
            bB.insert(0, delta, '0');
        }
    } else if (thisB.length() < bB.length()) {

        /* Filling the binary string with the correct char (0/1) */
        unsigned int delta = bB.length() - thisB.length();
        if (this->_sign) {
            thisB.insert(0, delta, '1');
        } else {
            thisB.insert(0, delta, '0');
        }
    }

    /* doing ^ on each pair of bits. */
    for (int i = 0; i < thisB.length(); ++i) {
        if ((thisB[i] != bB[i]) && ( (thisB[i] == '1') || (bB[i] == '1' ))) {
            result += '1';
        } else {
            result += '0';
        }
    }

    /* Checking if the result should be positive. */
    if ((this->_sign != b.getSign()) && ( (this->_sign) || (b.getSign()) )) { /* if one or more is negative. */
        result.insert(0, 1, '1');
        answer.setSign(true);
    } else { /* else, the number is positive. */
        result.insert(0, 1, '0');
    }

    /* Making sure we won't get -0 value. */
    if (result == "0") {
        answer.setSign(false);
    }

    /* Converting the binary string to a decimal string. */
    result = toDecimal(result);
    answer.setNum(result);

    return answer;
}

/**
 * Shifting this by b bites.
 * @param b the number of bites to shift.
 * @return InfInt - the result.
 */
InfInt InfInt::operator<<(const int b) const {

    /* Gets 2^b */
    InfInt twos("1");

    for (int i = 0; i < b; ++i) {
        twos = twos * 2;
    }

    /* Multiply 2^b * this */
    twos = (*this) * twos;

    return twos;
}

/**
 * Shifting this by b bites.
 * @param b the number of bites to shift.
 * @return InfInt - the result.
 */
InfInt InfInt::operator>>(const int b) const {

    /* Gets 2^b */
    InfInt twos("1");

    for (int i = 0; i < b; ++i) {
        twos = twos * 2;
    }

    /* Divide this / 2^b. */
    twos = (*this) / twos;

    return twos;
}

/**
 * Doing biw-wise AND(&) between two numbers.
 * @param b The number to & with.
 * @return InfInt& - sets this value to the AND(&) between the two numbers.
 */
InfInt& InfInt::operator&=(const InfInt b) {

    (*this) = ((*this) & b);
    return (*this);

}

/**
 * Shifting this by b bites.
 * @param b the number of bites to shift.
 * @return InfInt - sets this value to the result.
 */
InfInt InfInt::operator>>=(const int b) {
    (*this) = ((*this) >> b);
    return (*this);
}

/**
 * Adds b to the ostream.
 * @param stream the ostream to add to.
 * @param b The InfInt to add.
 * @return A reference to the ostream.
 */
ostream &operator<<(ostream& stream, const InfInt& b) {
    string print = b.getNum();
    stream << (b.getSign() ? "-" : "") << print;
    return stream;
}

/**
 * Gets an InfInt from the istream.
 * @param stream the istream to get the object from.
 * @param b The InfInt to initalize.
 * @return A reference to the istream.
 */
istream &operator>>(istream& stream, InfInt& b) {
    string input;
    stream >> input;
    b = InfInt(input);

    return stream;
}

/**
 * Allocating space for a new object.
 * @param size The number of bits we need.
 * @return A pointer to the new object.
 */
void *InfInt::operator new(size_t size) {

    /* Getting the space we need, and returns a pointer to the data. */
    void* pointer = malloc(size);
    return pointer;
}

/**
 * Deleting allocated space used for object.
 * @param pointer - A pointer to the object being deleted.
 */
void InfInt::operator delete(void* pointer) {
    free(pointer);
}

/**
 * Copying InfInt object properties to an existing object.
 * @param original - The object to copy from.
 * @return The object with his properties updated.
 */
InfInt& InfInt::operator=(const InfInt& original) {
    this->_num = ( original.getNum() );
    this->_sign = (original.getSign());
    return (*this);
}

/**
 * Converts an InfInt to an int.
 * @return  int - The int value of InfInt object.
 */
InfInt::operator int() const {

    /* Holds the current char in the number */
    char temp;

    /* Holds the final value. */
    int value = 0;

    /* Help multiply by 10^n. */
    int tens = 0;

    /* The string to convert. */
    string number = this->_num;

    /* Go digit by digit and put in the right spot. */
    for (int i = number.length() - 1; i >= 0; --i) {

        /* Making sure we won't get int overflow. */
        if (tens == 0) {
            tens = 1;
        } else {
            tens *= 10;
        }
        temp = number[i];
        value = ((int)temp - '0') * tens;
    }

    /* If negative make int negative too. */
    if (this->_sign) {
        value *= -1;
    }

    return value;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* Helpers methods. */

/**
 * Adding two numbers.
 * @param number1 the first number to add.
 * @param number2 the second number to add.
 * @return string - the sum of the numbers.
 */
string InfInt::plus(string number1, string number2) const {

    /* Holds the result. */
    string result;

    /* Holds the difference in sizes between the strings. */
    unsigned int delta = 0;

    /* Holds the carry value in the addition. */
    char carry = '0';

    /* Setting values for vars. */
    if (number1.length() > number2.length()) {
        delta = number1.length() - number2.length();
        result.insert(0, number1.length(), '0');
    } else {
        delta = number2.length() - number1.length();
        result.insert(0, number2.length(), '0');
    }

    /* Making sure that the strings has the same length. */
    if(number1.length() > number2.length()) {
        number2.insert(0, delta, '0');
    } else {
        number1.insert(0, delta, '0');
}

    /**
     * foreach char at each of the strings add its int value + the carry
     * value and convert back to char, if the result is bigger than 10
     * subtract 10 and add the result to the string.
     */
    for(int i = (number1.size() - 1); i >= 0; --i) {
        char tempChar = ((carry-'0')+(number1[i]-'0')+(number2[i]-'0')) + '0';
        if (tempChar > '9') {
            tempChar -= 10;
            carry = '1';
        } else {
            carry = '0';
        }
        result[i] = tempChar;
    }

    /* If we still have a carry value add '1' to the string. */
    if (carry != '0') {
        result.insert(0,1,'1');
    }

    return result;
}

/**
 * Subtract two numbers.
 * @param number1 the first number to subtract.
 * @param number2 the second number to subtract.
 * @return string - the difference of the numbers.
 */
string InfInt::minus(string number1, string number2) const {
    /* Holds the result. */
    string result;

    /* Holds the difference in sizes between the strings. */
    unsigned int delta = 0;

    /* Setting values for vars. */
    if (number1.length() > number2.length()) {
        delta = number1.length() - number2.length();
        result.insert(0, number1.length(), '0');
    } else {
        delta = number2.length() - number1.length();
        result.insert(0, number2.length(), '0');
    }

    /* Making sure that the strings has the same length. */
    if(number1.length() > number2.length()) {
        number2.insert(0, delta, '0');
    } else {
        number1.insert(0, delta, '0');
    }

    /**
     * foreach char i at each of the strings:
     * Check if number1[i] <= than number2[i].
     * if so, add 10 to number1[i] and subtract 1 from number1[i+1].
     * Subtract number1[i] -number2[i] and put the result at result[i].
     */
    for(int i = (number1.length() - 1); i >= 0; --i) {
        if(number1[i] < number2[i]) {
            number1[i] += 10;
            number1[i-1]--;
        }
        result[i] = ((number1[i]-'0')-(number2[i]-'0')) + '0';
    }

    /* Deleting all the zeroes before the value. */
    while(result[0] == '0') {
        result = result.substr(1);
    }

    return  result;
}

/**
 * Multiply two numbers.
 * @param number1 the first number to multiply.
 * @param number2 the second number to multiply.
 * @return string - the product of the numbers.
 */
string InfInt::multiply(string string1, string string2) const {

    string result;

    if (string1.length() > string2.length()) {
        string1.swap(string2);
    }

    /* foreach digit in string1, multiplication it in all the digits of string2 */
    for(int i=string1.length()-1; i>=0; --i) {

        /* Holds the value of the current product. */
        string temp;
        temp.insert(0, string2.length(), '0');

        /* Holds the current digit we multiplication by. */
        int currentDigit = string1[i]-'0';

        /* Holds the carry value from last product. */
        int carry = 0;

        /**
         * foreach digit in string2:
         * multiply two digits, save the carry and the result to temp.
         */
        for(int j=temp.length()-1; j>=0; --j) {

            /* Gets the current product. */
            char tempChar = ((string2[j]-'0') * currentDigit) + carry;

            /* Checks for the carry, and update the current product. */
            if(tempChar > 9) {
                carry = (tempChar/10);
                tempChar -= (carry*10);
            } else {
                carry = 0;
            }

            /* Adds the product to the temporary result. */
            tempChar += '0';
            temp[j] = tempChar;
        }

        /* If we still have carry add it now. */
        if(carry > 0) {
            temp.insert(0, 1, (carry+'0'));
        }

        /* Moving the string as to multiply it by 10^(i-1). */
        temp.append((string1.length()-i-1), '0');

        /* Summing the products. */
        result = plus(result, temp);
    }

    /* Deleting all the zeroes before the value. */
    while(result[0] == '0' && result.length()!=1) {
        result.erase(0,1);
    }

    return result;
}

/**
 * Divide two numbers.
 * @param number1 the numerator .
 * @param number2 the denominator.
 * @return string - the quotient of the numbers.
 */
string InfInt::divide(InfInt number, InfInt divisor) const {

    /* If there is a try to divide by zero abort. */
    if (divisor.getNum() == "0") {
        return number.getNum();
    }

    /* Checks for quick solutions. */
    if (number.absoluteValue() < divisor.absoluteValue()) {
        return "0";
    } else if (number.absoluteValue() == divisor.absoluteValue()) {
        return "1";
    }
    if (divisor.getNum() == "1") {
        return number.getNum();
    }


    /* Holds the final result. */
    string result;

    /* Holds the current iteration result. */
    string temp;

    /* An index to go throughout the number. */
    unsigned int i = 1;

    /* Initializing the dividend. */
    InfInt dividend("0");

    /* Finding the first dividend. */
    while (dividend < divisor.absoluteValue()) {
        temp = number.getNum().substr(0, i);
        dividend.setNum(temp);
        i++;
    }

    /* Resetting values. */
    temp = "";
    i--;

    /*
     * While we are not in the last digit of number:
     * divide the numbers using the long division method.
    */
    while (i <= number.getNum().length()) {

        string longDivResult = longDivide(dividend.absoluteValue(), divisor.absoluteValue());
        string remainder = minus(dividend.getNum(), multiply(longDivResult, divisor.getNum()));
        temp = remainder + number.getNum()[i];
        dividend.setNum(temp);

        result += longDivResult;
        i++;
    }

    return result;
}

/**
 * Divide two InfInts by subtracting the smaller from the bigger.
 * @param number The numerator.
 * @param divisor The denominator.
 * @return string - number / divisor.
 */
string InfInt::longDivide(InfInt number, InfInt divisor) const {
    /* A limitless counter. */
    InfInt counter;

    /* Subtracting the divisor from the number until the divisor is bigger */
    while (number >= divisor) {
        number = minus(number.getNum(), divisor.getNum());
        ++counter;
    }

    return counter.getNum();
}

/**
 * Returns the absolute value of InfInt.
 * @return the absolute value of InfInt.
 */
InfInt InfInt::absoluteValue() const {
    return InfInt(this->_num);
}

/**
 * Checking how many bits we need to represent this->_num.
 * @return InfInt - the # of bits we need to represent this->_num.
 */
InfInt InfInt::bitsRequired() const {

    /* Gets the InfInt absolute value. */
    InfInt abs = this->absoluteValue();

    InfInt twos("1");
    while ( twos < abs ) {
        twos = twos * 2;
    }

    /* two = two^(n+1) */
    twos = twos * 2;

    return twos;
}

/**
 * Flips the sign of a InfInt.
 * @return InfInt - The result.
 */
InfInt InfInt::negativeInfInt() const {
    InfInt negative;
    negative.setSign(!this->getSign());
    negative.setNum(this->_num);
    return negative;
}

/* Binary/Decimal convention. */

/**
 * Divide the number by two, and check for a remaining.
 * @param number The number to divide.
 * @return The quotient.
 */
string InfInt::longDivision(const string number) const {
    string answer;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < 2) {
        temp = temp * 10 + (number[++idx] - '0');
    }
    while (number.size() > idx) {
        answer += (temp / 2) + '0';
        temp = (temp % 2) * 10 + number[++idx] - '0';
    }
    if (answer.length() == 0) {
        return "0";
    }
    return answer;
}

/**
 * Reverse a string.
 * @param str
 */
void InfInt::reverseStr(string& str) const {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

/**
 * Get's a decimal string and returns a binary string.
 * @param str - A decimal string.
 * @return string - A binary string.
 */
string InfInt::toBinaryPositive(string& str) const {

    /* Holds the reversed result. */
    string binaryNumber;

    /* Using the /10 %10 method we saw in class. */
    while (str != "0") {
        char y = str.at(str.length() - 1);
        if (int(y)%2 == 0){
            binaryNumber += "0";
        } else {
            binaryNumber += "1";
        }
        str = longDivision(str);
    }

    /* reversing the string and returns it. */
    binaryNumber;
    reverseStr(binaryNumber);
    return binaryNumber;
}

/**
 * Get's a decimal string and returns a binary string.
 * @param str - A decimal string.
 * @return string - A binary string.
 */
string InfInt::toBinary() const {

    InfInt number = this->_num;

    /* If the number is negative, make it a positive with the same binary code. */
    if (this->getSign()) {

        /* gets the number of bits required for number. */
        InfInt twos = bitsRequired() ;

        number = twos + (*this);
    }

    string str2Con = number.getNum();
    return toBinaryPositive(str2Con);
}

/**
 * Convert binary string to decimal string.
 * @param str the string to convert.
 * @return string - a decimal string.
 */
string InfInt::toDecimal(string& str) const {

    /* The InfInt with the decimal value.  */
    InfInt dec;

    /* Used to calculate the decimal value. */
    InfInt twos("1");

    /*
     * foreach bit at index i, if bit=1 add 2^i to dec.
     * The MSB will be dealt with after the loop.
     */
    for (int j =  (str.length() - 1) ; j > 0; --j) {
        if (str[j] == '1') { /* need to add */
            dec += twos;
        }
        twos = twos * 2;
    }

    /* If the MSB is 1, the number is negative, add -(2^n). */
    if (str[0] == '1') {
        dec = dec - twos;
    }

    return dec.getNum();
}
