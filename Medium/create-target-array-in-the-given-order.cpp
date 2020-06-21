// https://leetcode.com/problems/create-target-array-in-the-given-order/
// Easy

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        
        list<int>ll;
        list<int>::iterator itr;
        
        int ind, val;
        for(int i = 0; i < nums.size(); i++) {
            val = nums[i]; ind = index[i];
            
            if(ll.empty() || ind >= ll.size()) ll.push_back(val);
            else {
                itr = ll.begin();
                while(ind--) itr++;
                ll.insert(itr, val);
            }
        }
        
        vector<int>result(ll.size());
        for(int i = 0; i < result.size(); ++i) {
            result[i] = ll.front();
            ll.pop_front();
        }
        
        return result;
    }
};