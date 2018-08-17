// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    
    int countStairs(int index, int n, vector<int>& arr)
    {
        if(index == n) return 1;
        if(index > n) return 0;
        
        // if the total number of possible combination at each level is not comsidered
        if(arr[index] == -1) {
            arr[index] = countStairs(index+1, n, arr) + countStairs(index+2, n, arr);
        }
        return arr[index];
    }
    
    int climbStairs(int n) {
        
        vector<int>arr(n+1, -1);
        
        return countStairs(0, n, arr);
    }
};