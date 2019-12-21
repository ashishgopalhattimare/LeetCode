// https://leetcode.com/problems/flood-fill/
// Easy

class Solution {
private:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    
    bool inrange(int x, int l) { return x >= 0 && x < l; }
    
public:
    
    void fill(vector<vector<int>>& I, int sr, int sc, int newColor, int original)
    {
        I[sr][sc] = newColor;
        
        for(int k = 0; k < 4; k++) {
            if(inrange(sr+Y[k], I.size()) && inrange(sc+X[k], I[0].size()) &&
              I[sr+Y[k]][sc+X[k]] == original) {
                
                fill(I, sr+Y[k], sc+X[k], newColor, original);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] != newColor)
            fill(image, sr, sc, newColor, image[sr][sc]);
        
        return image;
    }
};