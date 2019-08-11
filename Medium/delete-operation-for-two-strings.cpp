// https://leetcode.com/problems/delete-operation-for-two-strings/
// Medium
// Logic : Longest Common Subsequence

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int w1 = word1.length(), w2 = word2.length();
        int DP[w1+1][w2+1];
        
        for(int i = 0; i <= w1; i++) {
            for(int j = 0; j <= w2; j++) {
                DP[i][j] = 0;
            }
        }
        
        for(int i = 1; i <= w1; i++) {
            for(int j = 1; j <= w2; j++) {
                if(word1[i-1] == word2[j-1]) {
                    DP[i][j] = DP[i-1][j-1] + 1;
                }
                else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
        
        return (w1 + w2) - 2*DP[w1][w2];
    }
};
