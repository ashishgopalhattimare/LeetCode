// https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    
    int perfectSquare(int n)
    {
        vector<int>arr(n+3);
        
        for(int i = 0; i <= 3; i++) {
            arr[i] = i;
        }
        
        int temp;
        int result;
        for(int i = 4; i <= n; i++) {
            result = i;
            for(int j = 1; j <= i; j++) {
                temp = j * j;
                if(temp > i) break;
                
                result = min(result, 1 + arr[i - temp]);
            }
            
            arr[i] = result;
        }
        
        return arr[n];
    }
    
    int numSquares(int n) {
        return perfectSquare(n);
    }
};