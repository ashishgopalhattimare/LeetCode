// https://leetcode.com/submissions/detail/210760628/

class Solution {
public:
    string countAndSay(int n) {
        
        string current = "1";
        
        int count;
        char x;
        for(int i = 1; i < n; i++) {
            string temp;
            
            count = 0;
            x = current[0];
            for(int j = 0; j < current.length(); j++) {
                if(x == current[j]) {
                    count++;
                }
                else {
                    temp += to_string(count);
                    temp.push_back(x);
                    
                    x = current[j];
                    count = 1;
                }
            }
            
            temp += to_string(count);
            temp.push_back(x);
            current = temp;
            
            //cout <<" -> "  << current << endl;
        }
        
        return current;
    }
};
