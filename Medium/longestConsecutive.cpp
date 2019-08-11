#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
     	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

void inorder(TreeNode* head, unordered_set<TreeNode*>& set, vector<TreeNode*>& arr) {
    if(head == NULL) return;
    
    arr.push_back(head);
    set.insert(head);
    
    inorder(head->left, set, arr);
    inorder(head->right, set, arr);
}

void longestConsecutive(TreeNode *head, int length, int prev, int& result, 
                        unordered_set<TreeNode*> & set) {
    if(head == NULL) return;
    
    if(head->val == prev+1) {
        result = max(result, length+1);
        
        set.erase(head);
        longestConsecutive(head->left, length+1, head->val, result, set);
        longestConsecutive(head->right, length+1, head->val, result, set);
    }
}

int main() {
    string line = "[1,2,2,3,null,4,null,4,null,5,null,5,5,6,null,\
                    null,null,null,6,7,null,7,null,8,8]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);
    
    unordered_set<TreeNode*>set;
    vector<TreeNode*>arr;
    inorder(root, set, arr);
    
    int maxConsecutive = 0;
    for(TreeNode * x : arr) {
        if(set.find(x) != set.end()) {
            longestConsecutive(x, 0, x->val-1, maxConsecutive, set);
        }
    }
    
    cout << maxConsecutive << endl;
    
    return 0;
}
