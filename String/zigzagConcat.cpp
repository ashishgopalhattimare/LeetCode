#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/concatenation-of-zig-zag-string-in-n-rows/0

using namespace std;

void zigzagConcat(const string str, const int k)
{
    if(k == 1) {
        cout << str << endl;
        return;
    }
    
	vector< vector<char> > V;
	for(int i = 0; i < k; i++) {
	    vector<char> v;
	    V.push_back(v);
	}

	int row = 0, val = -1;
	for(int i = 0; i < str.length(); i++) {
		V[row].push_back(str[i]);

		if(row == k - 1 || row == 0) {
			val *= -1;
		}

		row = row + val;
	}

	for(int i = 0; i < k; i++) {
		for(int j = 0; j < V[i].size(); j++) {
			printf("%c", V[i][j]);
		}
	}
	printf("\n");
    
	return;
}

int main(int argc, char* argv[])
{
	int t, k;
	string str;

	cin >> t;
	while(t--) {
		cin >> str;
		cin >> k;

		zigzagConcat(str, k);
	}

	return 0;
}