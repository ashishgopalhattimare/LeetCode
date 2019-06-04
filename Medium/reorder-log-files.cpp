// https://leetcode.com/problems/reorder-log-files/

class Solution {
public:
    
    vector<string> reorderLogFiles(vector<string> logs) {
        
        vector<string>result = logs;
        
        if(result.size() <= 1) return result;
        
        sort(result.begin(), result.end(), [](string a, string b) {
            
            vector<string>aa;
            string str1;
            for(char x : a) {
                if(x == ' ') {
                    aa.push_back(str1);
                    str1 = "";
                }
                else str1.push_back(x);
            }
            aa.push_back(str1);
            
            vector<string>bb;
            string str2;
            for(char x : b) {
                if(x == ' ') {
                    bb.push_back(str2);
                    str2 = "";
                }
                else str2.push_back(x);
            }
            bb.push_back(str2);
            
            if(isalpha(aa[1][0]) && isalpha(bb[1][0])) {
                int ia = 1, ib = 1;
                for( ; ia < aa.size() && ib < bb.size(); ia++, ib++) {
                    
                    if(aa[ia] == bb[ib]) continue;
                    return (aa[ia] < bb[ib]);
                }
                
                if(ia == aa.size() && ib == bb.size()) {
                    return aa[0] < bb[0];
                }
                return (ia < aa.size());
            }
            else if(isalpha(aa[1][0])) {
                return true;
            }
            else if(isalpha(bb[1][0])) {
                return false;
            }
            return true;
        });
        
        deque<string>dq;
        for(int i = 0; i < logs.size(); i++) {
            string x = logs[i];
            
            int in = 0;
            while(x[in] != ' ') in++;
            in++;
            
            if(isdigit(x[in])) dq.push_back(x);
        }
        
        int i = result.size()-1;
        while(!dq.empty()) {
            result[i--] = dq.back();
            dq.pop_back();
        }
        
        return result;
    }
};
