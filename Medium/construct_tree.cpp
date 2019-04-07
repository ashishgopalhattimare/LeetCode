#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *constructTree(vector<string>& nums) {
	
	if(nums.size() == 0) return NULL;
	
	TreeNode *head, *ptr;

	try {
		head = new TreeNode(stoi(nums[0]));
	}
	catch(int e) {
		return NULL;
	}
	stack<TreeNode *> st, temp;

	int index = 1;
	
	st.push(head);
	while(!st.empty() && index < nums.size())
	{
		while(!st.empty() && index < nums.size()) {
			ptr = st.top();
			st.pop();
			
			if(index < nums.size() && nums[index] != "null") {
				temp.push(ptr->left = new TreeNode(stoi(nums[index])));
			}
			index++;
			
			if(index < nums.size() && nums[index] != "null") {
				temp.push(ptr->right = new TreeNode(stoi(nums[index])));
			}
			index++;
		}

		while(!temp.empty()) {
			st.push(temp.top());
			temp.pop();
		}
	}

	while(!st.empty()) st.pop();

	return head;
}

void preorder(TreeNode *head) {
	if(head == NULL) return;
	printf("%d ", head->val);
	preorder(head->left);
	preorder(head->right);
}

int main() {

	int n;
	cin >> n;
	vector<string> nums(n);

	for(int i = 0; i < n; i++)
	cin >> nums[i];

	TreeNode *root = constructTree(nums);
	// preorder(root);

	return 0;
}

/*
         1
        / \
       2   3
      / \   \
	 4   5   6
    / \   \   \
   7   8   9   10
          / \    \
         11  12   13

21                       
1 2 3 4 5 null 6 7 8 null 9 null 10 null null null null 11 12 null 13

*/