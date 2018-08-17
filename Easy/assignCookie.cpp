// https://leetcode.com/problems/assign-cookies/description/

/**

to give maximum children cookie, give least child first, the minimum cookie possible

**/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // increasing order child requirement
        sort(s.begin(), s.end()); // increasing order cookie size
        
        int count = 0;
        int index = 0;
        for(int i = 0; i < s.size() && index < g.size(); i++) {
            if(g[index] <= s[i]) { // if the cookie is suitable with child's requirement
                count++;
                index++;
            }
        }
        
        return count;
    }
};