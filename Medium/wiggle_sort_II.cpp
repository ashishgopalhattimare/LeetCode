// https://leetcode.com/problems/wiggle-sort-ii/description/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        vector<int> arr;
        for(int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i]);
        }
        
        sort(arr.begin(), arr.end());
        
        int k = nums.size()/2; // put the second half
        for(int i = 0; i < nums.size(); i+=2) {
            nums[i] = arr[k++]; // at alternate index
        }
        
        k = 0;// put the first half
        for(int i = 1; i < nums.size(); i+=2) {
            nums[i] = arr[k++]; // at alternate index
        }
    }
};