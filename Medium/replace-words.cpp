// https://leetcode.com/problems/replace-words/
// Medium, Trie

struct Trie
{
    vector<Trie*> dict;
    bool end;
    
    Trie() : end(false) {
        dict = vector<Trie*>(26, NULL);
    }
};

Trie *construct(Trie *head, string& word, int index) {
    if(index == word.length()) {
        head->end = true; // path followed this is a valid word
        return head;
    }
        
    // If this node is not present
    if(!head->dict[word[index]-'a']) head->dict[word[index]-'a'] = new Trie();
    
    head->dict[word[index]-'a'] = construct(head->dict[word[index]-'a'], word, index+1);
    
    return head;
}

string updateWord(Trie* head, string word, int index, string curr) {
    
    if(head == NULL || index == word.length()) {
        return (head && head->end)? curr : word;
    }
    
    if(head->end) return curr;
    return updateWord(head->dict[word[index]-'a'], word, index+1, curr + word[index]);
}

class Solution {
public:
    
    string replaceWords(vector<string>& dict, string sentence) {
        
        Trie *root = new Trie();
        
        for(string x : dict) {
            root = construct(root, x, 0);
        }
        
        vector<string> words;
        string word = "";
        for(int i = 0; i < sentence.length(); i++) {
            if(sentence[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else word.push_back(sentence[i]);
        }
        words.push_back(word);
        
        for(string& word : words) {
            word = updateWord(root, word, 0, "");
        }
        
        string result = "";
        for(int i = 0; i < words.size(); i++) {
            if(i) result.push_back(' ');
            result.append(words[i]);
        }
        
        return result;
    }
};
