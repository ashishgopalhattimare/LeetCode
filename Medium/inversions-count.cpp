// https://www.interviewbit.com/problems/inversions/

void cruxAlgorithm(vector<int>& A, int start, int mid, int end, int &inversions, 
vector<int>& temp)
{
    int i = start;
    int j = mid+1;
    
    int k = 0;
    
    while(i <= mid && j <= end) {
        if(A[i] > A[j]) {
            inversions += (mid-i+1);
            temp[k++] = A[j++];
        }
        else temp[k++] = A[i++];
    }
    while(i <= mid) temp[k++] = A[i++];
    while(j <= end) temp[k++] = A[j++];
    
    for(i = 0; i < k; i++) {
        A[start+i] = temp[i];
    }
    return;
}

void inversionCount(vector<int>& A, int start, int end, int &inversions, vector<int>& temp)
{
    if(start == end) return;
    
    int mid = start + (end-start)/2;
    
    inversionCount(A, start, mid, inversions, temp);
    inversionCount(A, mid+1, end, inversions, temp);
    cruxAlgorithm(A, start, mid, end, inversions, temp);
}

int Solution::countInversions(vector<int> &A) {
    
    int inversions = 0;
    
    vector<int>temp(A.size());
    inversionCount(A, 0, A.size()-1, inversions, temp);
    
    return inversions;
}

