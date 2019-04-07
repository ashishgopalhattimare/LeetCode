// https://leetcode.com/problems/max-consecutive-ones-iii/submissions/

// Maximum Window Question using two pointer (low, high)

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        
        int maxim = INT_MIN;
        int maxZero;
        
        maxZero = 0;
        for(int x : A) maxZero += (x == 0);

// Base Cases -> extreme cases
        if(maxZero <= K) return A.size();

        int low = 0;
        maxZero = 0;
        for(int high = 0; high < A.size(); high++) {
            if(A[high] == 0) {
                maxZero += 1;
            }
            if(maxZero > K) { // limit crossed
                // if the low index is zero then decrement the maxZero by 1
                // as one zero is out of the current 1's window
                if(A[low++] == 0) {
                    maxZero -= 1;
                }
            }

            maxim = max(maxim, high-low+1);
        }

        return maxim;
    }
};
