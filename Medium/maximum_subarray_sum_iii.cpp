#include <bits/stdc++.h>

using namespace std;

#define lli long long int

class Solution {
public:

    lli max(lli x, lli y) {
        return (x > y) ? x : y;
    }

    lli min(lli x, lli y) {
        return (x < y) ? x : y;
    }

    lli bruteForce(vector<int>& nums)
    {
        lli result = 0;
        lli sum, prev;

        bool allNegative = true;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                allNegative = false;
                break;
            }
            result = min(result, nums[i]);
        }
        if(allNegative) return result * result;

        result = 0;
        for(int i = 0; i < nums.size(); i++) {

            nums[i] = pow(prev = nums[i], 2);
            sum = 0;
            for(int j = 0; j < nums.size(); j++) {
                sum += nums[j];
                if(sum < 0) sum = 0;

                result = max(result, sum);
            }
            nums[i] = prev;
        }

        return result;
    }

    lli maximumSubarraySum(vector<int>& nums)
    {
        lli result = 0;
        lli sum, prev;

        bool allNegative = true;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                allNegative = false;
                break;
            }
            result = min(result, nums[i]);
        }
        // If all the values are negative
        if(allNegative) return result * result;

        vector<lli>maximumSum(nums.size()); // Kadane algo
        vector<lli>prefixSum(nums.size());  // prefix algo

        result = sum = 0;
        for(int j = 0; j < nums.size(); j++) {

            // Prefix Sum of the array
            if(j == 0) prefixSum[j] = nums[j];
            else {
                prefixSum[j] = prefixSum[j-1] + nums[j];
            }

            // Kadane Algorithm
            sum += nums[j];
            if(sum < 0) sum = 0;

            maximumSum[j] = result = max(result, sum);
        }

        for(lli x : maximumSum) {
            cout << x << " ";
        }printf("\n");

        for(lli x : prefixSum) {
            cout << x << " ";
        }printf("\n");

        return result;
    }
};

int main() {
    Solution *solution = new Solution();

    vector<int> nums{1,-6,3};

    cout << solution->bruteForce(nums) << endl;
    cout << solution->maximumSubarraySum(nums) << endl;
    
    return 0;
}

/*

< Motivation >

This question was recently asked in my university on-campus Amazon coding round for
Software Engineer position. I tried spending 30 min on it, but still tried solving it
after it was over.
The question was very unique to all the questions i came across in LeetCode so far.
I think the question would be very useful for the community and its users to
experience such type of questions as it would give them an exposure to use different
concepts together to solve such problems. I think question would be LeetCode Medium.

-------------------------------------

< Question >

Given an array of integers. You can almost square one value from the given array.
Find the maximum subarray sum possible.

< Input >

The first line of the input contains a single integer N denoting the number of
integers in the array.
The second line contains N space-separated integers A1, A2, . . . , AN

< Output >

Return the maximum subarray sum possible.

< Contraints >

1 ≤ N ≤ 105
1 ≤ Ai ≤  for each valid i

*/