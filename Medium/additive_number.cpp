// https://leetcode.com/problems/additive-number/

class Solution {
public:
    
    stack<char>st;
    
    void recursive(string& num, int start, bool *valid, long long int value1, long long int value2)
    {
        long long int value = value1 + value2;
        int digits;
        
        if(value == 0) {
            // if the value is 0, digit is 1
            digits = 1;
        }
        else {
            // digits in the sum number
            digits = log10(value) + 1;
        }
        
        // if the current start index + digit is reaching out of string length
        if(start + digits > num.length()) return;
        
        // if the current start index + digit is reaching the string length
        if(start + digits == num.length()) {
            // value is zero
            if(value == 0) {
                st.push('0');
            }
            // non-zero value -> put the value in stack -> no leading zero guaranteed
            else {
                while(value) {
                    st.push(value%10+'0');
                    value/=10;
                }
            }
            
            // assume this path to be true
            bool validPath = true;
            for(int i = start; i < num.length(); i++) {
                // check if the value generated is same as the next number in the string input
                if(num[i] != st.top()) { // if not same
                    validPath = false; // not a valid path
                    
                    // emty the stack
                    while(!st.empty()) st.pop();
                    break;
                }
                st.pop();
            }
            
            // if validPath, valid is true
            *valid = validPath;
            return;
        }
        
        // if the string is still not valid
        if(*valid == false) {
            long long int temp = value;
            // if the temp value is zero
            if(temp == 0) {
                st.push('0');
            }
            // non-zero value -> put the value in stack -> no leading zero guaranteed
            else {
                while(temp) {
                    st.push(temp%10+'0');
                    temp/=10;
                }
            }

            bool validPath = true;
            for(int i = start; i < start + digits; i++) {
                // check if the value generated is same as the next number in the string input
                if(num[i] != st.top()) { // if not same
                    validPath = false; // not a valid path

                    // emty the stack
                    while(!st.empty()) st.pop();
                    break;
                }
                st.pop();
            }
            
            // if the next number is same as the value, try next number after this number
            if(validPath) {
                recursive(num, start + digits, valid, value2, value);
            }
        }
    }
    
    // get the second number
    void secondPass(string& num, int start, bool *valid, long long int value1)
    {
        long long int value2 = 0;
        
        if(start < num.length() && num[start] == '0') {
            recursive(num, start+1, valid, value1, value2);
            return;
        }
        
        for(int i = start; i < num.length() && *valid == false; i++) {
            value2 = value2*10 + (num[i]-'0');
            
            if(i+1 != num.length()) {
                recursive(num, i+1, valid, value1, value2);
            }
        }
    }
    
    // get the first number
    void firstPass(string& num, int start, bool *valid)
    {
        long long int value1 = 0;
        
        if(start < num.length() && num[start] == '0') {
            secondPass(num, start+1, valid, value1);
            return;
        }
        
        for(int i = start; i < num.length() && *valid == false; i++) {
            value1 = value1*10 + (num[i]-'0');
            
            secondPass(num, i+1, valid, value1);
        }
    }
    
    bool isAdditiveNumber(string num) {
        
        bool valid = false;
        
        firstPass(num, 0, &valid);
        
        return valid;
    }
};