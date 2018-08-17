// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > result;
        
        int l, r, sum;
        int prev = INT_MIN; // temporary prev used first number
        for(int i = 0; i < nums.size(); i++) {
            
            if (nums[i] == prev) continue; // if the previous first is current first number, go to next number
            
            prev = nums[i];
            
            l = i+1;
            r = nums.size()-1;
            
            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    vector<int> v;
                    // printf("%d,%d %d,%d %d,%d\n", nums[i],i, nums[l],l, nums[r],r);
                    v.push_back(nums[i]); v.push_back(nums[l]); v.push_back(nums[r]);
                    result.push_back(v);
                    
                    while(l < r) { // while next right-most is not equal to next-rightmost number
                        if(nums[r-1] == nums[r]) r--;
                        else break;
                    }
                    r--;
                    
                    continue;
                }
                
                if(sum > 0) r--;
                else l++;
            }
        }
        
        
        return result;
    }
};