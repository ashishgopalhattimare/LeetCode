// https://leetcode.com/problems/longest-turbulent-subarray/
// Window-Problem
// O(n) , Medium

class Solution {
public:
    
    int compare(int x, int y) {
        if(x == y) return 0;
        return (x > y) ? 1 : -1;
    } 
    
    int maxTurbulenceSize(vector<int>& A) {
        
        int result = 1, start = 0;
        for(int i = 1; i < A.size(); i++)
        {
            int sign = compare(A[i-1], A[i]); // if same, start from the next index
            if(sign == 0) {
                start = i;
            }
            
            // or eg. (prev = -1, this = 0) == 0 != -1
            // or eg. (prev = 1, this = -1) == -1 != -1 // invalid - this is part of substring
            // or eg. (prev = -1, this = 1) == -1 != -1 // invalid - this is part of substring
            else if(i == A.size()-1 || sign * compare(A[i], A[i+1]) != -1) {
                result = max(result, (i-start)+1);
                start = i;
            }
        }
        
        return result;
    }
};
//  [9,4,2,10,7,8,8,1,9]
 // 1 1 0  1 0 2 1 0 
