// Discussion
// https://leetcode.com/problems/previous-permutation-with-one-swap/discuss/300190/C-two-for-loops

// https://leetcode.com/problems/previous-permutation-with-one-swap/
// Medium

class Solution {
public:
    vector<int> prevPermOpt1(vector<int> A) {
        
        for(int i = A.size()-1; i >= 0; i--) {
            for(int j = i; j >= 1; j--) {
                if(A[j-1] < A[j]) continue;
                
                if(A[j-1] > A[i]) {
                    swap(A[j-1], A[i]);
                    return A;
                }
                
                break;
            }
        }
        
        return A;
    }
};
