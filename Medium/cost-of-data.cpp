// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/cost-of-data-11/
// Easy-Medium, Trie, Sorting

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

struct Trie {

    bool leaf;
    vector<Trie*>freq;
    Trie() : freq(26, NULL) {
        leaf = true;
    }
};

void insertTrie(Trie *root, string& input, int index, long long int& count)
{
    if(index == input.length()) return;

    root->leaf = false; // this node is not the leaf node

    int k = input[index]-'a';
    if(root->freq[k] == NULL) {
        root->freq[k] = new Trie();
        count++;
    }

    insertTrie(root->freq[k], input, index+1, count);
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

    cin >> N;

    long long int count = 1;
    while(N--)
    {
        cin >> input;
        insertTrie(root, input, 0, count);
    }

    cout << count << endl;

    return 0;
}