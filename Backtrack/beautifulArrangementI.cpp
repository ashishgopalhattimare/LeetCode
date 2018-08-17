class Solution {
public:
    
    int temp;
    void permutation(int index, int *A, int N, int *count)
    {
        if(index == N) {
            *count = *count + 1;
            return;
        }
        for(int i = index; i < N; i++) {
            temp = A[index];
            A[index] = A[i];
            A[i] = temp;
            
            ////////////////////////////////
            
            if(A[index] % (index+1) == 0 || (index+1) % A[index] == 0) {
                permutation(index+1, A, N, count);
            }
            
            ////////////////////////////////
            
            temp = A[index];
            A[index] = A[i];
            A[i] = temp;
        }
        
        return;
    }
    
    int countArrangement(int N) {
        
        int *A = new int[N];
        for(int i = 1; i <= N; i++) {
            A[i-1] = i;
        }
        
        int count = 0;
        permutation(0, A, N, &count);
        
        return count;
    }
};
