class Solution {
public:
    void combinationSum(int index, int sum, int target, vector<int>& candidates, vector<vector<int> >& result, vector<int>& arr)
    {
        if(sum > target) return;
        if(sum == target) {
            
            if(find(result.begin(), result.end(), arr) == result.end()) {
                result.push_back(arr);
            }
            return;
        }
        
        for(int i = index; i < candidates.size(); i++) {
            arr.push_back(candidates[i]);
            combinationSum(i+1, sum + candidates[i], target, candidates, result, arr);
            arr.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int> > result;
        vector<int> arr;
        
        sort(candidates.begin(), candidates.end());
        combinationSum(0, 0, target, candidates, result, arr);
        
        return result;
    }
};
