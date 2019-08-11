#include <bits/stdc++.h>

using namespace std;

vector<int> algorithm(vector<int>& nums)
{
    vector<int>result;
    int currMax = INT_MIN;
    for(int i = nums.size()-1; i >= 0; i--) {
        if(nums[i] > currMax) {
            result.push_back(nums[i]);
            currMax = nums[i];
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> nums = {1,4,55,45,2,5};

    vector<int>result = algorithm(nums);
    for(int x : result) {
        cout << x << " ";
    }
    printf("\n");

    return 0;
}