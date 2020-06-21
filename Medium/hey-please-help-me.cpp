// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/hey-please-help-me/
// Medium, BFS, DFS, Hashing, Trie

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

struct Trie {

    string word;
    bool end;

    vector<Trie*>freq;
    Trie() : end(false), freq(26, NULL) {}
};

void insertTrie(Trie *root, string& input, int index)
{
    if(index == input.length()) {
        root->word = input;
        root->end = true;
        
        return;
    }

    int k = input[index]-'a';
    if(root->freq[k] == NULL) root->freq[k] = new Trie();

    insertTrie(root->freq[k], input, index+1);
}

void printLexiOrder(Trie *root)
{
    if(root == NULL) return;
    if(root->end) {
        cout << root->word << endl;
    }

    for(int i = 0; i < 26; i++)
    if(root->freq[i]) printLexiOrder(root->freq[i]);
}

bool findLexiOrder(Trie *root, string& input, int index)
{   
    // If found, print all the word in the dictionary with this prefix
    if(index == input.length()) {
        printLexiOrder(root);
        return true;
    }

    int k = input[index]-'a';
    if(root->freq[k]) return findLexiOrder(root->freq[k], input, index+1);

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    int N, Q;
    string input, traverse;

    Trie *root = new Trie();

    cin >> N;
    while(N--)
    {
        cin >> input;

        transform(input.begin(), input.end(), input.begin(), ::tolower);
        insertTrie(root, input, 0);
    }

    cin >> Q;
    while(Q--)
    {
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        // If not found, add the word to the dictionary
        if(!findLexiOrder(root, input, 0)) {

            cout << "No suggestions" << endl;
            insertTrie(root, input, 0);
        }
    }

    return 0;
}