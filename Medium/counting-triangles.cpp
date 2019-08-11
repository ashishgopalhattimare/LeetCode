// https://www.interviewbit.com/problems/counting-triangles/
// O(n2logn)

int Solution::nTriang(vector<int> &A) {
    sort(A.begin(), A.end());
    
    int MOD = 1000000007;
    int n = A.size();
    long long int result = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i+1; j < A.size(); j++) {
            
            int lower = A[j]-A[i]+1; // lowest value i need
            int highr = A[j]+A[i]; // high value i dont need
            
            // cout << A[i] << " " << A[j] << " : " << lower << " " << highr << " | ";
            
            auto start = lower_bound(A.begin()+(j+1), A.end(), lower);
            auto end = lower_bound(A.begin()+(j+1), A.end(), highr);
            
            int startIndex = start - A.begin();
            int endIndex = end - A.begin() - 1;
            
            if(startIndex <= endIndex) {
                result = result + (endIndex - startIndex + 1);
                result %= MOD;
                // cout << endIndex - startIndex + 1 << endl;
            }
            
            // printf("\n");
            
        }
    }
    return result;
}

