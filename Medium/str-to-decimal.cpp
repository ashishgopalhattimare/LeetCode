//============================================================================
// Name        : template.cpp
// Author      : Ashish Gopal Hattimare
// Problem     : String Decimal to Actual Decimal
//============================================================================

#include <bits/stdc++.h>
using namespace std;

long double strToDecimal(string str) {

	long double result = 0;
	int start = 0;

	while(start < str.length()) {
		if(str[start] == '.') {
			start++;
			break;
		}
		result = result * 10 + (str[start++]-'0');
	}

	long double divide = 10.0;

	while(start < str.length()) {
		result += ((str[start++]-'0')/divide);
		divide *= 10;
	}

	return result;
}

int main()
{
	string strDecimal = "12.11222";

	cout << strToDecimal(strDecimal) << endl;

	return 0;
}

