// https://leetcode.com/problems/integer-replacement/
// Medium

class Solution {
public:
    int integerReplacement(int n) {
        int moves = INT_MAX;
        
        algorithm(n, &moves, 0); // recursive approach
        
        return moves;
    }
    
    void algorithm(long long int n, int *moves, int count) {
        
        if(*moves < count) return; // if this recursive approach is not better, return
        if(n == 1) { // could be the optimal approach
            *moves = min(*moves, count);
            return;
        }
        
        if(n%2 == 0) // try this if n is even
            algorithm(n/2, moves, count+1);
        else { // if n is odd
            algorithm(n+1, moves, count+1); // try n+1
            algorithm(n-1, moves, count+1); // try n-1
        }
    }
};
