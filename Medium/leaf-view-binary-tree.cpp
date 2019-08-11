#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
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

void leftViewIterative(TreeNode *head)
{
    printf("< Left View Traversal > \n");

    list<TreeNode*>ll;
    TreeNode *ptr;
    int size;

    ll.push_back(head);
    while(!ll.empty()){

        printf("%d ", (ll.front())->val);
        
        size = ll.size();
        while(size--) {
            ptr = ll.front();
            ll.pop_front();

            if(ptr->left) ll.push_back(ptr->left);
            if(ptr->right) ll.push_back(ptr->right);
        }
    }
    printf("\n");
}

void iterate(TreeNode *head, int height, unordered_set<int>& set)
{
    if(head == NULL) return;

    if(set.find(height) == set.end()) {
        printf("%d ", head->val);
        set.insert(height);
    }

    iterate(head->left, height+1, set);
    iterate(head->right, height+1,set);
}

void leftViewRecursive(TreeNode *head)
{
    unordered_set<int>set; // height considered
    iterate(head, 1, set);

    printf("\n\n");
}

void diagonalTraversal(TreeNode *head)
{
    list<TreeNode*>ll;
    TreeNode *ptr;
    int size;

    printf("< Diagonal Traversal > \n");

    ptr = head;
    while(ptr){
        ll.push_back(ptr);
        ptr = ptr->left;
    }

    while(!ll.empty()) {
        printf("[ ");
        for(auto itr = ll.begin(); itr != ll.end(); itr++) {
            printf("%d ", (*itr)->val);
        }
        printf("]\n");

        size = ll.size();
        while(size--) {
            ptr = ll.front();
            ll.pop_front();

            ptr = ptr->right;
            while(ptr) {
                ll.push_back(ptr);
                ptr = ptr->left;
            }
        }
    }
    printf("\n");
}

void closewisTraversal(TreeNode *head)
{
    vector<vector<int>>matrix;

    list<TreeNode*>ll;
    TreeNode *ptr;
    int size;

    printf("< Clockwise Traversal >\n");

    ll.push_back(head);
    while(!ll.empty()){

        vector<int>level;
        size = ll.size();

        while(size--) {
            ptr = ll.front();
            ll.pop_front();

            level.push_back(ptr->val);

            if(ptr->left) ll.push_back(ptr->left);
            if(ptr->right) ll.push_back(ptr->right);
        }

        matrix.push_back(level);
    }

    int l = 0, r = matrix.size()-1;
    bool top = true;

    while(l <= r) {
        printf("[ ");
        if(top) {
            for(int i = 0; i < matrix[l].size(); i++) {
                printf("%d ", matrix[l][i]);
            }
            l++;
        }
        else {
            for(int i = matrix[r].size()-1; i >= 0; i--) {
                printf("%d ", matrix[r][i]);
            }
            r--;
        }
        printf("]\n");
        top = !(top);
    }
}

int main()
{
    string input = "[5,10,7,3,4,6,14,5,11,2,1,0,2,2,1]";

    TreeNode *root = stringToTreeNode(input);
    prettyPrintTree(root);
    printf("\n");
    
    leftViewIterative(root);
    leftViewRecursive(root);

    diagonalTraversal(root);

    closewisTraversal(root);

    return 0;
}

