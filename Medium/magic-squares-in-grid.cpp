// https://leetcode.com/problems/magic-squares-in-grid/
// Easy

#define D2_int vector<vector<int>>&

class Solution {
private:
    int digits[10];
    int _id;    
public:
    
    Solution() { for(int i = 0; i < 10; i++) digits[i] = 0; }
    
    int sumCalc(D2_int G, int i, int j, int fi, int fj) {
        int sum = 0;
        for(int k = 0; k < 3; k++) {
            sum += G[i][j];
            i+=fi; j+=fj;
        }
        
        return sum;
    }
    
    bool inrange(int x) { return x >= 1 && x < 10; }
    
    bool allDistinctDigits(D2_int G, int iShift, int jShift) {
        
        _id++;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(!inrange(G[i+iShift][j+jShift]))
                    return false;
                
                if(digits[G[i+iShift][j+jShift]] == _id) {
                    return false;
                }
                else digits[G[i+iShift][j+jShift]] = _id;
            }
        }
        return true;
    }
    
    bool isMagic(D2_int G, int i, int j) {
        
        int sum = sumCalc(G, i, j, 0, 1);
        
        for(int k = 0; k < 3; k++) {
            if(sum != sumCalc(G,i,j,0,1)) return false; // rowCalc
            if(sum != sumCalc(G,i,j,1,0)) return false; // colCalc
        }
        
        // diagonal Calculate
        return (sum == sumCalc(G,i,j,1,1)) && (sum == sumCalc(G,i,j+2,1,-1));
    }
    
    int numMagicSquaresInside(D2_int grid) {
        
        int row = grid.size(), col = grid[0].size();
        int result = 0;
        
        _id = 1;
        for(int i = 0; i < row-2; i++) {
            for(int j = 0; j < col-2; j++) {
                if(allDistinctDigits(grid, i, j)) {
                    result += isMagic(grid,i,j);
                }
            }
        }
        return result;
    }
};