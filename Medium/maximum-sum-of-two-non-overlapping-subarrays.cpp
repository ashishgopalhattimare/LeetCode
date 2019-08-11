// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
// Medium
// Easy, Index Maintain Problem

class Solution {
public:
    
    int maximumSubarray(vector<int>& A, int first, int second) {
        
        int start1, sum1 = 0, sum2;
        int start2, k1, k2;
        int maxim =INT_MIN;
        
        k1 = start1 = 0;
        while(start1 < first) sum1 += A[start1++]; // sum1 of first n elements
        
        for( ; start1 <= A.size()-second; start1++) {
            k2 = start2 = start1;
            sum2 = 0;
            for(int i = 0; i < second; i++) { // sum2 of second m elements
                sum2 += A[start2++];
            }
            
            maxim = max(maxim, sum1 + sum2); // take the max
            // cout << sum1 << " " << sum2 << endl;
            
            sum2 -= A[k2++]; // remove the k2 index
            for( ; start2 < A.size(); start2++) { // while not the end of array
                sum2 += A[start2]; // append start2 index element
                
                // cout << sum1 << " " << sum2 << endl;
                
                maxim = max(maxim, sum1 + sum2);
                sum2 -= A[k2++]; // remove k2 index element
            }
            sum1 += (A[start1] - A[k1++]); // remove k1 index and append start1 index element
        }
        
        return maxim;
    }
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        
        // We may take M elements and then L elements or vise-versa
        return max(maximumSubarray(A, L, M), maximumSubarray(A, M, L));
    }
};
