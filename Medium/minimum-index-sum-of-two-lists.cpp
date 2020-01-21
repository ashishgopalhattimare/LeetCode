// https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// Easy

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

        unordered_map<string,int>map;

        for(int i = 0; i < list1.size(); i++) {
            map[list1[i]] = i;
        }

        int minSum = INT_MAX;
        for(int i = 0; i < list2.size(); i++) {
            if(map.find(list2[i]) != map.end())
                minSum = min(minSum, map[list2[i]]+i);
        }

        vector<string> result;
        for(int i = 0; i < list2.size(); i++) {
            if(map.find(list2[i]) != map.end() && minSum == map[list2[i]]+i) {
                result.push_back(list2[i]);
            }
        }
        
        return result;
    }
};