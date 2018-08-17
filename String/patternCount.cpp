#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/101-pattern-count/0

using namespace std;

int main(int argc, char* argv[])
{
	int t, c;
	string str;

	bool start, end;

	cin >> t;
	while(t--) {
		cin >> str;

		start = false;

		c = 0;
		for(int i = 0; i < str.length(); i++) {
			if(str[i] != '0' && str[i] != '1') {
				start = false;
				continue;
			}
			else if(!start) {
				if(str[i] == '1' && i < str.length() - 1 && str[i+1] == '0') {
					start = true;
					i++;
				}
				continue;
			}
			else {
				if(str[i] == '1') {
					c++;
					i--; // <- important for 10101010001 cases
					start = false;
				}
			}
		}

		printf("%d\n", c);
	}

	return 0;
}
