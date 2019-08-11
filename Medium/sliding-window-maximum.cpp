// https://leetcode.com/problems/sliding-window-maximum/
// Hard

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if(k <= 0) return {};
        if(k == 1) return nums;
        
        vector<int>result;
        list<int>ll;
        int i = 0;
        
        while(i < k && i < nums.size()) {
            while(!ll.empty() && nums[ll.back()] <= nums[i])
                ll.pop_back();
            ll.push_back(i++);
        }
        result.push_back(nums[ll.front()]);
        
        i = 0;
        while(k < nums.size()) {
            while(ll.front() == i) ll.pop_front();
            while(!ll.empty() && nums[ll.back()] <= nums[k])
                ll.pop_back();
            ll.push_back(k++);
            
            result.push_back(nums[ll.front()]);
            i++;
        }
        
        return result;
    }
};
