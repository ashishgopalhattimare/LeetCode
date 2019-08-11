// https://leetcode.com/problems/basic-calculator/
// Hard, List Use, Recursive Approach + Stack

class Solution {
public:
    int index = 0;
    int result = 0;
    
    int eval(int a, int b, char x) {
        return (x == '+') ? (a + b) : (a - b);
    }
    
    void evaluate(string& s, list<int>& nums, list<char>& sign) {
        
        int startLen = nums.size();
        bool firstValue = true;
        int value = 0;
        
        while(index < s.length()) {
            if(s[index] == ' ') {
                index++;
                continue;
            }
            
            if(s[index] == '(') {
                index++;
                evaluate(s, nums, sign);
                
                // from the above recursion, the last value is the current value
                // and according to this recursion, that value is not yet pushed
                
                value = nums.back();
                nums.pop_back();
                
                result = value; // it is the result at the end (...)
            }
            else if(s[index] == ')') {
                index++;
                
                if(firstValue) nums.push_back(value);
                else {
                    int a  = nums.back(); nums.pop_back();
                    char s = sign.back(); sign.pop_back();
                    
                    nums.push_back(eval(a, value, s));
                }
                return;
            }
            else if(isdigit(s[index])) {
                value = value*10 + (s[index]-'0');
                index++;
            }
            else {
                if(firstValue) {
                    nums.push_back(value);
                }
                else {
                    int a  = nums.back(); nums.pop_back();
                    char s = sign.back(); sign.pop_back();
                    
                    nums.push_back(eval(a, value, s));
                }
                
                sign.push_back(s[index]);
                
                firstValue = false;
                value = 0;
                index++;
            }
        }
    }
    
    int calculate(string s) {
        
        list<int>value; list<char>sign;
        index = 0;
        
        s = "("+s+")";
        
        evaluate(s, value, sign);
        
        return result;
    }
};
