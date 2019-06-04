// https://leetcode.com/problems/basic-calculator-ii/
// Medium, Mock Test, On-site

class Solution {
public:
    
    int priority(char x) {
        switch(x) {
            case '+': case '-': return 1;
        }
        return 2;
    }
    
    int resultant(int a, int b, char sign) {
        switch(sign) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
        }
        return 0;
    }
    
    void print(deque<int>& nums, deque<char>& op) {
        for(auto itr = nums.begin(); itr != nums.end(); itr++) {
            printf("%d ", *itr);
        }
        printf("\n");
        
        if(!op.empty()) {
            for(auto itr = op.begin(); itr != op.end(); itr++) {
                printf("%c ", *itr);
            }
        }
        printf("\n\n");
    }
    
    // Pop Two values from back and sign from back
    int calculate(deque<int>& nums, deque<char>& op)
    {
        int b = nums.back(); nums.pop_back();
        int a = nums.back(); nums.pop_back();
        char sign = op.back(); op.pop_back();
        return resultant(a, b, sign);
    }
    
    int calculate(string s) {
     
        deque<int>nums;
        deque<char>op;
        
        bool started = false;
        int number = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') continue;
            
            if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
                nums.push_back(number);
                
                if(op.empty()) op.push_back(s[i]);
                else { 
                    // while upper sign is greater than current
                    while(!op.empty() && priority(op.back()) >= priority(s[i])) {
                        nums.push_back(calculate(nums, op));
                    }
                    op.push_back(s[i]);
                }
                number = 0;
            }
            else {
                number = number*10+(s[i]-'0');
            }
        }
        nums.push_back(number);
        
        if(nums.size() == 1) return nums.back();
        
        nums.push_back(calculate(nums, op));
        
        // Now start same popping from the front
        while(nums.size() != 1) {
            int a = nums.front(); nums.pop_front();
            int b = nums.front(); nums.pop_front();            
            char sign = op.front(); op.pop_front();
            
            int result = resultant(a, b, sign);
            nums.push_front(result);
        }
        return nums.back();
    }
};
