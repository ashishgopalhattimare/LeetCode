// https://leetcode.com/problems/monotonic-array/
// Easy

class Solution {
public:
    
    bool monotonic(vector<int>& A, int f, int start, int end) {
        int prev = A[start];
        for(int i = start; i != end; i+=f) {
            if(prev <= A[i]) prev = A[i];
            else return false;
        }
        return true;
    }
    
    bool isMonotonic(vector<int>& A) {
        
        return monotonic(A, 1, 0, A.size()) || monotonic(A, -1, A.size()-1, -1);
    }
};