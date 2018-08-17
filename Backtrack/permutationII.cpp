class Solution {
public:
    int temp;
    void permutation(int index, vector<int>& nums, vector<vector<int> >& result)
    {
        if(index == nums.size()) {
            if(find(result.begin(), result.end(), nums) == result.end()) {
                result.push_back(nums);
            }
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {    
            swap(nums[i], nums[index]);
            permutation(index+1, nums, result);
            swap(nums[i], nums[index]);
        }
        
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        
        permutation(0, nums, result);
        
        return result;
    }
};
