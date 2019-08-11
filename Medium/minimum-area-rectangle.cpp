// https://leetcode.com/problems/minimum-area-rectangle/
// Medium
// Complexity : O(n^2logn)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        unordered_map<int, unordered_set<int>>pointset;
        
        for(vector<int> x : points) pointset[x[0]].insert(x[1]);
        
        long long int minimArea = LONG_MAX, area;
        for(int i = 0; i < points.size(); i++) { // O(10^4)
            for(int j = i+1; j < points.size(); j++) {
                
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                
                // printf("[%d,%d][%d,%d][%d,%d][%d,%d]\n", points[i][0], points[i][1], points[j][0], points[j][1], 
                // points[i][0], points[j][1], points[j][0], points[i][1]);
                
                // Check if the other two points exists
                // to find complexity, logn in worst case
                if( pointset[points[i][0]].find(points[j][1]) != pointset[points[i][0]].end() && 
                    pointset[points[j][0]].find(points[i][1]) != pointset[points[j][0]].end()) {
                    
                    area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
                    if(minimArea > area) minimArea = area;
                }
            }
        }
        return (minimArea == LONG_MAX) ? 0 : minimArea;
    }
};
