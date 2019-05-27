// https://leetcode.com/problems/longest-absolute-file-path/
// Medium, Mock Test 2
// Design : Stack O(n)

class Solution {
public:
    
    int max(int x, int y) { return (x > y) ? x : y; }
    
    int lengthLongestPath(string input) {
        int level, file;
        int len = input.length();
        bool dot;
        int result = 0;
        
        stack<pair<int,int>>st;
        pair<int,int>top;
        
        for(int i = 0; i < len; ) {
            level = 0;
            while(i < len && input[i] == '\t') { // count level of the current directory/file
                level++; 
                i++; 
            }
            
            file = dot = false;
            while(i < len && input[i] != '\n') {// filename 
                if(input[i] == '.') dot = true; // this is a file
                file++;
                i++;
            }
            
            while(i < len && input[i] == '\n') i++;
            
            // if the level of the current file is less than the top
            while(!st.empty()) {
                top = st.top();         // get current node details
                if(top.second < level)  // this level is more close to the root directory
                    break;
                st.pop();               // this file is under current top of stack node
            }
            
            if(st.empty()) { // new directory open
                st.push(make_pair(file, level)); // make directory as root
                // if this file is a file not a directory, get maxim
                if(dot) result = max(result, file);
            }
            else {
                // push length till last top + current file length
                st.push(make_pair(top.first + 1 + file, level)); 
                // if this file is a file not a directory, get maxim
                if(dot) result = max(result, top.first + 1 + file);
            }
        }
        return result;
    }
};
