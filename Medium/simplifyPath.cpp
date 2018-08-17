// https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
    string simplifyPath(string path) {
        
        deque<string> dq;
        int index = 0;
        
        string str = "";
        
        for(int i = 0; i < path.length(); i++) {
            if(path[i] == '/') {
                if(str.length()) {
                    if(!str.compare("..")) { // str == ".." -> go to parent directory
                        if(!dq.empty()) dq.pop_back();
                    }
                    else if(!(str == ".")){  // str != "." --> change directory || str == "." -> ignore
                        dq.push_back(str);
                    }
                    str = "";
                }
            }
            else {
                str.push_back(path[i]);
            }
        }
        
        if(str.length()) {
            if(!str.compare("..")) { // str == ".." -> go to parent directory
                if(!dq.empty()) dq.pop_back();
            }
            else if(!(str == ".")){  // str != "." --> change directory || str == "." -> ignore
                dq.push_back(str);
            }
        }
        
        string result = "/";
        
        if(!dq.empty()) {
            result.append(dq.front());
            dq.pop_front();
        }
        while(!dq.empty()) {
            result.push_back('/');
            result.append(dq.front());
            dq.pop_front();
        }
        
        return result;
    }
};