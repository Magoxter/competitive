#include <iostream>
#include <math.h>

using namespace std;

int charToInt(char c) {
	const string alphabet = "abcdefghijklmnopqrstuvwxyz";
	const string capitalAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int x = 1;

	for (int i = 0; i < alphabet.size(); i++) {
		if (c == alphabet[i]) {
			x += i;
			return x;
		}
	}

	x += 26;

	for (int i = 0; i < capitalAlphabet.size(); i++) {
		if (c == capitalAlphabet[i]) {
			x += i;
			return x;
		}
	}

	//Should never get here
	return 0;
}

bool isPrime(string s) {
	int x = 0;

	//Doing the sum of the letters
	for (int i = 0; i < s.size(); i++) {
		x += charToInt(s[i]);
	}

	if (x == 1) return true;

	for (int i = 2; i <= sqrt(x); i++) {
		if ((x % i) == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	string s;

	while (cin >> s) {
		if ( isPrime(s) ) {
			cout << "It is a prime word." << endl;
		} else {
			cout << "It is not a prime word." << endl;
		}
	}

	return 0;
}