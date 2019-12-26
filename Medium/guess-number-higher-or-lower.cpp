// https://leetcode.com/problems/guess-number-higher-or-lower/
// Easy

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long low = 1, high = n;
        int mid;
        
        while(low <= high) {
            mid = low + (high-low)/2;
            switch(guess(mid)) {
                case -1: high = mid;
                         break;
                case  1: low = mid+1;
                         break;
                case 0 : low = high+1;
            }
        }
        return mid;
    }
};