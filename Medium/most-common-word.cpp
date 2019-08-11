// https://leetcode.com/problems/most-common-word/
// Easy

class Solution {
public:
    
    string result = "";
    int maxFreq = 0;
    
    void addWord(unordered_map<string,int>& map, unordered_set<string>& ban, string& word)
    {
        if(ban.find(word) == ban.end()) {
            if(maxFreq < ++map[word]) {
                maxFreq++;
                result = word;
            }
        }
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_map<string,int>map;
        unordered_set<string>ban;
        
        for(string x : banned) {
            transform(x.begin(), x.end(), x.begin(), ::tolower); 
            ban.insert(x);
        }
        
        string word = "";
        for(char x : paragraph) {
            if(isalpha(x)) word.push_back(tolower(x));
            else {
                if(word.length()) {
                    addWord(map, ban, word);
                    word = "";
                }
            }
        }
        if(word.length()) addWord(map, ban, word);
        
        return result;
    }
};
