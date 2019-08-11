// https://leetcode.com/problems/partition-array-for-maximum-sum/
// Medium
// DP

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        
        vector<int>maxDP(A.size(), 0);
        maxDP[0] = A[0]; // base case
        
        int currMax, maxim, counter;
        int index;
        
        for(int i = 1; i < A.size(); i++) {
            maxim = 0; currMax = A[i];
            
            index = i;
            for(int counter = 1; i-counter+1 >= 0 && counter <= K; counter++, index--) {
                currMax = max(currMax, A[index]);
                
                if(index == 0) {
                    maxim = max(maxim, counter * currMax);
                }
                else {
                    maxim = max(maxim, maxDP[index-1] + counter * currMax);
                }
            }
            maxDP[i] = maxim;
        }
        
        return maxDP[A.size()-1];
    }
};
