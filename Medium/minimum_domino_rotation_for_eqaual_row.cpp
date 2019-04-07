// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution {
public:
    
    int minMoves(vector<int>& set, int num) {
        int moves = 0;
        
        // swaps required to make one set all same
        for(int i = 0; i < set.size(); i++) {
            moves += (set[i] != num);
        }
        return moves;
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        bool possible;
        int count;
        int result = INT_MAX;
        
        for(int i = 1; i != 7; i++) {
            possible = true;
            for(int j = 0; j < A.size() && possible; j++) {
                possible = !(A[j] ^ i) || !(B[j] ^ i);
            }
            
            // this number is present on either of the two sets
            if(possible) {
                // find the minimum swaps required to make any set same number
                result = min(result, min(minMoves(A, i), minMoves(B, i)));
            }
        }
        
        return (result == INT_MAX) ? -1 : result;
    }
};
