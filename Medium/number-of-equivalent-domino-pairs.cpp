// https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Easy
// Weekly Contest 146

class Solution {
public:
    
    bool equal(int a, int b, int c, int d) {
        return (a==c && b == d) || (a == d && b == c);
    }
    
    int numEquivDominoPairs(vector<vector<int>>& d) {
        
        for(int i = 0; i < d.size(); i++) {
            if(d[i][0] > d[i][1]) {
                swap(d[i][0], d[i][1]);
            }
        }
        
        sort(d.begin(), d.end());
        
        int result = 0, count = 1;
        for(int i = 1; i < d.size(); i++) {
            if(equal(d[i-1][0], d[i-1][1], d[i][0], d[i][1])) {
                count++;
            }
            else {
                result += (count*(count-1))/2;
                count = 1;
            }
        }
        result += (count*(count-1))/2;
        
        return result;
    }
};
