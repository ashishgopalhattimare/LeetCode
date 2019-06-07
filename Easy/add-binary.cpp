// https://leetcode.com/problems/add-binary/
// Easy

class Solution {
public:
    string addBinary(string a, string b) {
        
        list<int>ll;
        
        int i0 = a.size()-1, i1 = b.size()-1;
        int carry = 0;
        while(i0 >= 0 || i1 >= 0) {
            int aa = (i0 >= 0) ? a[i0--]-'0' : 0;
            int bb = (i1 >= 0) ? b[i1--]-'0' : 0;
            
            carry += (aa + bb);
            ll.push_front(carry%2);
            carry /= 2;
        }
        while(carry) {
            ll.push_front(carry%2);
            carry/=2;
        }
        
        // Generate Result Binary
        while(!ll.empty()) {
            if(ll.front() == 1) break;
            ll.pop_front();
        }
        
        if(ll.empty()) return "0";
        
        string result = "";
        while(!ll.empty()) {
            result.push_back(ll.front()+'0');
            ll.pop_front();
        }
        return result;
    }
};
    
