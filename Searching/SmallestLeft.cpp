#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
	int n, d;
	vector<int> ar;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> d;
		ar.push_back(d);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", ar[i]);
	}
	printf("\n");

	stack<int> st;
	vector<int>result(n, 0);
	for(int i = n-1; i >= 0; i--) {
		while(!st.empty() && ar[i] < ar[st.top()]) {
			result[st.top()] = ar[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}