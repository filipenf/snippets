/****
 * Code snippets for BCD->ASCII and ASCII->BCD conversion.
 *
 * */
#include <string>
#include <iostream>
#include <cstdint>

using namespace std;

/**
 * Given a std::string containing binary-coded-decimal values, convert it's
 * values to a string of ascii characters ( the numbers in ascii table ).
 * Example:
 * char data[] = { 0x18, 0x22, 0x11, 0x00 };
 * result = BCDToString(data); // implicit conversion
 * cout << result << endl;
 * It you return a string containing "812211";
 * */
string BCDToString(const string &src) {
    string dst;
    static const char BCD_ASCII_VALUES[] = "0123456789*#abc";
    for ( int i = 0; i < src.length(); i++ ) {
        dst.append(1, BCD_ASCII_VALUES[((unsigned char) src[i]) & 0x0f]);
        dst.append(1, BCD_ASCII_VALUES[((unsigned char) src[i]) >> 4]);
    }
    return dst;
}

/**
 * Given a string containing decimal numbers in ascii table, converts each 2
 * bytes in one BCD encoded byte ( example string "48" will become 0x84 )
 * */
string StringToBCD(const string &src) {
    string dst;
    for ( int i = 0; i < src.length(); i+=2 ) {
        dst.append(1, ((src.c_str()[i+1] - 0x30)<<4) | (src.c_str()[i] - 0x30));
    }
    return dst;
}


int main() {
    string result, result2;
    string ascii = "5548842870106";
    result = StringToBCD(ascii);
    cout << "StringToBCD = " << result << endl;
    cout << "BCDToString = " << BCDToString(result) << endl;
}

