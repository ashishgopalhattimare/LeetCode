// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
// Medium, Codility Contest

class Solution {
public:
    
    vector<int> flipRow(vector<int> row, int value)
    {
        for(int i = 0; i < row.size(); i++) {
            if(row[i] == value) {
                row[i] = 0;
            }
            else row[i]= 1;
        }
        return row;
    }
    
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        map<vector<int>, int>freq;
    
        // take each row
        for(vector<int> x : matrix) {
            freq[flipRow(x, 0)]++; // once flip it
            freq[flipRow(x, 1)]++; // once take it as it is
        }

        int maximumOccur = 0;
        for(auto itr = freq.begin(); itr != freq.end(); itr++) {
            maximumOccur = max(maximumOccur, itr->second);
        }

        return maximumOccur;
    }
};
