// https://leetcode.com/problems/longest-consecutive-sequence/
// Hard

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        
        int n = arr.size();
        
        //Your code here
        unordered_set<int>set;
        for(int i = 0; i < n; i++) {
            set.insert(arr[i]);
        }

        int value;
        int maxim = 0;
        int currLong;
        for(int i = 0; i < n; i++) {
            currLong = 0;

            value = arr[i]+0;
            while(set.find(value) != set.end()) {
                set.erase(value);
                currLong++;
                value--;
            }

            value = arr[i]+1;
            while(set.find(value) != set.end()) {
                set.erase(value);
                currLong++;
                value++;
            }

            maxim = max(maxim, currLong);
        }
        return maxim;
    }
};
