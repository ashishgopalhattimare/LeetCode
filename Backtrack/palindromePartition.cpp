// PalindromePartitioning

class Solution {
public:
    
    bool isPalindrome(const string str)
    {
        int l = 0, r = str.length()-1;
        while(l < r) {
            if(str[l] != str[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    void permutation(int index, string str, vector<string>& st, vector<vector<string> >& result)
    {
        if(index == str.length()) {
            result.push_back(st);
            return;
        }
        
        string currentWord = "";
        for(int i = index; i < str.length(); i++)
        {
            currentWord += str[i];
            
            if(isPalindrome(currentWord)) {
                st.push_back(currentWord);
                permutation(i+1, str, st, result);
                st.pop_back();
            }

            // else break // not required to get future palindrome
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        
        vector<string> st;
        permutation(0, s, st, result);
        
        return result;
    }
};