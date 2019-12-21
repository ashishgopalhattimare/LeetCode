// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Medium

class Solution {
public:
    string removeDuplicates(string str, int k) {

        list<pair<char,int>>ll;
        pair<char,int> top;

        string result = "";

        if(k == 1) return result;

        for(char c : str) {
            if(ll.empty() || ll.back().first != c)
                ll.push_back({c,1});
            
            // The current top pair is same as the current c
            else {
                top = ll.back();
                ll.pop_back();

                top.second++;
                if(top.second != k) ll.push_back(top);
            }
        }

        while(!ll.empty()) {
            top = ll.front(); ll.pop_front();
            for(int i = 0; i < top.second; i++)
                result.push_back(top.first);
        }

        return result;
    }
};