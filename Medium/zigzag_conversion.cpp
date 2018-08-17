// https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        
        vector<vector<char>>result;
        
        for(int i = 0; i < numRows; i++) {
            vector<char> v;
            result.push_back(v);
        }
        
        int factor = 1, currRow = 0;;
        numRows--;
        for(int i = 0; i < s.length(); i++) {
            if(factor == 1 && currRow == numRows) { // bottom row
                result[currRow].push_back(s[i]);
                factor = -1;
            }
            else if(factor == -1 && currRow == 0) { // top row
                result[currRow].push_back(s[i]);
                factor = 1;
            }
            else {
                result[currRow].push_back(s[i]);
            }
            currRow += factor;
        }
        
        string str = "";
        for(int i = 0; i < result.size(); i++) {
            for(int j = 0; j < result[i].size(); j++) {
                str.push_back(result[i][j]);
            }
        }
        
        return str;
    }
};