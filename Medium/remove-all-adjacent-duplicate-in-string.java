// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Easy

class Solution {
    public String removeDuplicates(String S) {
        int start = 1, prev = 0;
        while(start < S.length()) {
            if(S.charAt(prev) == S.charAt(start)) {
                S = S.substring(0, prev) + S.substring(start+1);
                prev--;
                
                if(prev < 0) prev = 0;
                start = prev+1;
            }
            else {
                prev++; start++;
            }
        }
        return S;
    }
}
