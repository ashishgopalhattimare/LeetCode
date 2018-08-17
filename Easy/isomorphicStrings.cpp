//https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>hash1;
        unordered_map<char, char>hash2;
        
        if(s.length() != t.length()) return false;
        
        for(int i = 0; i < s.length(); i++) {
            if(hash1.find(s[i]) == hash1.end() && hash2.find(t[i]) == hash2.end()) {
                hash1[s[i]] = t[i];
                hash2[t[i]] = s[i];
            }
            else {
                if(hash1[s[i]] != t[i] || hash2[t[i]] != s[i]) return false;
            }
        }
        
        string str;
        for(int i = 0; i < s.length(); i++) {
            str.push_back(hash1[s[i]]);
        }
        return str == t;
    }
};

/**

"egg" "add" -> true
"ab" "aa" -> false
"foo" "bar" -> false
"paper" "title" -> true


double sided hashing works because we are making sure that char in string A is only connected
to single char in string B 


"paper" "title" -> true

p <-> t
e <-> l         /** string A 'e' is connected to 'l' in string B 
r <-> e		/** string B 'e' is connected to 'r' in string B


while in "ab" "aa" case

a <-> a
b <-> a      /** a and b in string A are connected to same char 'a'


**/

**/
