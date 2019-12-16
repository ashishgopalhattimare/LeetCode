// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Easy

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        
        vector<int>row(n, 0), col(m, 0);
        
        for(vector<int>& x : indices) {
            row[x[0]]++; col[x[1]]++;
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                count += ((row[i] + col[j]) % 2 == 1);
            }
        }
        
        return count;
    }
};