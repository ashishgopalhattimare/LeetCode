// https://leetcode.com/problems/4sum/
// Medium
// O(n^3)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>result;
        
        sort(nums.begin(), nums.end());
        
        int l, r, sum;
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i-1] == nums[i]) continue; // try to remove duplicate
            
            for(int j = i+1; j < nums.size(); j++) {
                if(j != i+1 && nums[j-1] == nums[j]) continue; // try to remove duplicate
                
                l = j+1; r = nums.size()-1;
                
                while(l < r) {
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});

                        while(l < r && nums[l] == nums[l+1]) {
                            l++;
                        }
                        l++;
                        while(l < r && nums[r-1] == nums[r]) {
                            r--;
                        }
                        r--;
                    }
                    else if(sum < target) l++;
                    else r--;
                }
            }
        }
        
        return result;
    }
};
