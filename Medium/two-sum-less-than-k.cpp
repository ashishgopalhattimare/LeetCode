// https://leetcode.com/problems/two-sum-less-than-k/
// Complexity : O(n2)
// Could be solved in nlogn
// Easy
// Weekly Contest

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        
        int maxim = -1;
        for(int i = 0; i < A.size(); i++) {
            for(int j = i+1; j < A.size(); j++) {
                if(A[i]+A[j] < K) {
                    maxim = max(maxim, A[i]+A[j]);
                }
            }
        }
        
        return maxim; 
    }
};
