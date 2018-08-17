#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/longest-common-substring/0

using namespace std;

int matrix[101][101];

int countSubstring(string s1, string s2, int n1, int n2)
{
	int maxCount = 0;

	for(int i = 0; i < n2; i++) { // s2
		for(int j = 0; j < n1; j++) { // s1
			if(s2[i] == s1[j]) {
				if(i == 0 || j == 0) {
					::matrix[i][j] = 1;
				}
				else {
					::matrix[i][j] = ::matrix[i-1][j-1] + 1;
				}
				maxCount = max(maxCount, ::matrix[i][j]);
			}
			else {
				::matrix[i][j] = 0;
			}
		}
	}

	return maxCount;
}

int main(int argc, char* argv[])
{
	int t;
	int n1, n2;
	string s1, s2;

	cin >> t;
	while(t--) {
		cin >> n1 >> n2;
		cin >> s1 >> s2;

		cout << countSubstring(s1, s2, n1, n2) << endl;
	}

	return 0;
}