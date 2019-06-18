// https://leetcode.com/problems/array-nesting/submissions/
// Medium
// elements that are visited, dont visit them again
// as they well answer same output (loop formed)

class Solution {
public:
    
    int maxim = INT_MIN;
    
    void traverse(int source, vector<int>& nums, vector<bool>& visited, int l) {
        if(visited[source]) {
            maxim = max(maxim, l-1);
            return;
        }
        visited[source] = true;
        traverse(nums[source], nums, visited, l+1);
    }
    
    int arrayNesting(vector<int>& nums) {
        vector<bool>visited(nums.size(), false);
        
        int tempMax = nums.size();
        for(int i = 0; i < nums.size() && tempMax > maxim; i++, tempMax--) {
            if(!visited[i]) traverse(nums[i], nums, visited, 1);
        }
        
        return maxim;
    }
};
