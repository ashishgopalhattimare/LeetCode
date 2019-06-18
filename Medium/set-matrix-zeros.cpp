// https://www.interviewbit.com/problems/set-matrix-zeros/
// https://leetcode.com/problems/set-matrix-zeroes/
// Amazon, Oracle

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int row = A.size(), col = A[0].size();
    
    vector<vector<bool>> zero(row);
    vector<vector<char>>dir(row);
    
    for(int i = 0; i < row; i++) {
        zero[i] = vector<bool>(col, false);
        dir[i] = vector<char>(col, 0);
    }
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            zero[i][j] = (A[i][j] == 0);
            
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(zero[i][j]) {
                // row traversal
                for(int k = 0; k < A[i].size(); k++) {
                    if(dir[i][k] == 1 || dir[i][k] == 3) break; // 1 -> row done // 3 -> row/col done
                    dir[i][k] |= 1;
                    A[i][k] = 0;
                }
                for(int k = 0; k < A.size(); k++) {
                    if(dir[k][j] == 2 || dir[k][j] == 3) break; // 2 -> col done // 3 -> row/col done
                    dir[k][j] |= 2;
                    A[k][j] = 0;
                }
            }
        }
    }
}

