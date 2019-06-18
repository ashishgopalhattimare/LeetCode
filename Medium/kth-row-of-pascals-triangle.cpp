// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
// Google
// Space complexity : O(k)

vector<int> Solution::getRow(int A) {
    
    vector<int>result(A+1, 1);
    
    int first, second;
    for(int i = 1; i < A; i++) {
        first = 1;
        for(int j = 1; j <= i; j++) { // 2
            second = result[j];
            result[j] = first + second;
            first = second;
        }
    }
    
    return result;
}


