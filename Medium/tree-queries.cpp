// https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/tree-queries-45/
// Easy, Sum Level, Level order Tree

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;

	TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

void levelTraverse(TreeNode *head, vector<vector<int>>& levelnodes, int level, vector<long long int>& levelsum)
{
    if(head == NULL) return;
    
    levelnodes[level-1].push_back(head->val);
    levelsum[level-1] += (head->val);
    
    levelTraverse(head->left, levelnodes, level+1, levelsum);
    levelTraverse(head->right, levelnodes, level+1,levelsum);
}

int main()
{
	int n, q, d;
	cin >> n >> q;

	list<TreeNode*>ll;
	TreeNode *root;
	for(int i = 0; i < n; i++) {
		cin >> d;
		if(i == 0) {
			root = new TreeNode(d);
			ll.push_back(root);
		}
		else {
			TreeNode *temp = ll.front();
			if(!temp->left) {
				temp->left = new TreeNode(d);
				ll.push_back(temp->left);
			}
			else {
				temp->right = new TreeNode(d);
				ll.push_back(temp->right);
				ll.pop_front();
			}
		}
	}
	while(!ll.empty()) ll.pop_back();

	int x, lv, l, r, val;
	int type;
    
    vector<vector<int>>levelnodes(22);
    vector<long long int>levelsum(22, 0);
    levelTraverse(root, levelnodes, 1, levelsum);

    while(q--)
    {
        cin >> type;
        
        if(type == 1) {
            cin >> x >> lv;
            cout << levelnodes[lv-1][x-1] << endl;
        }
        else if(type == 2) {
            cin >> l >> r;
            
            long long int total = 0;
            for(int i = l-1; i != r; i++) {
                total += levelsum[i];
            }
            cout << total << endl;
        }
        else {
            cin >> x >> lv >> val;
            
            levelsum[lv-1] += (val - levelnodes[lv-1][x-1]);
            levelnodes[lv-1][x-1] = val;
        }
    }
    
	return 0;
}
