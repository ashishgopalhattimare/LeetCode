// https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    
    int l = 1, r = B;
    vector<int>result;
    for(int i = 0; i < A.length(); i++) {
        if(A[i] == 'I') result.push_back(l++);
        else result.push_back(r--);
    }
    result.push_back(l);

    return result;
}
