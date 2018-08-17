// https://leetcode.com/problems/add-and-search-word-data-structure-design/description/


//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

class TrieChar
{
public:
    bool end;
    TrieChar *character[26];

    TrieChar() {
        end = false;
        for(int i = 0; i < 26; i++) {
            character[i] = NULL;
        }
    }
};

class WordDictionary {
public:

    TrieChar *root, *ptr;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieChar();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        ptr = root;
        for(int i = 0; i < word.length(); i++) {
            if(!(ptr->character[word[i]-'a'])) {
                ptr->character[word[i]-'a'] = new TrieChar();
            }
            ptr = ptr->character[word[i]-'a'];
        }
        ptr->end = true;
    }


    bool searchPattern(TrieChar *head, string word, int index)
    {
        if(index == word.length()) {
            return (head != NULL && head->end == true);
        }

        TrieChar *ptr = head;

        if(word[index] != '.') {
            if(ptr->character[word[index]-'a']) {
                return searchPattern(ptr->character[word[index]-'a'], word, index + 1);
            }
        }
        else {
            for(int i = 0; i < 26; i++) {
                if(ptr->character[i]) {
                    if(searchPattern(ptr->character[i], word, index+1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchPattern(root, word, 0);
    }
};

int main()
{
    WordDictionary *root = new WordDictionary();

    root->addWord("bad");
    root->addWord("dad");
    root->addWord("mad");

    cout << root->search("pad") << endl;
    cout << root->search("bad") << endl;
    cout << root->search(".ad") << endl;
    cout << root->search("b..") << endl;

    return 0;
}
