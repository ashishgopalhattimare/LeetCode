// https://leetcode.com/problems/keyboard-row/
// Easy

class Solution {
public:
    
    bool possible(string x, unordered_set<char>& set) {
        for(char i : x) {
            i = tolower(i);
            if(set.find(i) == set.end()) return false;
        }
        return true;
    }
    
    
    vector<string> findWords(vector<string>& words) {
        
        unordered_set<char>set1, set2, set3;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        for(char i : row1) set1.insert(i);
        for(char i : row2) set2.insert(i);
        for(char i : row3) set3.insert(i);
        
        vector<string>result;
        for(string x : words) {
            if(possible(x, set1) || possible(x, set2) || possible(x, set3)) {
                result.push_back(x);
            }
        }
        return result;
    }
};
