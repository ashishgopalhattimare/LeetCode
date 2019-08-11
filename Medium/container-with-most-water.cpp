// https://leetcode.com/problems/container-with-most-water/

// 2-pointer Approach
// Similar to maximum sum of two numbers
// Medium
// Brute Force O(n^2)
// Optimal O(n)

class Solution {
public:
    
    int bruteForce(vector<int>& height) {
        int maximArea = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = i+1; j < height.size(); j++) {
                maximArea = max(maximArea, (j-i) * min(height[i], height[j]));
            }
        }
        return maximArea;
    }
    
    int optimal(vector<int>& height) {
        
        int l = 0, r = height.size()-1;
        int maximArea = 0;
        while(l < r) {
            maximArea = max(maximArea, (r-l) * min(height[r], height[l]));
            
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maximArea;
    }
    
    int maxArea(vector<int>& height) {
        
        int maximArea;
        
        // maximArea = bruteForce(height);
        maximArea = optimal(height);
        
        return maximArea;
    }
};
