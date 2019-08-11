// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int>result;
    
    int ia = 0, ib = 0;
    while(ia < A.size() && ib < B.size()) {
        if(A[ia] == B[ib]) {
            result.push_back(A[ia]);
            ia++; ib++;
        }
        else if(A[ia] < B[ib]) ia++;
        else ib++;
    }
    
    return result;
}

