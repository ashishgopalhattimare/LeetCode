// https://leetcode.com/contest/weekly-contest-132/problems/longest-arithmetic-sequence/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        
        int diff, prev;
        int maxim = 0;
        int count;
        for(int i = 0; i < A.size() && maxim < A.size()-i; i++) {
            for(int j = i+1; j < A.size(); j++) {
                diff = A[j] - A[i];
                
                prev = A[j]; count = 2;
                for(int k = j+1; k < A.size(); k++) {
                    if(A[k] == prev + diff) {
                        prev+=diff;
                        
                        ++count;
                    }
                }
                maxim = max(maxim, count);
            }
        }
        
        return maxim;
    }
};
