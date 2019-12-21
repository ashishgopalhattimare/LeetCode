// https://leetcode.com/problems/letter-case-permutation/
// Easy

class Solution {
public:
    
    void backtrack(vector<char>& str, int index, vector<string>& result) {
        
        if(index == str.size()) {
            string temp = "";
            for(char x : str) temp.push_back(x);
            
            result.push_back(temp);
            return;
        }
        
        if(isdigit(str[index])) backtrack(str, index+1, result);
        
        else { // alpha character
            str[index] = tolower(str[index]); backtrack(str, index+1, result);
            str[index] = toupper(str[index]); backtrack(str, index+1, result);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        
        vector<char>str(S.length());
        for(int i = 0; i < str.size(); i++) {
            str[i] = S[i];
        }
        
        vector<string>result;
        
        backtrack(str, 0, result);
        
        return result;
    }
};