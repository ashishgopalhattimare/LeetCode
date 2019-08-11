// https://leetcode.com/problems/maximal-rectangle/
// N^3
// Kadane DP (Hard)

class Solution {
public:
    
    int kadane(vector<int>& temp, int ROW, int stretch)
    {
        int maxArea = 0;
        int count = 0;
        
        for(int i = 0; i < ROW; i++) {
            if(temp[i] == 1) count++;
            else {
                maxArea = max(maxArea, count * stretch);
                count = 0;
            }
        }
        return max(maxArea, count * stretch);
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0) return 0;
        
        int ROW = matrix.size(), COL = matrix[0].size();
        int maxArea = 0, area;
        
        vector<int>temp(ROW, 1);
        for(int left = 0; left < COL; left++) {
            
            for(int & x : temp) x = 1;
            for(int right = left; right < COL; right++) {
                
                for(int i = 0; i < ROW; i++) {
                    temp[i] &= matrix[i][right];
                }
                
                // for(int x : temp) printf("%d ", x);
                // printf("\n");
                
                area = kadane(temp, ROW, right-left+1);
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};
