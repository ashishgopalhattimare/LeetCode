// https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    
    int maxSubArraySum(vector<int>& A, int start, int len) 
    { 
        int max_so_far = INT_MIN, max_ending_here = 0; 

        for (int i = start; i < len; i++) 
        { 
            max_ending_here = max_ending_here + A[i]; 
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
            }

            if (max_ending_here < 0) 
                max_ending_here = 0; 
        } 
        return max_so_far; 
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        
        int len = A.size();
        int result = INT_MIN;
        int total = 0;
        
        int positiveCount = 0;
        for(int i = 0; i < A.size(); i++) {
            positiveCount += (A[i] > 0);
            result = max(result, A[i]);
            total += A[i];
        }
        
        if(positiveCount == len) return total;
        if(positiveCount == 0) return result;
        
        
        for(int i = 0; i < len-1; i++) {
            A.push_back(A[i]);
        }
        
        for(int i = 0; i < len; i++) {
            if(A[i] <= 0) continue;
            result = max(result, maxSubArraySum(A, i, len+i));
        }
        
        return result;
    }
};
