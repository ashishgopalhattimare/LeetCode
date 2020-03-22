// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Easy

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int result = 0;
        bool found;
        for(int x : arr1) {
            found = false;
            for(int y : arr2) {
                if(abs(x-y) <= d) {
                    found = true;
                    break;
                }
            }
            if(!found) result++;
        }
        
        return result;
    }
};