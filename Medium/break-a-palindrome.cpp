// https://leetcode.com/problems/break-a-palindrome/
// Medium

class Solution {
public:
    string breakPalindrome(string palin) {
        
        string result = "";
        
        for(int i = 0; i < palin.size()/2; i++) {
            if(palin[i] != 'a') { // Greedy approach
                palin[i] = 'a'; result = palin;
                break;
            }
        }
        
        // all the first half is 'a' // change the last character to 'b'
        // as first character is 'a' due to palindrome condition
        if(result.size() == 0 && palin.size() > 1) {
            palin[palin.size()-1] = 'b';
            return palin;
        }
        return result;
    }
};