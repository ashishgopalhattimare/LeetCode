#include <bits/stdc++.h>

using namespace std;

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

void findMaximumMinimum(TreeNode *root)
{
    printf("\n");
    if(root == NULL) return;

    int minim = INT_MAX;
    int maxim = INT_MIN;

    TreeNode *current = root;
    TreeNode *ptr;

    while(current != NULL) {

        if(current->left == NULL) {
            maxim = max(maxim, current->val);
            minim = min(minim, current->val);

            current = current->right;
        }
        else {
            ptr = current->left;
            // find the right node of the current ptr
            while(ptr->right != NULL && ptr->right != current) {
                ptr = ptr->right;
            }

            // Visit left
            if(ptr->right == NULL) {
                ptr->right = current;
                current = current->left;
            }

            // Self Loop, current node is already left visited
            // go right
            else {
                maxim = max(maxim, current->val);
                minim = min(minim, current->val);

                ptr->right = NULL;
                current = current->right;
            }
        }
    }

    cout << "Maximum value : " << maxim << endl;
    cout << "Minimum value : " << minim << endl;

    return;
}

void inorder(TreeNode *root, vector<int>& bottom)
{
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) {
        bottom.push_back(root->val);
        return;
    }

    inorder(root->left, bottom);
    inorder(root->right, bottom);
}

void printBorder(TreeNode *root)
{
    printf("\n");

    list<TreeNode*>ll;
    TreeNode *ptr;

    vector<int>right, left, bottom;

    ll.push_back(root);
    while(!ll.empty()){
        
        int size = ll.size();
        for(int i = 0; i < size; i++) {
            ptr = ll.front();
            ll.pop_front();

            if(i == 0) { // push to left if not leaf
                if(ptr->left || ptr->right) {
                    left.push_back(ptr->val);
                }
            }
            else if(i == size-1) { // push to right if not leaf
                if(ptr->left || ptr->right) {
                    right.push_back(ptr->val);
                }
            }
            
            // push left
            if(ptr->left) {
                ll.push_back(ptr->left);
            }
            // push right
            if(ptr->right) {
                ll.push_back(ptr->right);
            }
        }
    }

    inorder(root, bottom);

    // print right
    printf("[ ");
    for(int i = 0; i < right.size(); i++) {
        printf("%d ", right[i]);
    }
    printf("][ ");
    for(int i = bottom.size()-1; i >= 0; i--) {
        printf("%d ", bottom[i]);
    }
    printf("][ ");
    for(int i = left.size()-1; i >= 0; i--) {
        printf("%d ", left[i]);
    }
    printf("]\n");

    return;
}

bool find_node(TreeNode *head, int x)
{
    if(head->val > x) return false;

    TreeNode *l, *r;
    while(head) {
        if(head->val == x) return true;
        
        r = (head->right) ? head->right : NULL;
        l = (head->left) ? head->left : NULL;

        // X node is not present in the tree
        if(r == NULL && l == NULL) {
            return false;
        }

        while(l || r) {
            
            printf("[ ");
            if(l) printf("%d ", l->val);
            if(r) printf("%d ", r->val);
            printf("]");

            if(x <= l->val || r == NULL) {
                head = head->left;
                break;
            }
            else if(l->val < x && x <= r->val) {
                head = head->right;
                break;
            }

            if(l) l = l->right;
            if(r) r = r->right;
        }

        if(!l && !r) head = head->left;
        printf("\n");
    }

    return false;
}

void inorder(TreeNode *head, int &c) {
    if(head == NULL) return;
    inorder(head->right,c);
    inorder(head->left, c);
    c++;
}

double findMedian(TreeNode *root)
{
    if(root == NULL) return 0;

    int countnodes = 0;
    inorder(root, countnodes);


}

int main()
{
    string tree = "[20,8,22,4,12,null,null,null,null,10,14]";

    TreeNode *root = stringToTreeNode(tree);
    prettyPrintTree(root);

    // cout << find_node(root, 6) << endl;
    cout << findMedian(root) << endl;
    
    return 0;
}

