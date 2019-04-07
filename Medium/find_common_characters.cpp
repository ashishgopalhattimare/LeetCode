// https://leetcode.com/problems/find-common-characters/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        vector<vector<int>> hashArray;
        vector<string> result;
        int freq;

        for(int i = 0; i < A.size(); i++) {
            vector<int> word(26, 0);
            hashArray.push_back(word);
        }

        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                hashArray[i][A[i][j]-'a']++;
            }
        }

        for(int i = 0; i < 26; i++) {
            freq = INT_MAX;
            for(int j = 0; j < A.size(); j++) {
                freq = min(freq, hashArray[j][i]);
            }

            while(freq--) {
                result.push_back(string(1, 'a'+i));
            }
        }
        return result;
    }
};