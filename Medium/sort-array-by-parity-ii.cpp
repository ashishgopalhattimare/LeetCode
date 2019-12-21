// https://leetcode.com/problems/sort-array-by-parity-ii/
// Easy

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        for(int i = 0, j = 1; i < A.size(); i+=2) {
            if(A[i] % 2 == 1) { // odd element found, should be even
                while(A[j] % 2 == 1) { // while j is not even
                    j+=2;
                }
                
                // I point to odd element, J point to even element
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};