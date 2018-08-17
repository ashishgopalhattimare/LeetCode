// https://leetcode.com/problems/arranging-coins/description/

// binary search

class Solution {
public:
    
    int binarySearch(long long int s, long long int e, long long int r)
    {
        if(s > e) return 0;
        
        if(e == s+1) {
            if(e * e + e <= r) return e;
            if(s * s + s <= r) return s;
        }
        
        long long int m = s + (e-s)/2;
        long long int temp = m * m + m;
        
        if(temp <= r) {
            return binarySearch(m, r, r);
        }
        return binarySearch(s, m, r);
    }
    
    int arrangeCoins(int x) {
        
        if(x == 0) return 0;
        
        long long int n = x;
        return binarySearch(1, n, 2*n);
    }
};