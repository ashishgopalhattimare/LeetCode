#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/longest-even-length-substring/0

using namespace std;

int main(int argc, char* argv[])
{
	int t, l, r;
	int suml, sumr;
	int maxRange, gl, gr;
	string str;

	cin >> t;
	while(t--) {
		cin >> str;

		maxRange = -1;

		gl = gr = -1;
		for(int i = 0; i != str.length() - 1; i++) {
			l = i; r = i+1;

			suml = sumr = 0;
			while(l >= 0 && r < str.length()) {
				suml+=(str[l]-'0');
				sumr+=(str[r]-'0');

				if(suml == sumr && maxRange < r - l) {
					gl = l;
					gr = r;

					maxRange = r - l;
				} 

				l--; r++;
			}
		}

		printf("%d\n", maxRange + 1);
	}

	return 0;
}