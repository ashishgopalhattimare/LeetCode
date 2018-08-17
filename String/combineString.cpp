#include <bits/stdc++.h>

// done - easy - string
// https://practice.geeksforgeeks.org/problems/roll-the-characters-of-a-string/0

using namespace std;

void rotateChar(vector<char>& c, int index, int rotate)
{
	int asciipos = c[index] - 'a';

	if(asciipos + rotate > 25) {
		c[index] = 'a' + (rotate - (25-asciipos) - 1);
	}
	else {
		c[index] += rotate;
	}

	return;
}

int main(int argc, char* argv[])
{
	int t, n, d, rotate;
	string str;

	vector<int>rise(10001);
	vector<char>c(10001);

	cin >> t;
	while(t--) {
		cin >> n;
		cin >> str;

		// string to vector char array
		for(int i = 0; i < str.length(); i++) {
			c[i] = str[i];
		}

		// algorithmic crush algo
		for(int i = 0; i <= n; i++) { rise[i] = 0; }

		// rise input
		for(int i = 0; i < n; i++) { 
			cin >> d;

			rise[0]++;
			rise[d]--;
		}

		rotate = 0;
		for(int i = 0; i < n; i++) {
			rotate += rise[i];
			
			rotateChar(c, i, rotate % 26);
		}

		for(int i = 0; i < n; i++) {
			printf("%c", c[i]);
		}
		printf("\n");

	}

	return 0;
}