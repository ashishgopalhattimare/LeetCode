// https://leetcode.com/problems/water-and-jug-problem/submissions/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        
	// Requirement is more than the capacity of total
        if(z > x+y) return false;
        
        int gcd = __gcd(x,y);
        
	// If the gcd is zero and requirement is zero
        if(z == 0 && gcd == 0) return true;
	
	// if gcd is zero -> division by zero error
        else if(gcd == 0) return false;
        
        return !(z % gcd);
    }
};
