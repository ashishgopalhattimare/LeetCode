#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/smallest-distant-window/0
// smallest distinct window

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
	int start;
	int current;
	int distinct;

	int smallWindow, gl, gr;

	string str;

	cin >> t;
	while(t--) {
		cin >> str;

		reset();
		distinct = 0;
		for(int i = 0; i < str.length(); i++) {
			if(hasht[str[i]-'a'] == 0) {
				distinct++;
			}
			hasht[str[i]-'a']++;
		}

		reset();

		start = current = 0;
		smallWindow = INT_MAX;
		for(int i = 0; i < str.length(); i++) {

			if(hasht[str[i]-'a'] == 0) {
				current++;
			}

			hasht[str[i]-'a']++;

			if(current == distinct) {
				while(hasht[str[start]-'a'] != 1) {
					hasht[str[start]-'a']--;
					start++;
				}

				if(smallWindow > (i - start)) {
					smallWindow = i - start;
					gl = start;
					gr = i;
				}

				hasht[str[start]-'a']--;
				current--;
				start++;
			}
		}

        int count = 0; // length of window required
		for (int i = gl; i <= gr; ++i) {
// 			printf("%c", str[i]);
            count++;
		}
		printf("%d\n", count);
	}

	return 0;
}