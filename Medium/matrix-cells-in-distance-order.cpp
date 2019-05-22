// https://leetcode.com/contest/weekly-contest-133/problems/matrix-cells-in-distance-order/

class Solution {
public:
    
    static bool function(pair <int, pair <int,int> >& a, pair <int, pair <int,int> >& b) {
        return a.first < b.first;
    }
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        
        vector< pair <int, pair <int,int> > > temp;
        vector<vector<int>> result;
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                temp.push_back(make_pair(abs(r0-i) + abs(c0-j), make_pair(i, j)));
            }
        }
        
        sort(temp.begin(), temp.end(), function);
        for(int i = 0; i < temp.size(); i++) {
            vector<int> entity {temp[i].second.first, temp[i].second.second};
            result.push_back(entity);
        }
        
        return result;
    }
};
