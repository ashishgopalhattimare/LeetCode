// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
// Easy

class Solution {
public:
    string freqAlphabets(string str) {
        
        list<int>arr;
        int f, s;
        
        for(char x : str) {
            if(x == '#') {
                s = arr.back(); arr.pop_back();
                f = arr.back(); arr.pop_back();
                
                arr.push_back(f*10+s);
            }
            else arr.push_back(x-'0');
        }
        
        string result = "";
        while(!arr.empty()) {
            result.push_back(arr.front()+'a'-1);
            arr.pop_front();
        }
        
        return result;
    }
};