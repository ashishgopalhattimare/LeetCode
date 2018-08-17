#include <bits/stdc++.h>

using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-number-of-characters-between-any-two-same-character/0

int main(int argc, char* argv[])
{
	int t;
	int maxChar;
	string str;

	cin >> t;
	while(t--) {
		cin >> str;

		unordered_map<char, pair<int, int> > hash;

		for(int i = 0; i < str.length(); i++) {
			if(hash.find(str[i]) == hash.end()) {
				hash[str[i]] = make_pair(i, -1);
			}
			else {
				hash[str[i]].second = i;
			}
		}

		maxChar = -1;

		for(auto itr = hash.begin(); itr != hash.end(); itr++) {
			if((itr->second).second == -1) continue;
			
			maxChar = max(maxChar, (itr->second).second - (itr->second).first - 1);
		}

		printf("%d\n", maxChar);
	}

	return 0;
}