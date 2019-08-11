// https://leetcode.com/problems/4sum-ii/
// Medium
// Complexity : O(n2logn)

class Solution {
public:
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        unordered_map<int,int>map;
        
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                map[A[i]+B[j]]++;
            }
        }
        
        int value, result = 0;
        for(int i = 0; i < C.size(); i++) {
            for(int j = 0; j < D.size(); j++) {
                value = -(C[i]+D[j]);
                
                if(map.find(value) != map.end()) {
                    result += map[value];
                }
            }
        }
        return result;
    }
};
