// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-monk-and-balanced-parentheses/
// Medium, Stack

#include <bits/stdc++.h>
using namespace std;

int max (int x, int y) {
	return x > y ? x : y;
}

int main() {

	int n, d;
	cin >> n;

	int maxim = 0, balance = 0;

	stack<int>st, balanceset;

	while(n--) {
		cin >> d;
		if(d > 0) st.push(d);
		else {
			if(st.empty()) {
			    balance = 0;
			}
			else {
    			if(st.top() != abs(d)) { // not balanced
    			    
    			    // current int is not making it balanced, but it was before
    				maxim = max(maxim, balance << 1);
    			
    				while(!st.empty()) st.pop(); // empty the substring
                    
                    /* [1 -1 2 -2 3 -3] 4 -3 */
                    // Add up all the previous broken balanced set 
    				balance = 0;
    				while(!balanceset.empty()) {
    					balance += balanceset.top();
    					balanceset.pop();
    				}
    				maxim = max(maxim, balance); // now get the new maxim balance
    				balance = 0; // restart new substring of balanced set
    			}
    			else {
    			    st.pop(); // valid part of balanced substring
    			    balance++;// increment balance by 1
    			}
    			if(st.empty()) { // this makes a broken balanced set
    				balanceset.push(balance << 1);
    				balance = 0; // restart new substring of balanced set
    			}
			}
		}
	}

    // Get the current max balanced set
	maxim = max(maxim, balance << 1);
	balance = 0;
	
	// Check all the previous balanced broken set
	while(!balanceset.empty()) {
		balance += balanceset.top();
	    balanceset.pop();
	}
	maxim = max(maxim, balance);
	cout << maxim << endl;
    return 0;
}

