// https://leetcode.com/problems/restore-ip-addresses/
// Medium
// Combinatorics

class Solution {
public:
    
    void generateIPAddresses(int index, string& s, vector<string>& result, vector<int>& comb) {
        
        if(index > s.length() || comb.size() > 4) return;
        if(index == s.length()) { // string over
            if(comb.size() == 4){ // if number of columns ae exactly 4
                string str = to_string(comb[0]);
                for(int i = 1; i < 4; i++) {
                    str.push_back('.');
                    str.append(to_string(comb[i]));
                }
                result.push_back(str);
            }
            return;
        }
        
        for(int i = index, value = 0; i < s.length(); i++)
        {
            value = value*10 + (s[i]-'0');
            
            if(value > 255) return;
            
            comb.push_back(value);
            generateIPAddresses(i+1, s, result, comb);
            comb.pop_back();
            
            if(value == 0) break; // consider 0 value only once
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string>result;
        vector<int>comb;
        generateIPAddresses(0, s, result, comb);
        
        return result;
    }
};
