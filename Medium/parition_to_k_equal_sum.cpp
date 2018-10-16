// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    
    bool algorithm(vector<int>& nums, int start, int ps, int sum, int k, int cp, vector<bool>&bel)
    {
        // if the current parts is equal to the number of parts required, return true
        if(cp == k) return true;
        
        // decide what should be on this currenSet
        for(int i = start; i < nums.size(); i++) {
            // if the current element does not belong to any set
            if (bel[i] == false){
                // add to current set total sum
                sum += nums[i];
                // make this set visited
                bel[i] = true;
                
                // since the num[i] cannot be 0, this is always possible
                // iff current set sum == required set sum
                if(sum == ps) { // next set making
                    // form the next set, start iterating the array from index 0 and current set
                    // sum = 0
                    if(algorithm(nums, 0, ps, 0, k, cp+1, bel)) {
                        return true;
                    }
                }
                
                // if the current Set sum is not equal to required sum
                // go to next index in the current set making
                else if(sum < ps) { // current set making
                    if(algorithm(nums, i+1, ps, sum, k, cp, bel)) {
                        return true;
                    }
                }
                
                // if the current num[i] cannot be in the current set
                bel[i] = false;
                sum -= nums[i];
            }
        }
        
        // not possible
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        if(k > nums.size()) return false;
        
        int sumTotal = 0;
        for(int x : nums) {
            sumTotal += x;
        }
        
        if(sumTotal % k) return false;
        
        int partSum = sumTotal / k;
        vector<bool> belongSet(nums.size(), false);
        
        return algorithm(nums, 0, partSum, 0, k, 1, belongSet);
    }
};
