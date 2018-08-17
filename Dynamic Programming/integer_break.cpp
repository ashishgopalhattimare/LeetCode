// https://leetcode.com/problems/integer-break/description/

vector<int> arr(57, -1);

class Solution {
public:
    
    
    
    int integerBreak(int n) {
        arr[0] = 0; arr[1] = 1;
        
        int maxValue;
        for(int i = 2; i <= n; i++) {
            
            if(arr[i] != -1) continue;
            
            maxValue = INT_MIN;
            for(int j = 1; j <= i/2; j++) {

            	// maximum in all possible combination
                maxValue = max(max(max(max(maxValue, arr[j] * arr[i - j]), j*(i-j)), j * arr[i-j]), arr[j] * (i-j));
            }
            
            arr[i] = maxValue;
        }
        
        return arr[n];
    }
};