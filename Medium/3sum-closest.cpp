// https://leetcode.com/problems/3sum-closest/
// Medium

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int l, r, sum;
        
        int minDiff = INT_MAX;
        int result = 0;
        for(int i = 0; i < n; i++) {
            l = i+1; r = n-1;
            
            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];
                
                if(minDiff > abs(target-sum))
                {
                    minDiff = min(minDiff, abs(target-sum));
                    result = sum;
                }
                
                if(target == sum) return sum;
                else if(sum < target) l++;
                else r--;
            }
        }
        
        return result;
    }
};
