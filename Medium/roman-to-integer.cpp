// https://leetcode.com/problems/roman-to-integer/
// Easy, Mock Test

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>map;
        
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        int value = 0, prev = -1;
        for(int i = 0; i < s.length(); i++) {
            value += map[s[i]];
            if(i && map[s[i]] > map[s[i-1]]) value -= (2*map[s[i-1]]);
        }
        return value;
    }
};
