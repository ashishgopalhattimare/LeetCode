// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/
// Medium
// Advanced Data Structure, Trie

#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define MAX 10000000001

static int bitmask[36] = {0};
static int maxLen;

/**

OK. I'm assuming you know about tries so I won't go into those details.
You need a binary trie (just zero or one possible) whose height needs to be large
enough to handle the biggest number you can have (hint: I used unsigned ints throughout). 
Top of the trie will be the MSB while leaves will be the 0th bit.

Insert zero in the trie.
Initialize the accumulated mask to 0.

Now:
For each add op, XOR the number to be inserted with the accumulated mask and then insert normally.
For each xor op, just XOR it into the accumulated xor.
For searching, traverse the trie trying always to keep towards the "0" branch - UNLESS that bit is 
set in the mask. If the bit is set in the mask try to go to the "1" branch. When traversing, build
up your result bit by bit (suggest using a shifting 1 bit mask for both checking the accumulated xor 
and creating the resultant number). You would use this mask by ANDing with the accumulated xor and by 
ORing into the result.

Hope this clears up the idea a bit. If you need more details, just send me a message.
Complexity (if I'm not mistaken):
Add op: O(1)
Xor op: O(1)
Search op: O(1)
Since we process N operations, overall complexity: O(N)

P.S. Duplication of numbers is unimportant (and the trie takes care of that).

**/

struct Trie
{
    int bit;
    Trie *left, *right;

    // Right -> 1
    // Left -> 0
    Trie() : left(NULL), right(NULL) {
        
    }
};

void print(vector<int>& binary) {
    for(int x : binary) printf("%d", x);
    printf("\n");
}

LL getInteger(vector<int>& binary) {
    LL value = 0;
    for(int i = 0; i < binary.size(); i++) {
        value = 2*value + (binary[i] == 1);
    }

    return value;
}

vector<int> getBinary(LL num)
{
    vector<int> binary(maxLen, 0);
    for(int i = maxLen-1; i >= 0 && num; i--) {
        if(num % 2 == 1) binary[i] = 1;
        num /= 2;
    }
    return binary;
}

int countBits(LL number) 
{
    if(number == 0) return 1;
    return static_cast<int>(log2(number)) + 1; 
}

// 7 is the value to be stored, XOR by 6
// Store 7^6 = Y in the trie, so that Y^6 can return the actual value back 
void insertTrie(Trie *head, vector<int>& bin, int ind)
{
    head->bit = bin[ind] ^ bitmask[ind];

    if(ind + 1 != bin.size()) {
        if(bin[ind+1] ^ bitmask[ind+1] == 1) { // Go right

            if(head->right == NULL) head->right = new Trie();
            insertTrie(head->right, bin, ind+1);
        }
        else {
            if(head->left == NULL) head->left = new Trie();
            insertTrie(head->left, bin, ind+1);
        }
    }
}

void traverseTrie(Trie *head, vector<int>& bin, int ind)
{
    bin[ind] = head->bit ^ bitmask[ind]; // XOR that bit using bitmask
    
    if(ind + 1 == bin.size())
    {
        // Print, all numbers in the Trie
        printf("[%lld] ", getInteger(bin));
        return;
    }

    if(head->right) traverseTrie(head->right, bin, ind+1);
    if(head->left) traverseTrie(head->left, bin, ind+1);
}

LL getMinimumValue(Trie *head, vector<int>& bin, int ind)
{
    bin[ind] = head->bit ^ bitmask[ind];

    if(ind + 1 == bin.size()) return getInteger(bin);

    // If Both the right and left childs are present
    if(head->right && head->left) {
        // Take the one which is 0, as we are planning to lead towards minimum number
        // Since, the bit is xor, need to check both
        if(head->right->bit ^ bitmask[ind+1] == 0) {
            return getMinimumValue(head->right, bin, ++ind);
        }
        else return getMinimumValue(head->left, bin, ++ind);
    }
    // If only one child is present, no other option
    else if(head->left) return getMinimumValue(head->left, bin, ++ind);
    return getMinimumValue(head->right, bin, ++ind);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    maxLen = countBits(MAX);

    LL t, type, x;

    vector<int> temp(maxLen, 0);
    Trie *root = new Trie();

    insertTrie(root, temp, 0);

    cin >> t;
    while(t--)
    {
        cin >> type;
        switch(type) {
            case 1: // insert in the tree
                    cin >> x;
                    
                    temp = getBinary(x);
                    insertTrie(root, temp, 0);
                    
                    break;

            case 2: cin >> x;

                    temp = getBinary(x);
                    for(int i = 0; i < temp.size(); i++) {
                        bitmask[i] ^= temp[i];
                    }
                    break;

            case 3:
                    printf("%lld\n", getMinimumValue(root, temp, 0));
                    // cout << getMinimumValue(root, temp, 0) << endl;
        }
        // traverseTrie(root, temp, 0);
        // printf("\n--------\n");
    }

    return 0;
}