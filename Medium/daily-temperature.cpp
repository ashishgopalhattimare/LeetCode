// https://leetcode.com/problems/daily-temperatures/
// Medium, Next Greater Element

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        if(T.size() == 0) {};
        
        int n = T.size()-1;
        
        list<pair<int,int>>ll;
        vector<int>result(T.size(), 0);
        
        ll.push_back(make_pair(T[n], n));
        for(int i = n-1; i >= 0; i--) {
            while(!ll.empty() && T[i] >= ll.front().first) {
                ll.pop_front();
            }
            if(!ll.empty()) result[i] = ll.front().second - i;
            ll.push_front(make_pair(T[i], i));
        }
        return result;
    }
};
