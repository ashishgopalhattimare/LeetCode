#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left, *right;

    TreeNode(char c) : val(c), left(NULL), right(NULL) {}
};

static int i = 0, n = 0;
TreeNode *constructTree(string &input)
{
    TreeNode * newNode = NULL;

    if(i < n && input[i] == '(') i++; // open bracket increment by 1

    if(i < n && isalnum(input[i])) { // if the current is not )
        newNode = new TreeNode(input[i]);
        i++;

        if(i < n && input[i] == '(')
            newNode->left = constructTree(input);
        else
            return newNode;

        if(i < n && input[i] == '.') return newNode;
        else if(i < n && isalnum(input[i]))
            newNode->right = constructTree(input);
    }

    i++;
    return newNode;
}

    //    a
    //  b   c
    // d e    f
    //      g   h
    //         k l

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + node->val + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

vector<int>path;
struct Data {
    int index;

    bool operator<(const Data& other) const {
        return path[index] > path[other.index];
    }
};

bool allSame(int i1, int i2, string& a, string& b) {
    int n1 = a.length(), n2 = b.length();
    while(i1 < n1 && i2 < n2) {
        if(a[i1] != b[i2])
            return false;
        i1++; i2++;
    }
    return i1 == n1 && i2 == n2;
}

int Abs(int x, int y) {
    return abs(x - y);
}

bool singleOperation(string &a, string &b) {
    if(a.length() == b.length()) { // replace only
        int changes = 0;
        for(int i = 0; i < a.length() && changes < 2; i++) {
            if(a[i] != b[i]) changes++;
        }
        return changes == 1;
    }

    // Only one character delete or append
    else if(Abs(a.length(), b.length()) == 1){
        for(int i = 0; i < min(a.length(), b.length()); i++) {
            if(a[i] != b[i]) {
                // remove or append new char
                if(a.length() > b.length()) { // append to smaller or remove from greater length
                    return allSame(i+1, i, a, b);
                }
                return allSame(i, i+1, a, b);
            }
        }
        return true;
    }
    return false;
}

string minimumOperations(vector<string>& arr, string start, string end) {

    path = vector<int>(arr.size(), INT_MAX);
    unordered_set<int>MST;

    priority_queue<Data>pq;
    Data curr;

    int starti = -1, endi = -1;

    // Find the start Node
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == start) {
            starti = i;
        }
        else if(arr[i] == end) {
            endi = i;
        }
    }

    if(start == end) return "0";
    if(starti == -1 || endi == -1) return "Infinity"; // infinity
    
    MST.insert(starti);
    pq.push({starti});
    path[starti] = 0;

    while(!pq.empty()) {
        curr = pq.top();
        pq.pop();

        // "mat","cat","hat","mate","hate","hated"
        for(int i = 0; i < arr.size(); i++) {
            if(MST.find(i) != MST.end()) continue; // lready in MST
            else {
                if(path[curr.index] + 1 < path[i] && singleOperation(arr[curr.index], arr[i])) {
                    path[i] = path[curr.index] + 1;

                    MST.insert(i);
                    pq.push({i});
                }
            }
        }
    }

    return to_string(path[endi]);
}

int main()
{
    string input = "(a(b(de)c(.f(gh(kl))))";

    n = input.length();
    TreeNode *root = constructTree(input);

    prettyPrintTree(root);

    // Number of substring with odd sum
    vector<int>arr = {5,4,4,5,1,3};

    // Brute Force : O(n^2)
    // Optimal     : O(n)

    vector<string> strs = {"mat","cat","hat","mate","hate","hated","hatred","atred","tred","red","ed","d"};
    cout << "Minimum Operations required : " << minimumOperations(strs, "hat", "d") << endl;

    return 0;
}