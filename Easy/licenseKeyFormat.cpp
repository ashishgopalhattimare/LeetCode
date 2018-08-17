// https://leetcode.com/problems/license-key-formatting/description/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string str = "";
        int count = 0;
        bool lastWord = true;
        
        vector<string> v;
        for(int i = S.size()-1; i >= 0; i--) {
            
            if(!isalnum(S[i])) continue;
            
            str.push_back(toupper(S[i]));
            count++;
            
            if(count == K) {
                // reverse the string because taken in reverse order
                reverse(str.begin(), str.end());

                // push into the vector
                v.push_back(str);
                
                str = "";
                count = 0;
            }
        }
        
        if(count != 0) {
            reverse(str.begin(), str.end());
            v.push_back(str);
        }
        
        string result = "";
        
        // if input is "---" for K = n
        if(v.size() == 0) return result;
        
        result.append(v[v.size()-1]);
        
        // append reverse order
        for(int i = v.size()-2; i >= 0; i--) {
            result.push_back('-');
            result.append(v[i]);
        }
        
        return result;
    }
};