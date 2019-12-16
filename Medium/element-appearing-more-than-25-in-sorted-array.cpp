// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Easy

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int minFreq = ceil(0.25 * arr.size());
        
        if(minFreq == 0.25 * arr.size()) {
            minFreq++;
        }
        
        if(arr.size() == 1) return arr[0];
        
        int count = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i-1] == arr[i]) {
                count++;
            }
            else count = 1;
            
            if(count >= minFreq) return arr[i];
        }
        return -1;
    }
};