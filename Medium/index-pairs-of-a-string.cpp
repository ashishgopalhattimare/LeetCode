// https://leetcode.com/contest/biweekly-contest-1/problems/index-pairs-of-a-string/
// Easy

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        unordered_set<string>set;
        for(string x : words) {
            set.insert(x);
        }
        
        vector<vector<int>>result;
        
        for(int i = 0; i < text.length(); i++) {
            string substring = "";
            for(int j = i; j < text.length(); j++) {
                substring.push_back(text[j]);
                if(set.find(substring) != set.end()) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
