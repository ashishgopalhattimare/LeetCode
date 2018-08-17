#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0

using namespace std;

int hasht[26];

void reset() {
	for (int i = 0; i < 26; ++i) {
		hasht[i] = 0;
	}
	return;
}

int main(int argc, char* argv[])
{
	int t;
	char c;
	int longDis, gl, gr, start;
	string str;

	cin >> t;
	while(t--) {
		cin >> str;

		longDis = INT_MIN;
		gl = gr = -1;

		start = 0;
		for(int i = 0; i < str.length(); i++) {
			c = str[i];
			hasht[c-'a']++;

			if(hasht[c-'a'] == 2) {
				while(true) {
					hash[str[start]-'a']--;

					if(str[start] == c) {
						start++;
						break;
					}
					start++;
				}
			}

			if(longDis < i-start) {
				longDis = i-start;
				gl = start;
				gr = i;
			}
		}

		for (int i = gl; i <= gr; ++i) {
			printf("%c", str[i]);
		}
		printf("\n");
	}

	return 0;
}