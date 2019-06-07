// https://leetcode.com/problems/powerful-integers/submissions/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        long long int a = x, b = y, value, prev;
        
        set<int>st;
        bool loop = true;
        for(int i = 0; loop; i++) {
            loop = false;
            prev = -1;
            for(int j = 0; ; j++) {
                value = pow(a, i) + pow(b, j);
                if(prev == value) { // same values are being generated
                    loop = true;
                    break;
                }
                
                prev = value;
                if(value <= bound) {// included in the answer
                    st.insert(value);
                    loop = true;
                }
                else break;
            }
            
            if(x <= 1) break; // 1^n and 0^n is same always generated
        }
        
        vector<int>result;
        for(auto itr = st.begin(); itr != st.end(); itr++) {
            result.push_back(*itr);
        }
        return result;
    }
};
