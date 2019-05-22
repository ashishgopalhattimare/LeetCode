// https://leetcode.com/problems/hamming-distance/
// Easy

// C++
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int r = x^y;
        int result = 0;
        while(r) {
            result += (r%2);
            r/=2;
        }
        return result;
    }
};


// Java
class Solution {
    public int hammingDistance(int x, int y) {
        
        String xa = Integer.toBinaryString(x);
        String xb = Integer.toBinaryString(y);
        
        int r1 = xa.length()-1;
        int r2 = xb.length()-1;
        
        int result = 0;
        while(r1 >= 0 && r2 >= 0) {
            if(xa.charAt(r1--) != xb.charAt(r2--)) result++;
        }
        while(r1 >= 0) {
            if(xa.charAt(r1--) == '1') result++;
        }
        while(r2 >= 0) {
            if(xb.charAt(r2--) == '1') result++;
        }
        
        return result;
    }
}
