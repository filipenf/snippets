/*
 * =====================================================================================
 *
 *       Filename:  gcd.cpp
 *
 *    Description:  implementation of the Euclid's algorithm to find the gcd (
 *					greatest common divisor ) of 2 numbers
 *
 *        Version:  1.0
 *        Created:  14/03/2013 11:51:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Filipe N. Felisbino (fnf), filipenf@gmail.com
 *        Company:  IM Control Systems
 *
 * =====================================================================================
 */

#include <iostream>

using std::endl;
using std::cout;

int recursive_gcd(int a, int b) {
	if ( a <= 0 || b <= 0 ) return 0;
	if ( a == b ) return a;
	int dv = a % b;
	if ( dv == 0 ) return b;
	else return (recursive_gcd(b, dv));
}

int iterative_gcd(int a, int b) {
	if ( a <= 0 || b <= 0 ) return 0;
	if ( a == b ) return a;
	while ( b != 0 ) {
		int dv = a % b;
		a = b;
		b = dv;
	}
	return a;
}

int main(int argc, char* argv[]) {
	if ( argc < 3 ) {
		cout << "usage: " << argv[0] << " number number" << endl;
		return -1;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	cout << "The GCD of " << argv[1] << " and " << argv[2] << " is: " << endl <<
		" recursive: " << recursive_gcd(a, b) << endl <<
		" iterative: " << iterative_gcd(a, b) << endl;
}
