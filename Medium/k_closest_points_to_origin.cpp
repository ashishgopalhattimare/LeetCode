// https://leetcode.com/problems/k-closest-points-to-origin/submissions/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        std::sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return (pow(a[0], 2) + pow(a[1], 2)) < (pow(b[0], 2) + pow(b[1], 2));
        });
        
        vector<vector<int>>result(K);
        for(int i = 0; i < K; i++) result[i] = points[i];
    
        return result;
    }
};
