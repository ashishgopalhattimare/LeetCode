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

#define ll long long int
ll maxSum;

ll max(ll x, ll y) { return (x > y) ? x : y; }

pair<ll,TreeNode*> maximumSumTwoNodes(TreeNode *head)
{
    if(head == NULL) return {0, NULL};

    pair<ll,TreeNode*>right = maximumSumTwoNodes(head->right);
    pair<ll,TreeNode*> left = maximumSumTwoNodes(head->left);
    
    ll subtree = left.first + right.first + head->val;
    ll leftSub = left.first + head->val;
    ll rightSub = right.first + head->val;

    maxSum = max(maxSum, subtree); // if this subtree is the answer

    ll temp = max(max(leftSub, rightSub), head->val);

    if(leftSub == temp) return { temp, left.second };
    if(rightSub== temp) return { temp, right.second};
    
    return {temp, head};
}

pair<ll, TreeNode *> maximumSumLeafNodes(TreeNode *head)
{
    if(head == NULL) return {0, NULL};

    if(head->left == NULL && head->right == NULL) {
        return {head->val, head};
    }

    pair<ll,TreeNode*> right = maximumSumLeafNodes(head->right);
    pair<ll,TreeNode*> left = maximumSumLeafNodes(head->left);
    
    ll subtree = left.first + right.first + head->val;

    //Both the subtree are there
    if(head->right && head->left) {
        // Consider this subtree
        maxSum = max(maxSum, subtree);

        // Use either one of the left or right
        // to maximize sub of the above subtree
        if(left.first > right.first) {
            return {left.first + head->val, left.second};
        }
        return {right.first + head->val, right.second};
    }

    // Only its one side is null, take the valid subtree to parent
    if(head->left) return {left.first + head->val, left.second};
    return {right.first + head->val, right.second};
}

TreeNode *front = NULL, *rear = NULL;

void BinaryToDoublyList(TreeNode *head)
{
    if(head == NULL) return;

    BinaryToDoublyList(head->left);

    printf("%d ", head->val);
    if(front == NULL) {
        front = rear = head;
    }
    else {
        head->left = rear;
        rear->right = head;
        rear = rear->right;
    }
    BinaryToDoublyList(head->right);
}

int main()
{
    string input = "[10,2,10,20,1,null,-25,null,null,null,null,3,4]";

    TreeNode *head = stringToTreeNode(input);
    prettyPrintTree(head);
    printf("\n");

    maxSum = 0;
    maxSum = max(maxSum, maximumSumTwoNodes(head).first);

    cout << "Maximum Sum Between Two Nodes  : " << maxSum << endl;

    maxSum = 0;
    maximumSumLeafNodes(head);

    cout << "Maximum Sum Between Leaf Nodes : " << maxSum << endl;

    // Convert Binary Tree To Circular Linked List
    cout << "Inorder Traversal : ";
    BinaryToDoublyList(head);
    printf("\n");

    printf("Doubly Traversal  : ");
    TreeNode *ptr = front;
    while(ptr) {
        printf("%d ", ptr->val);
        ptr = ptr->right;
    }
    printf("\n");

    return 0;
}