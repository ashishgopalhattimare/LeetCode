// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

class Solution {
public:
    
    void subsetII(int index, vector<int>& nums, vector<int>& curr, vector<vector<int> >& result)
    {
        for(int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            
            if(find(result.begin(), result.end(), curr) == result.end()) {
                result.push_back(curr);
            }
            subsetII(i+1, nums, curr, result);
            
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        
        vector<int>curr;
        
        sort(nums.begin(), nums.end()); // after sorting the duplicate elements are in the same order
        
        result.push_back(curr);
        subsetII(0, nums, curr, result);
        
        return result;
    }
};
