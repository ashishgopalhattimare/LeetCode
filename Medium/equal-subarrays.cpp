// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/equal-subarrays-cf01a26a/
// Medium
// Segment Tree, Sliding Window Problem, Accumulative Sum

#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int main()
{
	int N;
	lli K;

	cin >> N >> K;

	vector<lli>arr(N);
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	map<lli,int>mapi;
	int l = 0, r = 0, result = 0;

	lli stretch, maxVal, sum = 0;
	while(r < N)
	{
		mapi[arr[r]] += 1;		// Increment Frequency by 1 O(logN)
		sum += arr[r];			// Total sum of the current subarray
		stretch = abs(r-l)+1;	// Get the stretch of the window

		maxVal = mapi.rbegin()->first; // Get the maximum element
		while(mapi.size() && abs(maxVal*stretch - sum) > K)
		{
			if(mapi[arr[l]] == 1) { // If the freq of arr[l] is 1, erase it
				mapi.erase(arr[l]);
			}
			else mapi[arr[l]]--;	// decrement the frequency by 1

			sum -= arr[l];			// subtract it from the current subarray
			l++;					// reduce window size by 1 from left pointer

			// Consider next maximum element
			if(mapi.size() > 0) maxVal = mapi.rbegin()->first;
			stretch = abs(r-l)+1; 	// re-compute the stretch
		}

		// Valid Subarray with Increment Equal  <= K
		if(l <= r) result = max(result, abs(r-l)+1);

		r++; // move right pointer
	}

	cout << result << endl;

	return 0;
}