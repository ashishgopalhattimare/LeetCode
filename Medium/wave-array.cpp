// https://www.interviewbit.com/problems/wave-array/
// Easy, Amazon, Google, Oracle

vector<int> Solution::wave(vector<int> &A) {
    
    sort(A.begin(), A.end());
    
    vector<int>result(A.size());
    
    int k = 0, i = 0;
    while(i < A.size()) {
        if(i+1 < A.size()) result[k++] = A[i+1];
        result[k++] = A[i];
        i+=2;
    }
    
    return result;
}

// 1 2 3 4 5 6 7 8 9
// 2 1 4 3 6 5 8 7 9 - lexicologically smallest
