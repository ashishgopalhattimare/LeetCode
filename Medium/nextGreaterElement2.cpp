// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int maxIndex, maxim = 0;
        
        vector<int> result(nums.size());
        
        if(nums.size() == 0) return result;
        
        maxim = nums[0];
        maxIndex = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= maxim) {
                maxim = nums[i];
                maxIndex = i;
            }
        }
        
        stack<int>st;
        for(int i = maxIndex; i >= 0; i--) {
            while(!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            if(st.empty()) {
                result[i] = -1;
            }
            else {
                result[i] = st.top();
            }
            st.push(nums[i]);
        }
        
        for(int i = nums.size()-1; i > maxIndex; i--) {
            while(!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            if(st.empty()) {
                result[i] = -1;
            }
            else {
                result[i] = st.top();
            }
            st.push(nums[i]);
        }
        
        return result;
    }
};