// https://www.interviewbit.com/problems/matrix-search/

int binary_search(int row, int start, int end, int B, vector<vector<int> > &A) {
    if(start > end) return 0;
    
    int mid = start + (end-start)/2;
    if(A[row][mid] == B) return 1;
    
    if(A[row][mid] < B) return binary_search(row, mid+1, end, B, A);
    return binary_search(row, start, mid-1, B, A);
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int row = A.size();
    int col = A[0].size();
    for(int i = 0; i < row; i++) {
        if(B <= A[i][col-1]) {// this row
            return binary_search(i, 0, col-1, B, A);
        }
    }
    return 0;
}

