// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// Medium
// Easy, Just check whether this x word is forming all the chracters in the string

class Solution {
public:
    
    int DP[1002][1002];
    
    int longestCommonSubsequence(string word1, string word2)
    {
        int w1 = word1.length(), w2 = word2.length();
        
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
        
        return DP[w1][w2];
    }
    
    string bruteForce(string s, vector<string>& d) {
        string result = "";
        for(string x : d) {
            if(longestCommonSubsequence(s, x) == x.length()) {
                if(result == "") result = x;
                else if(result.length() < x.length()) {
                    result = x;
                }
                else if(result.length() == x.length() && result > x) {
                    result = x;
                }
            }
        }
        return result;
    }

    string sofarOptimal(string s, vector<string>& d) {
        string result = "";

        int k;
        for(string x : d) {
            if(x.length() > s.length()) continue;

            k = 0;
            for(int i = 0; i < s.length() && k < x.length(); i++) {
                k += (s[i] == x[k]);
            }

            if(k == x.length()) { // entire x word is in the s word given
                if(result.length() < x.length()) {
                    result = x;
                }
                else if(result.length() == x.length() && result > x) {
                    result = x;
                }
            }
        }

        return result;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        
        string result = sofarOptimal(s, d);
        return result;
    }
};
