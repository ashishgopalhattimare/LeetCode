// https://leetcode.com/problems/car-pooling/
// Medium, Weekly Contest
// Easy Approach, Algorithmic Crush

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        unordered_map<int,int> passengers; // <time, number of passengers in the bus at this time>
        
        int minTime = INT_MAX, maxTime = INT_MIN;
        for(int i = 0; i < trips.size(); i++) {
            minTime = min(minTime, trips[i][1]); // minimTime of start journey
            maxTime = max(maxTime, trips[i][2]); // maximTime of journey
            
            
            // number of passengers at time i
            passengers[trips[i][1]] += trips[i][0];
            passengers[trips[i][2]] -= trips[i][0];
        }
        
        long long int currentCapacity = 0;
        for(int i = minTime; i <= maxTime; i++) {
            currentCapacity += passengers[i];
            if(currentCapacity > capacity)
                return false;
        }
        return true;
    }
};
