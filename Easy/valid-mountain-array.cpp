// https://leetcode.com/problems/valid-mountain-array/
// Easy

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        
        if(A.size() <= 2) return false;
        
        int prev = INT_MIN, i0 = 0, i1 = 0;
        
        for(i0 = 1; i0 < A.size(); i0++) if(A[i0-1] < A[i0]) break;
        if(i0 == A.size()) return false; // already sorted in descending order
        
        for(i0 = i1 = 0; i0 < A.size(); i0++) {
            if(prev < A[i0]) prev = A[i0];
            else break;
        }
        
        if(i0 == A.size()) return false; // already sorted in ascending order
        
        for(i1 = i0; i1 < A.size(); i1++) {
            if(prev > A[i1]) prev = A[i1];
            else return false;
        }
        return true;
    }
};
