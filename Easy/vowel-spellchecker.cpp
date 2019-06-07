// https://leetcode.com/problems/vowel-spellchecker/
// Medium, Trie DS

// - When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
// - When the query matches a word up to capitlization, you should return the first such match in the wordlist.
// - When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
// - If the query has no matches in the wordlist, you should return the empty string.

#define ASCII 130

static char vowel[10] = {'A','a','E','e','I','i','O','o','U','u'};
static string correct;
static bool found, capitalDone;

struct Trie {
    vector<Trie*>alphabets;
    bool end;
    string word;
    Trie() : end(false), alphabets(ASCII, NULL) {}
};

Trie *constructWordList(Trie *head, string& word, int index, int length) {
    if(index == length) {
        head->word = word;
        head->end = true;
        return head;
    }
    char temp = word[index];
    
    if(!head->alphabets[temp]) { // node is not present
        head->alphabets[temp] = new Trie();
    }
    
    head->alphabets[temp] = constructWordList(head->alphabets[temp], word, index+1, length);
    return head;
}

bool isvowel(char x) {
    switch(x) {
        case 'a': case 'e':
        case 'i': case 'o':
        case 'u': return true;
        default : return false;
    }
}

void CheckWordList(Trie *head, string query, int index, int length, unordered_map<string, int>& map, bool capitalize) {
    if(head == NULL) return;
    
    if(index == length) {
        if(head->end == true) {
            if(correct.length() == 0) { // make any found random first word available, correct word
                correct = head->word;
                if(query == head->word) found = true;
            }
            if(found) return;
            else if(map[correct] > map[head->word]) {
                correct = head->word;
            }
        }
        return;
    }
    
    char temp = query[index];
    if(head->alphabets[temp]) { // if the same character is present
        CheckWordList(head->alphabets[temp], query, index+1, length, map, capitalize);
    }
    
    // if the temp character is a non-vowel character
    if(islower(temp)) { // if the character is lowercase, try uppercase
        if(head->alphabets[toupper(temp)]) { // if the same character is present
            CheckWordList(head->alphabets[toupper(temp)], query, index+1, length, map, capitalize);
        }
    }
    else { // if uppercase, try lowercase
        if(head->alphabets[tolower(temp)]) { // if the same character is present
            CheckWordList(head->alphabets[tolower(temp)], query, index+1, length, map, capitalize);
        }
    }
    
    if(!capitalize) {
        if(isvowel(tolower(temp))){
            for(int i = 0; i < 10; i++) {
                if(head->alphabets[vowel[i]]) {
                    CheckWordList(head->alphabets[vowel[i]], query, index+1, length, map, capitalize);
                }
            }
        }
    }
}

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        unordered_map<string, int>map;
        vector<string> result;
        
        Trie *root = new Trie();
        int i = 0;
        for(string word : wordlist) {
            map[word] = i++;
            root = constructWordList(root, word, 0, word.length());
        }
        
        for(string query : queries) {
            
            correct = ""; found = false;
            
            CheckWordList(root, query, 0, query.length(), map, true);
            if(correct.length() == 0) // if 
                CheckWordList(root, query, 0, query.length(), map, false);
            
            result.push_back(correct);
        }
        
        return result;
    }
};
