// https://www.interviewbit.com/problems/sorted-insert-position/

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    auto itr = lower_bound(A.begin(), A.end(), B);
    if(itr == A.end())
        return A.size();
    return itr - A.begin();
}

