// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// Hard

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int ROW = matrix.size(), COL = matrix[0].size();
        int maxSum = INT_MIN, sum;
        int subarray;
        
        vector<int>temp(ROW, 0);
        for(int left = 0; left < COL; left++) {
            
            for(int& x : temp) x = 0;
            for(int right = left; right < COL; right++) {
                
                for(int i = 0; i < ROW; i++) {
                    temp[i] += matrix[i][right];
                }
                
                set<int>mySet;
                subarray = 0; sum = INT_MIN;
                
                mySet.insert(0);
                for(int i = 0; i < ROW; i++) {
                    subarray += temp[i];
                    auto itr = mySet.lower_bound(subarray-k);
                    if(itr != mySet.end()) {
                        sum = max(sum, subarray - *itr);
                    }
                    mySet.insert(subarray);
                }
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
};
