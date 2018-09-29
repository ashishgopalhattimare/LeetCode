// https://leetcode.com/problems/reverse-string-ii/description/

class Solution {
public:
    
    void swapArray(int start, int end, vector<char>& nums)
    {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++; end--;
        }
        return;
    }
    
    string reverseStr(string s, int k) {
        
        vector<char>nums;
        
        for(int i = 0; i < s.size(); i++) {
            nums.push_back(s[i]);
        }
        
        int i = 0;
        
        bool swapRange = true;
        while(i < nums.size()) {
            if(swapRange) {
                
                if(i+k >= nums.size()) {
                    swapArray(i, nums.size()-1, nums);
                }
                else {
                    swapArray(i, i+k-1, nums);
                }
            }
            swapRange = !swapRange;
            i+=k;
        }
        
        string result = "";
        for(char x : nums) {
            result.push_back(x);
        }
        
        return result;
    }
};
