// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// Medium, Greedy

#define START 0
#define END 1

class Solution {
public:

	int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        vector<bool>event(100005, false);
        int count = 0;
        
        for(vector<int>& x : events) {
            
            for(int day = x[START]; day <= x[END]; day++) {
                if(event[day] == false) {
                    event[day] = true;
                    count++;
                    break;
                }
            }
        }
        
        return count;
    }
};