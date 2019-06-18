// https://leetcode.com/contest/biweekly-contest-2/problems/high-five/
// Easy, Sorting

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int average = items[0][1];
        int prev = items[0][0];
        int len = 1;
        
        int count = 1;
        
        vector<vector<int>>result;
        for(int i = 1; i < items.size(); i++) {
            if(items[i][0] != prev) {
                result.push_back({prev, average/len});
                
                average = items[i][1];
                count = 1;
                len = 1;
            }
            else {
                if(count < 5) {
                    average += items[i][1];
                    len++;
                }
                count++;
            }
            
            prev = items[i][0];
        }
        
        result.push_back({prev, average/len});
        
        return result;
    }
};
