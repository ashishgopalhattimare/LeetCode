// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
// Easy

class Solution {
public:
    
    string repeat(char x, int n) {
        string temp = "";
        while(n--) temp.push_back(x);
        return temp;
    }
    
    string generateTheString(int n) {
        
        if(n % 2 == 1) return repeat('a', n);
        else {
            return repeat('a', n-1) + "b";
        }
    }
};