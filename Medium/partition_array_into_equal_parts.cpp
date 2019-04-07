// https://leetcode.com/contest/weekly-contest-129/problems/partition-array-into-three-parts-with-equal-sum/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        
//         0 2 1 -6 6 -7 9 1 2 0 1    
        int len = A.size();
        
        int total = 0;
        
        for(int i = 0; i < A.size(); i++) total += A[i];
        
        if(total % 3) return false;
        
        total/=3;
        
        int count = 0, sum = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            
            if(total == sum) { count++; sum = 0; }
        }
        
        return (count == 3);
    }
};
