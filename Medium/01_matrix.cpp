// https://leetcode.com/problems/01-matrix/submissions/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        vector<pair<int,int>> zeroArray;
        vector<pair<int,int>> onesArray;
        
        vector<vector<int>> result;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j]) {
                    onesArray.push_back(make_pair(i, j));
                } else {
                    zeroArray.push_back(make_pair(i, j));
                }
            }
            
            vector<int>row(matrix[i].size(), 0);
            result.push_back(row);
        }
        
        pair<int,int> source;
        int minim;
        
        for(int i = 0; i < onesArray.size(); i++) {
            source = onesArray[i];
            
            minim = INT_MAX;
            for(int j = 0; j < zeroArray.size(); j++) {
                minim = min(minim, abs(source.first - zeroArray[j].first) + abs(source.second - zeroArray[j].second));
            }
            result[source.first][source.second] = minim;
        }
        
        return result;
    }
};
