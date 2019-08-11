// https://leetcode.com/problems/shortest-completing-word/
// Easy

class Solution {
public:
    
    int licenseFreq[26] = {0}, currWord[26] = {0};
    
    bool possible(string& str) {
        for(char x : str) currWord[x-'a']++;
        
        for(int i = 0; i < 26; i++) {
            if(licenseFreq[i] > currWord[i]) {
                return false;
            }
        }
        return true;
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        for(char x : licensePlate) {
            if(isalpha(x)) licenseFreq[tolower(x)-'a']++;
        }
        
        string result = "";
        for(string x : words) {
            if(possible(x)) {
                if(result.length() == 0 || result.length() > x.length()) {
                    result = x;
                }
            }
            for(char a : x) currWord[a-'a']--;
        }
        
        return result;
    }
};
