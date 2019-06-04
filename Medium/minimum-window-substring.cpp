// https://leetcode.com/problems/minimum-window-substring/submissions/
// Medium

class Solution {
public:
    
    int compare(vector<int>& curr, vector<int>& hash) {
        for(int i = 0; i < 256; i++)
            if(curr[i] < hash[i]) return 0;
        return 1;
    }
    
    string minWindow(string s, string t) {
        
        string result = "";
        
        if(t.length() > s.length()) return result;
        
        vector<int>hash(256, 0);
        vector<int>curr(256, 0);
        
        int different = 0;
        
        for(char x : t) {
            if(hash[x] == 0) different++;
            hash[x]++;
        }
        
        int len = INT_MAX, minim = -1, maxim = -1;
        
        int i = 0, start, diff = 0;
        while(i < s.length() && !hash[s[i]]) i++;
        
        start = i;
        for( ; i < s.length(); i++) {
            if(hash[s[i]]) {
                
                if(hash[s[i]] == ++curr[s[i]]) diff++;
                
                while(diff == different && compare(curr, hash)) {
                        
                    if(len > i-start+1) {
                        minim = start; maxim = i;
                        len = i-start+1;
                    }
                    int index = s[start++];
                    if(curr[index] == hash[index]) --diff;
                    curr[index]--;
                        
                    while(start < i) {
                        if(hash[s[start]]) break;
                        start++;
                    }
                }
            }
        }
        return (len == INT_MAX)? "" : s.substr(minim, len);
    }
};
