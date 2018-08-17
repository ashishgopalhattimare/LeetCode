class Solution {
public:
    
    stack<char>temp;
    void phoneCombination(int index, string& digits, stack<char>& st, vector<string>& result, unordered_map<char, string>& hash)
    {
        if(index == digits.size()) {
            while(!st.empty()) {
                temp.push(st.top());
                st.pop();
            }
            string v;
            while(!temp.empty()) {
                v.push_back(temp.top());
                st.push(temp.top());
                temp.pop();
            }
            result.push_back(v);
            
            return;
        }
        for(int i = 0; i < hash[digits[index]].size(); i++) {
            st.push(hash[digits[index]][i]);
            
            phoneCombination(index+1, digits, st, result, hash);
            
            st.pop();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>hash;
        
        hash['2'] = "abc"; hash['3'] = "def";
        hash['4'] = "ghi"; hash['5'] = "jkl";
        hash['6'] = "mno"; hash['7'] = "pqrs";
        hash['8'] = "tuv"; hash['9'] = "wxyz";
        
        vector<string> result;
        
        if(digits.length() == 0) {
            return result;
        }
        
        stack<char> st;
        phoneCombination(0, digits, st, result, hash);
        
        return result;
    }
};
