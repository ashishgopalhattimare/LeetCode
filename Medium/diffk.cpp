// https://www.interviewbit.com/problems/diffk/

int binary_search(vector<int>& A, int start, int end, int sum) {
    if(start > end) return -1;
    
    if(start == end || end == start+1) {
        if(A[start] == sum) return start;
        if(A[end] == sum) return end;
        return -1;
    }
    
    int mid = start + (end-start)/2;
    
    if(A[mid] <= sum) return binary_search(A, mid, end, sum);
    return binary_search(A, start, mid, sum);
}

int Solution::diffPossible(vector<int> &A, int k) {
    
    int sum, index;
    for(int i = 0; i < A.size(); i++) {
        sum = k + A[i];
        index = binary_search(A, 0, A.size()-1, sum); // if the sum index is found or not
        if(index != -1) { // if found
            if(index == i) { // if not same as i
                // if there are duplicate sum, the lowest is found
                // in case of index == i, check next element in the array
                if(index != A.size()-1 && A[index] == A[index+1])
                    return 1;
            }
            // return true, and found
            else return 1;
        }
    }
    return 0;
}

