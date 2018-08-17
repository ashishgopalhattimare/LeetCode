#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/extract-maximum/0

using namespace std;

int main(int argc, char* argv[])
{
	int t;
	int maxValue, value;
	string str;

	cin >> t;
	while(t--) {
		cin >> str;

		maxValue = value = 0;
		for(int i = 0; i < str.length(); i++) {
			if(isdigit(str[i])) {
				value *= 10;
				value += (str[i]-'0');
			}
			else {
				maxValue = max(maxValue, value);

				value = 0;
			}
		}

		maxValue = max(maxValue, value);

		cout << maxValue << endl;
	}

	return 0;
}