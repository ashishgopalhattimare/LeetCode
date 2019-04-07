// https://leetcode.com/problems/clumsy-factorial/

class Solution {
public:
    
    int counter, result;
    
    int cluster() {
        int value = 1;
        if(counter) value *= (counter--);
        if(counter) value *= (counter--);
        if(counter) value /= (counter--);
        
        return value;
    }
    
    int clumsy(int N) {
        
        counter = N;
        
        result = cluster();
        while(counter) {
            result += (counter--);
            if(counter) result -= cluster();
        }
        
        return result;
    }
};
