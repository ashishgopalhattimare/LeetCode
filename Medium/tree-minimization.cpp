// Given a binary tree, modify the tree satisfying the following constrains :
// 
// 1. Value at root must be the sum of left child and right child (not subtrees).
// 2. You can’t reduce the value at any node. You can only increase it.
// 3. Value of root node must be minimum. 

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

int tree_minimization(TreeNode *head)
{
    if(head == NULL) return 0;

    if(head->left == NULL && head->right == NULL) {
        return head->val;
    }

    int left = tree_minimization(head->left);
    int right = tree_minimization(head->right);

    int sum = left + right;
    if(head->val > sum) {
        if(head->left && head->right) {
            head->right->val += abs(sum-head->val);

            return head->val;
        }
    }

    head->val += abs(sum-head->val);
    return head->val;
}

void treeBalance(TreeNode *head) {

    if(head->right == NULL && head->left == NULL) {
        return;
    }

    int left = 0, right = 0;
    if(head->right) right = head->right->val;
    if(head->left) left = head->left->val;

    int diff = abs(head->val - (left + right));
    if(diff) {
        if(head->left && head->right) {
            head->right->val += diff;
        }
        else if(head->left) {
            head->left->val += diff;
        }
        else head->right->val += diff;
    }

    treeBalance(head->left);
    treeBalance(head->right);
}

int main()
{
    string input = "[100,20,40,5,10,50,10]";
    
    TreeNode *root = stringToTreeNode(input);
    
    prettyPrintTree(root);
    
    tree_minimization(root);
    // prettyPrintTree(root);

    treeBalance(root);
    prettyPrintTree(root);

    return 0;
}