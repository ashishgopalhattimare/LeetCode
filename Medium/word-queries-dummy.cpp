// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/dummy4-2/
// Medium, Trie

#include<bits/stdc++.h>
using namespace std;

struct Trie {

    int count, end;

    vector<Trie*>freq;
    Trie() : freq(26, NULL) {
        count = 0;
        end = 0;
    }
};

int insertTrie(Trie *root, string& input, int index)
{
    if(index == input.length()) {
        root->count = root->count +1;
        root->end = root->end +1;
        return 1;
    }

    int k = input[index]-'a';
    if(root->freq[k] == NULL) root->freq[k] = new Trie();

    root->count += insertTrie(root->freq[k], input, index+1);
}

int findCount(Trie *root, string& input, int index)
{
    if(index == input.length()) {
        return root->count;
    }

    int k = input[index]-'a';

    if(root->freq[k]) return findCount(root->freq[k], input, index+1);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    // Code Here
    int N, Q;
    string input;

    Trie *root = new Trie();

    cin >> N >> Q;
    while(N--)
    {
        cin >> input;
        insertTrie(root, input, 0);
    }

    while(Q--)
    {
        cin >> input;
        cout << findCount(root, input, 0) << endl;
    }

    return 0;
}