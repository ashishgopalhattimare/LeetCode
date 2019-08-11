// https://leetcode.com/problems/spiral-matrix-iii/
// Medium

class Solution {
public:
    
    bool inrange(int x, int l){
        return x >= 0 && x < l;
    }
    
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        
        vector<vector<int>>result;
        
        int count = 0, maximum = R * C;
        int alpha = 2;
        while(count < maximum)
        {
            for(int k = 0; k < alpha && count < maximum; k++) { // left to right
                if(inrange(r0, R) && inrange(c0, C)) {
                    result.push_back({r0, c0});
                    count++;
                }
                c0++;
            }
            r0++; c0--;
            
            for(int k = 0; k < alpha-1 && count < maximum; k++) { // top to down
                if(inrange(r0, R) && inrange(c0, C)) {
                    result.push_back({r0, c0});
                    count++;
                }
                r0++;
            }
            r0--; c0--;
            
            for(int k = 0; k < alpha && count < maximum; k++) { // left to right
                if(inrange(r0, R) && inrange(c0, C)) {
                    result.push_back({r0, c0});
                    count++;
                }
                c0--;
            }
            r0--; c0++;
            
            for(int k = 0; k < alpha-1 && count < maximum; k++) { // top to down
                if(inrange(r0, R) && inrange(c0, C)) {
                    result.push_back({r0, c0});
                    count++;
                }
                r0--;
            }
            
            alpha+=2;
        }
        
        return result;
    }
};
