// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Medium

class Solution {
public:
    
    void resetLine(vector<int>& temp) {
        for(int &x : temp) x = 1;
    }
    
    int countSquares(vector<int>& temp, int n, int size)
    {
        int sub = 0, cs;
        
        for(int i = 0; i < size && i < n; i++) sub += temp[i];
        
        cs = (sub == size);
        for(int l = 0, h = size; h < n; h++, l++) {
            sub += (temp[h] - temp[l]);
            cs += (sub == size);
        }
        
        return cs;
    }
    
    int countSquares(vector<vector<int>>& M) {
        
        int row = M.size(), col = M[0].size();
        int result = 0;
        
        vector<int>temp(row);

        for(int low = 0; low < col; low++) {
            resetLine(temp);
            for(int high = low; high < col; high++) {
                
                for(int i = 0; i < row; i++) // get data from each row of this col
                    temp[i] &= M[i][high];
                
                result += countSquares(temp, row, abs(high-low)+1);
            }
        }
        
        return result;
    }
};