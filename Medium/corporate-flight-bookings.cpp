// https://leetcode.com/problems/corporate-flight-bookings/
// Weekly-Contest
// Medium, Algorithmic Crush

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int>result(n, 0);

        for(vector<int> x : bookings) {
        	result[x[0]-1] += x[2];
        	if(x[1] < n) {
        		result[x[1]] -= x[2];
        	}
        }
        
        for(int i = 0, sum = 0; i < n; i++)
            result[i] = (sum += result[i]);
        
        return result;
    }
};
