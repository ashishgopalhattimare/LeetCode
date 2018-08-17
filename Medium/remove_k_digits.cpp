// https://leetcode.com/problems/remove-k-digits/description/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        
        if(n == k) { // all the elements are removed
            return "0";
        }
        
        deque<char>dq; // easy to remove element from both side for leading 0 and top element
        
        for(int i = 0; i < num.length(); i++) {
            while(k && !dq.empty() && dq.back() > num[i]) {
                dq.pop_back();
                k--;
            }
            dq.push_back(num[i]);
        }
        
        while(!dq.empty() && k) {
            dq.pop_back();
            k--;
        }
        
        string result = "";
        while(!dq.empty()) {
            if(dq.front() == '0') {
                dq.pop_front();
            }
            else break;
        }
        
        while(!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }
        
        if(result == "") {
            return "0";
        }
        
        return result;
    }
};