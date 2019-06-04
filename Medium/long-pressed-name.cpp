// https://leetcode.com/problems/long-pressed-name/
// Easy

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i0 = 0, i1 = 0; // iterator
        char c0, c1; // current char
        int t0, t1; // count
        int l0 = name.length(), l1 = typed.length(); // length
        
        while(i0 < l0 && i1 < l1) {
            
            // Count number of characters in name that are same continously
            c0 = name[i0++];
            t0 = 1;
            while(i0 < l0 && name[i0] == c0) {
                t0++; i0++;
            }
            
            // Count number of characters in typed that are same continously
            c1 = typed[i1++];
            t1 = 1;
            while(i1 < l1 && typed[i1] == c1) {
                t1++; i1++;
            }
            
            // if both the characters are different or
            // count in name is less than count in typed (missed)
            if(c0 != c1 || t0 > t1) return false;
        }
        
        // If any of the two are remaining to be searched further, return false
        // else return true
        return (i0 < l0 || i1 < l1)? false : true;
    }
};
