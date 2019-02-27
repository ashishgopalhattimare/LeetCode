// https://leetcode.com/problems/minimum-falling-path-sum/submissions/

// dynamic programming ideology

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        int matrix[A.size()][A.size()];
        bool valid[A.size()][A.size()];
        
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A.size(); j++) {
                matrix[i][j] = valid[i][j] = 0;
            }
        }
        
        int maxLimit = A.size();
        
        for(int i = A.size()-1; i > 0; i--) {
            for(int j = A.size()-1; j >= 0; j--) {
                
                for(int k = -1; k != 2; k++) {
                    if(j+k != -1 && j+k != maxLimit) {
                        if(valid[i-1][j+k] == false) {
                            matrix[i-1][j+k] = A[i][j] + matrix[i][j];
                            valid[i-1][j+k] = true;
                        }
                        else {
                            if(matrix[i-1][j+k] > A[i][j] + matrix[i][j]) {
                                matrix[i-1][j+k] = A[i][j] + matrix[i][j];
                            }
                        }
                    }
                }
            }
        }
        
        int result = A[0][0] + matrix[0][0];
        for(int i = 0; i < A.size(); i++) {
            result = min(result, A[0][i] + matrix[0][i]);
        }
        
        return result;
    }
};