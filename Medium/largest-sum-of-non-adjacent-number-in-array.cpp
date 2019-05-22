#include <bits/stdc++.h>
using namespace std;

int maximumSum(vector<int>& nums)
{
	if(nums.size() == 0) return 0;

    int inc = nums[0], exc = 0;
	int new_exc;
	for(int i = 1; i < nums.size(); i++) {
        new_exc = (inc > exc) ? inc : exc;
        
		inc = exc + nums[i];
		exc = new_exc;
	}
	return max(inc, exc);
}

int main()
{
	vector<int> nums {5, 1, 1, 5};
	cout << maximumSum(nums) << endl;
	return 0;
}