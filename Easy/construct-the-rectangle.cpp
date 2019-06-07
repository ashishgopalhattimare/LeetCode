// https://leetcode.com/problems/construct-the-rectangle/
// Easy

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int sq = sqrt(area);
        
        int l, mlength = area;
        int w, mwidth = 1;
        
        int diff = area-1;
        
        for(int i = 2; i <= sq; i++) {
            l = i;
            w = area/l;
            
            if(area == l*w) {
                if(diff > abs(l-w)) {
                    mlength = w;
                    mwidth = l;
                    diff = abs(l-w);
                }
            }
        }
        
        return { mlength, mwidth };
    }
};
