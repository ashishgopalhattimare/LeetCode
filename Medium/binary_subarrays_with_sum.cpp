// https://leetcode.com/contest/weekly-contest-108/problems/binary-subarrays-with-sum/

class Solution {
public:
    
    int zeroPermutation(vector<int>& A, int S) {
        
        int k = 0, ways = 0;
        for(int start = 0, end = 0; start < A.size() && end < A.size(); end++) {
            if(A[end]) {
                ways += (k*(k+1)/2);
                k = 0;
            }
            else k++;
        }
        
        return ways + (k*(k+1)/2);
    }
    
    int numSubarraysWithSum(vector<int>& A, int S) {
        
        int start = 0, end = 0, k;
        int sum = 0, ways = 0;
        
        if(S == 0) {
            return zeroPermutation(A, S);
        }
        
        while(start < A.size() && end < A.size()) {
            
            if(sum + A[end] == S) {
                ways++;
                for(k = end+1; sum + A[end] + A[k] == S && k < A.size(); k++) {
                    ways++;
                }
                
                sum-=A[start++];
            }
            else {
                sum += A[end++];
            }
        }
        
        return ways;
    }
};

/**

Input :

A = [0,0,0,0,0,0,1,0,0,0], S = 0
A = [1,0,1,0,1], S = 2

Output : 
27
4
**/
