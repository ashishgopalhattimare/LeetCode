// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/monk-and-order-of-phoenix/description/
// Medium, Stack, Binary Search

#include <bits/stdc++.h>
using namespace std;

bool algorithm(stack<int>& random, vector<vector<int>>& arr)
{
	int prev = random.top();
	for(int i = arr.size()-1; i ; i--) {

		// Value strictly greater than prev value O(logn) binary search
		auto itr = upper_bound(arr[i].begin(), arr[i].end(), prev);
		if(itr == arr[i].end()) return false;
		prev = *itr;
	}
	return true;
}

int main() {

    int n, size;
    int Q, v, k, height;

    cin >> n;

    stack<int>rs; // to handle minstack so far
    vector<vector<int>>starr(n); // because k > 1 are sorted
    for(int i = 0; i < n; i++) {
        cin >> size;
        while(size--) {
            cin >> height;
            if(i == 0) { // create randomStack
                if(rs.empty())
                	rs.push(height);
                else
                	rs.push(min(rs.top(), height));
            }
            starr[i].push_back(height);
        }
    }

    cin >> Q;
    while(Q--) { // Queries
        cin >> v;

        switch(v) {
            case 1: // add height h to kth stack
                cin >> k >> height;
                if(n == 1 || k == 1) {
                	rs.push(min(rs.top(), height));
                }
                starr[k-1].push_back(height);

                break;

            case 0: // remove fighter from kth stack
                cin >> k;
                if(n == 1 || k == 1) rs.pop();
                starr[k-1].pop_back();

                break;

            case 2: // can use special wand or not
            	if(algorithm(rs, starr))
            		cout << "YES" << endl;
            	else
            		cout << "NO" << endl;
        }
    }

    return 0;
}

