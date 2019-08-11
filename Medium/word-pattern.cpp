class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        unordered_map<char,string>map1;
        unordered_map<string,char>map2;
        
        vector<string>words;
        string temp = "";
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == ' '){
                words.push_back(temp);
                temp = "";
            }
            else temp.push_back(str[i]);
        }
        words.push_back(temp);
        
        if(pattern.length() != words.size()) return false;
        
        for(int i = 0; i < words.size(); i++) {
            if(map1.find(pattern[i]) == map1.end() && map2.find(words[i]) == map2.end()) { // both are not present
                map1[pattern[i]] = words[i];
                map2[words[i]] = pattern[i];
            }
            else if(map1.find(pattern[i]) != map1.end() && map2.find(words[i]) != map2.end()) {
                // check if they are bijection
                if(map1[pattern[i]] != words[i] || map2[words[i]] != pattern[i]) {
                    return false;
                }
            }
            else return false;
        }
        return true;
    }
};
