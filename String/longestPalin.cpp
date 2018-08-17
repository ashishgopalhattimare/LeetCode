#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
	int t, l, r;
	int maxPalin, gl, gr;
	string str;

	cin >> t;

	while(t--) {
		cin >> str;

		gl = gr = -1;
		maxPalin = INT_MIN;
		for(int i = 0; i < str.length(); i++) {

			// odd length palin
			l = i-1;
			r = i+1;

			while(l >= 0 && r < str.length()) {
				if(str[l] == str[r]) {
					if(maxPalin < r-l+1) {
						maxPalin = r-l+1;
						gl = l;
						gr = r;
					}
					l--; r++;
				}
				else break;
			}

			// even length palin
			l = i;
			r = i+1;
			
			while(l >= 0 && r < str.length()) {
				if(str[l] == str[r]) {
					if(maxPalin < r-l+1) {
						maxPalin = r-l+1;
						gl = l;
						gr = r;
					}
					l--; r++;
				}
				else break;
			}
		}

		if(gl == -1) { // no palindrome of length >= 2
		    printf("%c\n", str[0]);
		}
		else {
			for (int i = gl; i <= gr; ++i)
			{
				printf("%c", str[i]);
			}
			printf("\n");
		}
	}

	return 0;
}