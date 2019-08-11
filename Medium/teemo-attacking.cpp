// https://leetcode.com/problems/teemo-attacking/
// Medium
// Algorithemic Crush Modified

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int result = 0, currMax = -1;
        int nextMax;
        for(int x : timeSeries) {
            if(currMax < x) {
                result += duration;
                currMax = x+duration-1;
            }
            else {
                nextMax = x+duration-1;
                result += (nextMax-currMax);
                currMax = nextMax;
            }
        }
        return result;
    }
};
