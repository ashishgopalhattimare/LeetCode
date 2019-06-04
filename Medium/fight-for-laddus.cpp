// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/fight-for-laddus/
// Medium, Stack
// Hint : Closest max on right of index

#include <bits/stdc++.h>

using namespace std;

vector<int> algorithm(vector<int>& nums) {
	unordered_map<int,int>map;
	for(int x : nums) {
		map[x]++;
	}

	vector<int>result(nums.size(), -1);
	
	stack<int>st;
	for(int i = nums.size()-1; i >= 0; i--) {
	    while(!st.empty() && map[nums[i]] >= map[st.top()]) {
	        st.pop();
	    }
	    
	    if(!st.empty()) result[i] = st.top();
	    st.push(nums[i]);
	}
	return result;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int>arr(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		vector<int> result = algorithm(arr);

		for(int x : result) {
			cout << x << " ";
		}printf("\n");
	}

	return 0;
}
