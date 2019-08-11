class Solution {
public:
    
    int temporal[5005];
    
    void countInversions(int start, int mid, int end, vector<int>& A, int &global)
    {
        int i = start, j = mid+1;
        int k = 0;
        while(i <= mid && j <= end) {
            if(A[i] > A[j]) {
                global += (mid-i+1);
                temporal[k++] = A[j++];
            }
            else
                temporal[k++] = A[i++];
        }
        
        while(i <= mid) temporal[k++] = A[i++];
        while(j <= end) temporal[k++] = A[j++];
        
        for(int i = 0; i < k; i++) {
            A[start++] = temporal[i];
        }
    }
    
    void mergeInversion(int start, int end, vector<int>& nums, int &global)
    {
        if(start >= end) return;
        
        int mid = start + (end-start)/2;
        mergeInversion(start, mid, nums, global);
        mergeInversion(mid+1, end, nums, global);
        
        countInversions(start, mid, end, nums, global);
    }
    
    bool isIdealPermutation(vector<int>& A) {
        
        vector<int>temp = A;
        
        // Local Inversions
        int local = 0;
        for(int i = 1; i < A.size(); i++) {
            local += (A[i-1] > A[i]);
        }
        
        int global = 0;
        mergeInversion(0, A.size()-1, temp, global);
        
        return global == local;
    }
};
