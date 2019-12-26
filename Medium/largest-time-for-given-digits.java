// https://leetcode.com/problems/largest-time-for-given-digits/
// Easy

// Editorial Understood
class Solution {
    public String largestTimeFromDigits(int[] A) {
        
        int hrs, min, ans = -1;
        int i,j,k,l;

        // Choose different indices i, j, k, l as a permutation of 0, 1, 2, 3
        for(i = 0; i < 4; i++){
            for(j = 0; j < 4; j++) {
                for(k = 0; j != i && k < 4; k++) {
                    if (k != i && k != j) {
                        l = 6-(i+j+k);

                        // For each permutation of A[i], read out the time and
                        // record the largest legal time.
                        hrs = 10 * A[i] + A[j];
                        min = 10 * A[k] + A[l];
                        if (hrs < 24 && min < 60)
                            ans = Math.max(ans, hrs * 60 + min);
                    }
                }
            }
        }

        return ans >= 0 ? String.format("%02d:%02d", ans / 60, ans % 60) : "";
    }
}