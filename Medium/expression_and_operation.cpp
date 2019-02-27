// https://leetcode.com/problems/expression-add-operators/

// not working properly.. need to debug this code

class Solution {
public:
    
    void backtrack(string sum, long long int target, int index, long long int current, long long int previous,
                   string currString, vector<string>& result)
    {
        // 1 -> previous operation was multiply
        // 2 -> previous operation was addition
        // 3 -> previous operation was subtraction
        
        // cout << currString << "\t| " << current << endl;
        if(index == sum.length()) {
            if(current == target) {
                result.push_back(currString);
            }
            return;
        }
        
        int value = sum[index]-'0';
        backtrack(sum, target, index+1, (current-previous) + (previous*value), previous*value, currString + "*" +  to_string(value), result); // direct
        
        backtrack(sum, target, index+1, current - value, -value, currString + "-" +  to_string(value), result); // direct
        
        backtrack(sum, target, index+1, current + value, +value, currString + "+" +  to_string(value), result); // direct
        
        if(previous != 0)
        backtrack(sum, target, index+1, current*10+value, previous*10+value, currString + to_string(value), result);
        
        return;
    }
    
    vector<string> addOperators(string num, int target) {
        
        vector<string> result;
        
        if(num.length() == 0) return result;
        
        backtrack(num, target, 1, num[0]-'0', num[0]-'0', to_string(num[0]-'0'), result);
        
        return result;
    }
};
