// https://leetcode.com/problems/distance-between-bus-stops/
// Easy

class Solution {
public:
    
    int distance(vector<int>& dist, int s, int d, int f) {
        
        int sr = s, result = 0, n = dist.size();
        
        if(f == -1) {
            sr = (sr-1+n)%n;
            d = (d-1+n)%n;
        }
        
        while(sr != d) {
            result += dist[sr];
            sr = (sr+f+n)%n;
        }
        return result;
    }
    
    int distanceBetweenBusStops(vector<int>& dist, int s, int d) {
        
        return min(distance(dist, s, d, 1), distance(dist, s, d, -1));
    }
};