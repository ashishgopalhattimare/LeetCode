// https://leetcode.com/problems/brick-wall/
// Medium
// COmplexity : O(nlogn)

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        vector<int>cracks;
        int edge;
        
        // do not include the first and last point
        // as they will always be result in longestCommon crack to wall.size()
        // which is not needed, minimum bricks that cover the vertical line
        // drawn
        for(vector<int> x : wall) {
            edge = 0;
            for(int i = 0; i < x.size()-1; i++) {
                edge += x[i];
                cracks.push_back(edge);
            }
        }
        
        // all the common crack lines are bought together
        sort(cracks.begin(), cracks.end());
        
        int longestCommon = 0, prev = 0, tempLen = 0;
        
        // count maximum same cracks to determine the longestCommon crack line
        for(int x : cracks) {
            if(prev == x) tempLen++;
            else {
                longestCommon = max(longestCommon, tempLen);
                tempLen = 1;
            }
            prev = x;
        }
        longestCommon = max(longestCommon, tempLen);
        
        return wall.size() - longestCommon;
    }
};
