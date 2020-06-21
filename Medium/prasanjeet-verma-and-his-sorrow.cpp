// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/prasanjeet-verma-and-his-sorrow/
// Medium, Trie

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

struct Trie {

    int count, end;

    vector<Trie*>freq;
    Trie() : freq(26, NULL) {
        count = end = 0;
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
    string type, input;

    Trie *root = new Trie();

    cin >> N;
    while(N--)
    {
        cin >> type >> input;

        if(type == "add") {
            insertTrie(root, input, 0);
        }
        else {
            cout << findCount(root, input, 0);
        }
    }

    return 0;
}