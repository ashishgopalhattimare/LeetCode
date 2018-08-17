// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class TrieChar
{
public:
    bool end; // end of word
    TrieChar * children[26]; // array of pointer objects

    // constructor
    TrieChar() {
        end = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieChar *root; // root pointer object to all words

    Trie() {
        root = new TrieChar();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieChar *ptr = root;
        for(int i = 0; i < word.length(); i++) {
            if(ptr->children[word[i]-'a'] == NULL) {
                ptr->children[word[i]-'a'] = new TrieChar();
            }
            ptr = ptr->children[word[i]-'a'];
        }
        ptr->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieChar *ptr = root;

        for(int i = 0; i < word.length(); i++) {
            if(ptr->children[word[i]-'a']) {
                ptr = ptr->children[word[i]-'a'];
            }
            else {
                return false;
            }
        }
        return (ptr != NULL && ptr->end);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieChar *ptr = root;

        for(int i = 0; i < prefix.length(); i++) {
            if(ptr->children[prefix[i]-'a']) {
                ptr = ptr->children[prefix[i]-'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */