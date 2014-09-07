#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

//Functions use ASCII table values to convert from char to an int value
int convertCharTo10(char c) {
	//If its a number
	if ((c >= 48) && (c <= 57)) {
		return (c - 48);
	}

	//If its a character
	if ((c >=65) && (c <= 90)) {
		return (c - 55);
	}
}

char convertIntTo36(int x) {
	string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	return alphabet[x];
}

int convertTo10(string s) {
	int x = 0;
	int e = 0;

	for (int i = s.size()-1; i >= 0; i--) {
		x += convertCharTo10(s[i]) * pow(36, e);
		e++;
	}

	return x;
}

string convertTo36(int x) {
	string s = "";
	int e = 0;

	if (x == 0) return "0";

	while (x > 0) {
		s = convertIntTo36(x%36) + s;

		x /= 36;
	}

	return s;
}

int main() {
	string a, b;

	cin >> a >> b;

	while ((a != "0") && (b != "0")) {

		int x = convertTo10(a);
		int y = convertTo10(b);

		string s = convertTo36(x + y);

		cout << s << endl;

		cin >> a >> b;
	}

	return 0;
}