#include <bits/stdc++.h>

using namespace std;

vector<int> prefixCompute(string pattern)
{
	vector<int>prefix(pattern.length(), 0);
	int len = 0;
	
	for(int i = 1; i < pattern.length(); i++) {
		if(pattern[len] == pattern[i]) {
			prefix[i] = ++len;
		}
		else {
			if(len == 0) prefix[i] = 0;
			else {
				len = prefix[len-1];
				i--;
			}
		}
	}
	
	return prefix;
}

int main() {
	
	vector<int>prefix = prefixCompute("acacabacacabacacac");
	for(int x : prefix) {
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}
