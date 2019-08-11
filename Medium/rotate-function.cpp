// https://leetcode.com/problems/rotate-function/
// Medium
// Good Question

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        long long n = A.size();
        
        long long sum = 0;
        for(int x : A) sum += x;
        
        long long temp = 0;
        for(int i = 0; i < n; i++) {
            temp += (A[i] * i);
        }
        
        long long maxim = temp;
        
        for(int i = n-1; i >= 0; i--) {
            temp = temp + sum - n * A[i];
            maxim = max(maxim, temp);
        }
        
        return maxim;
    }
};
