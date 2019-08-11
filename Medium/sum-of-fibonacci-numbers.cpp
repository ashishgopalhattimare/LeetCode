// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int binary_search(vector<int>& fibo, int start, int end, int target)
{
    if(start == end || end == start+1) {
        for(int i = end; i >= start; i--) {
            if(fibo[i] <= target)
                return fibo[i];
        }
    }
    
    int mid = start + (end-start)/2;
    
    if(fibo[mid] == target) return fibo[mid];
    else if(target < fibo[mid]) {
        return binary_search(fibo, start, mid, target);
    }
    return binary_search(fibo, mid, end, target);
}

int Solution::fibsum(int A) {
    
    long long a = 1, b = 1, temp;
    vector<int>fibo;
    
    fibo.push_back(1);
    while(a+b <= A) {
        fibo.push_back(a+b);
        temp = a + b;
        a = b;
        b = temp;
    }
    int count = 0;
    while(A) {
        A -= binary_search(fibo, 0, fibo.size()-1, A);
        count++;
    }
    
    return count;
}

