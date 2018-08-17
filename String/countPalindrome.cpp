#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string/0

using namespace std;

int countPalindrome(const string str, const int n)
{
	int count = 0;
	int l, r;

	for(int i = 0; i < n - 1; i++) {
		
		// even length palindrome
		l = i; r = i+1;
		while(l >= 0 && r != n) {
			if(str[l] == str[r]) count++;
			else break;

			l--; r++;
		}

		// odd length palindrome
		l = i-1; r = i+1;
		while(l >= 0 && r != n) {
			if(str[l] == str[r]) count++;
			else break;

			l--; r++;
		}
	}

	return count;
}

int main(int argc, char* argv[])
{
	int t, n;
	string str;

	cin >> t;
	while(t--) {
		cin >> n;
		cin >> str;

		cout << countPalindrome(str, n) << endl;
	}

	return 0;
}