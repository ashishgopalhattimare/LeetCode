// https://leetcode.com/problems/bulb-switcher-iii/
// Medium

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        
        int start = 0;
        vector<bool>bulb(light.size(), false); // initially all are off
        
        int result = 0, x;
        for(int i = 0; i < light.size(); i++) {
            
            x = light[i]-1;
            bulb[x] = true;
            
            while(start < light.size()) { // check how many bulbs are ON from the LHS
                if(bulb[start]) start++;
                else break;
            }
            
            if(start == i+1) result++; // If start Pointer is equal to number of bulbs turned on so far
        }
        return result;
    }
};