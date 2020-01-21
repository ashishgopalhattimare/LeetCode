// https://www.codechef.com/JAN20B/problems/BRKBKS
// Easy

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	int S, W1, W2, W3;
	int result, tempS;

	stack<int>st;

	cin >> t;
	while(t--) {

		cin >> S >> W1 >> W2 >> W3;

		st.push(W3); st.push(W2); st.push(W1);

		result = 0;
		while(!st.empty()) {
			tempS = S;

			while(!st.empty() && tempS >= st.top()) {
				tempS -= st.top();
				st.pop();
			}
			result++;
		}

		cout << result << endl;
	}
	return 0;
}