// https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/magical-tree-1-e7f8cabd/
// Easy, Binary/N-ary Trees

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char c;
    int val;
    vector<int>childs;
    vector<long long int>freq;

    TreeNode(int val, char x) : val(val), freq(26,0) {
        c = x;
        freq[c-'a'] = 1;
    }
};

vector<long long int> preorder(TreeNode *parent, int source, vector<TreeNode*>& nodes)
{
    vector<long long int>& tree = nodes[source]->freq;

    for(int child : nodes[source]->childs) {

        if(nodes[child] != parent) {
            vector<long long int>subtree = preorder(nodes[source], child, nodes);
            for(int i = 0; i < 26; i++) tree[i] += subtree[i];
        }
    }
    return tree;
}

int main()
{
	int N, Q;
	string S;

	cin >> N >> Q;
	cin >> S;

    vector<TreeNode*> nodes(N+1);
    for(int i = 1; i <= N; i++) nodes[i] = new TreeNode(i, S[i-1]);

    int u, v;
	for(int i = 0; i < N - 1; i ++)
	{
		cin >> u >> v;

        nodes[u]->childs.push_back(v);
        nodes[v]->childs.push_back(u);
    }

    preorder(NULL, 1, nodes);

    int n;
    char c;
    while(Q--)
    {
        cin >> n >> c;
        cout << nodes[n]->freq[c-'a'] << endl;
    }

	return 0;
}