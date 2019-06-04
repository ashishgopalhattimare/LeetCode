//============================================================================
// Name        : template.cpp
// Author      : Ashish Gopal Hattimare
// Problem     : Subsequence sum to K [index may repeat]
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

	vector<int> resultant;
	int minRange;

	void backtrack(vector<int>& nums, vector<int>& temp,
			int index, int sum, int k) {

		if(index == nums.size() || sum == k) {
			if(minRange > temp.size() && sum == k) {
				minRange = temp.size();
				resultant = temp;
			}
			return;
		}
		if(sum > k) return;

		temp.push_back(nums[index]);
		backtrack(nums, temp, index, sum + nums[index], k);   // use the same index next time as well
		backtrack(nums, temp, index+1, sum + nums[index], k); // take this index and move to next index

		temp.pop_back();
		backtrack(nums, temp, index+1, sum, k); // ignore this index and move to next index

		return;
	}

	vector<int> subsetSumToK(vector<int> nums, int k) {

		minRange = INT_MAX;

		std::sort(nums.begin(), nums.end());
		vector<int>temp;

		backtrack(nums, temp, 0, 0, k);
		return resultant;
	}
};

int main()
{
	Solution sol;
	vector<int> result = sol.subsetSumToK({3,1,2,11}, 7);

	printf("[ ");
	for(int x : result) cout << x << " ";
	printf("]\n");

	return 0;
}

