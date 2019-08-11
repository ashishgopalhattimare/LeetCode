// https://leetcode.com/problems/score-after-flipping-matrix/
// Medium

class Solution {
public:
    
    void toggleCol(vector<vector<int>>& A, int col) {
        for(int i = 0; i < A.size(); i++) {
            A[i][col] ^= 1;
        }
    }
    
    int matrixScore(vector<vector<int>>& A) {
        
        // The Idea is to flip all the columns if only
        // the first col is 0 of each row
        
        for(vector<int>& x : A) {
            if(x[0] == 0) { // toggle all the bits
                for(int & y : x){
                    y ^= 1;
                }
            }
        }
        
        int countZero = 0, countOne = 0;
        for(int j = 1; j < A[0].size(); j++) { // traverse col of
            countZero = 0; countOne = 0;
            for(int i = 0; i < A.size(); i++){ // each row
                if(A[i][j] == 1) countOne++;
                else countZero++;
            }
            
            // I have more 0s than 1s, toggling the col would optimize the result
            if(countZero > countOne) toggleCol(A, j);
        }
        
        int result = 0;
        int value;
        for(int i = 0; i < A.size(); i++) {
            value = 0;
            for(int j = 0; j < A[0].size(); j++) {
                value = 2*value + (A[i][j] == 1);
            }
            result += value;
        }
        
        return result;
    }
};
