// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        
        vector<vector<int>> matrix;
        
        for(int i = 0; i < B.size(); i++) {
            vector<int>row(A.size());
            matrix.push_back(row);
        }
        
        int maxLength = 0;
        
        for(int j = 0; j < A.size(); j++) {
            matrix[0][j] = (B[0] == A[j]);
            
            maxLength = max(maxLength, matrix[0][j]);
        }
        for(int i = 0; i < B.size(); i++) {
            matrix[i][0] = (B[i] == A[0]);
            
            maxLength = max(maxLength, matrix[i][0]);
        }
        
        for(int i = 1; i < B.size(); i++) {
            for(int j = 1; j < A.size(); j++) {
                if(B[i] == A[j]) {
                    matrix[i][j] = matrix[i-1][j-1] + 1;
                }
                else {
                    matrix[i][j] = 0;   
                }
                
                maxLength = max(maxLength, matrix[i][j]);
            }
        }
        return maxLength;
    }
};