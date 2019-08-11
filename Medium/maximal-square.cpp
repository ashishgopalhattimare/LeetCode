// https://leetcode.com/problems/maximal-square/
// Medium

class Solution {
public:
    
    int kadane(vector<int>& temp, int stretch)
    {
        int maxArea = INT_MIN;
        int side;
        int count = 0;
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == 1) count++;
            else {
                side = min(stretch, count);
                maxArea = max(maxArea, side*side);
                count = 0;
            }
        }
        
        side = min(stretch, count);
        maxArea = max(maxArea, side*side);
        
        return maxArea;
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        
        if(mat.size() == 0) return 0;
        
        int ROW = mat.size(), COL = mat[0].size();
        int maxArea = INT_MIN;
        
        vector<int>temp(ROW);
        for(int left = 0; left < COL; left++) {
            
            for(int &x : temp) x = 1;
            for(int right = left; right < COL; right++) {
                
                for(int k = 0; k < ROW; k++) {
                    temp[k] &= mat[k][right];
                }
                
                maxArea = max(maxArea, kadane(temp, right-left+1));
            }
        }
        
        return maxArea;
    }
};
