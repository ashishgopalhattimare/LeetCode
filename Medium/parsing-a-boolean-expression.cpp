// Leetcode
// Hard
// Weekly Contest 143

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int i = 0;
    stack<char>sign;

    bool boolean(char x) {
        return (x == 't');
    }
    
    bool evaluate(string& str) {
        int temp = -1;
        char x;
        while(i < str.length()) {
            switch(str[i]) {
                case ')':   i++;
                            // printf("result : %d, ", temp);
                            // printf("pop : %c\n", sign.top());
                            sign.pop();
                            return temp;
                    
                case '!':   if(!sign.empty()) x = sign.top();
                            sign.push('!');
                            i+=2;
                            if(temp == -1 || sign.empty()) temp = evaluate(str);
                            else if(x == '&') {
                                temp = temp & evaluate(str);
                            }
                            else {
                                temp = temp | evaluate(str);
                            }
                            // printf("neg result : %d\n", temp);
                            break;
                
                case '|':
                case '&':   
                            if(!sign.empty()) x = sign.top();
                            sign.push(str[i]);
                            // printf("push : %c\n", str[i]);
                            i+=2;
                            
                            if(temp == -1 || sign.empty()) temp = evaluate(str);
                            else if(x == '&') {
                                temp = temp & evaluate(str);
                            }
                            else {
                                temp = temp | evaluate(str);
                            }
                            break;
                
                case 't':   
                case 'f':
                            // if(!sign.empty()) printf("-> %c", sign.top());
                            // printf(" %c\n", str[i]);
                            
                            if(sign.empty()) temp = boolean(str[i]);
                            else if(sign.top() == '!') {
                                temp = !(boolean(str[i]));
                            }
                            else if(temp == -1) temp = boolean(str[i]);
                            else if(sign.top() == '&') {
                                temp = temp & boolean(str[i]);
                            }
                            else {
                                temp = temp | boolean(str[i]);
                            }
                default :   i++;
                    
            }
        }
        
        return temp;
    }
    
    bool parseBoolExpr(string expression) {
        
        return evaluate(expression);
    }
};

int main()
{
    Solution *sol = new Solution();

    string str = "|(f,t)";

    cout << sol->parseBoolExpr(str) << endl;
    return 0;
}
