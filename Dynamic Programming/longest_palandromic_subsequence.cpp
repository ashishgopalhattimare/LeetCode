// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>>matrix;
        
        for(int i = 0; i < s.length(); i++) {
            vector<int>row(s.length());
            matrix.push_back(row);
        }
        
        for(int i = 0; i < s.length(); i++) {
            matrix[i][i] = 1;
        }
        
        for(int l = 2; l <= s.length(); l++){
            for(int i = 0; i < s.length()-l + 1; i++){
                int j = i + l - 1;
                if(l == 2 && s[i] == s[j]){
                    matrix[i][j] = 2;
                }else if(s[i] == s[j]){
                    matrix[i][j] = matrix[i + 1][j-1] + 2;
                }else{
                    matrix[i][j] = max(matrix[i + 1][j], matrix[i][j - 1]);
                }
            }
        }
        
        return matrix[0][s.length()-1];
    }
};