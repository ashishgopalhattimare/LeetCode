// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/
// Medium, String, Tree, Trie

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

struct Trie {

    int maxFreq;
    vector<Trie*>freq;
    Trie() : maxFreq(0), freq(26, NULL) {}
};

int insertTrie(Trie *root, string& input, int index, int freq)
{
    if(index == input.length()) {
        root->maxFreq = max(root->maxFreq, freq);
        return root->maxFreq;
    }

    int k = input[index]-'a';
    if(root->freq[k] == NULL) root->freq[k] = new Trie();

    root->maxFreq = max(root->maxFreq, insertTrie(root->freq[k], input, index+1, freq));
}

int findMaxFrequency(Trie *root, string& input, int index)
{
    if(index == input.length()) {
        return root->maxFreq;
    }

    int k = input[index]-'a';
    if(root->freq[k]) return findMaxFrequency(root->freq[k], input, index+1);
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    int N, Q, freq;
    string input;

    Trie *root = new Trie();

    cin >> N >> Q;

    while(N--)
    {
        cin >> input >> freq;
        insertTrie(root, input, 0, freq);
    }

    while(Q--)
    {
        cin >> input;
        cout << findMaxFrequency(root, input, 0) << endl;
    }

    return 0;
}