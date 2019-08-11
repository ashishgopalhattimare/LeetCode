class Solution {
public:
    
    int binary_search(int start, int end, vector<int>& nums, int k) {
        if(start > end) return -1;
        
        if(start == end || end == start+1) {
            if(nums[end] == k) return end;
            if(nums[start] == k) return start;
            
            return -1;
        }
        
        int mid = start + (end-start)/2;
        
        if(k <= nums[mid]) return binary_search(start, mid, nums, k);
        return binary_search(mid, end, nums, k);
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>>result;
        
        // [0,0,0,0]
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            // if current ith element is same as previous ith element, skip
            if(i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            for(int j = i+1; j < nums.size(); j++) {
                // if current jth element is same as previous jth element, skip
                if(j != i+1 && nums[j] == nums[j-1])
                    continue;
                
                sum = nums[i] + nums[j];
                int k = 0 - sum;
                
                int start = binary_search(j+1, nums.size()-1, nums, k);
                if(start != -1) {
                    result.push_back({nums[i], nums[j], nums[start]});
                }
            }
        }
        
        return result;
    }
};
