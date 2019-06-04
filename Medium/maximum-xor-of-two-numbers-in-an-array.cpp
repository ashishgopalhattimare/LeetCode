// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Medium, Trie

vector<char> IntToBinary(int value, int bits) {
	vector<char>binary(bits+1, '0');
	int i = bits;
	while(value) {
		binary[i--] = (value&1) + '0';
		value = value >> 1;
	}
	return binary;
}

struct Trie
{
	Trie *left, *right;
	int value;
	char bit;
	bool end;

	Trie(char bit) : bit(bit), left(NULL), right(NULL), end(false) {
		value = -1;
	}
};

Trie *construct (Trie *head, vector<char>& binary, int index, int value) {
	if(index == binary.size()) return head;

	// If this node is node present
	if(!head) head = new Trie(binary[index]);

	// Least Significant bit - 0th bit
	if(index == binary.size()-1) {
		head->value = value;
		head->end = true;
	}
	else {
		if(binary[index+1] == '1') { // go to right
			head->right = construct(head->right, binary, index+1, value);
		}
		else { // go to left
			head->left = construct(head->left, binary, index+1, value);
		}
	}
	return head;
}

void traverseTrie(Trie *head, string binary) {
	if(head == NULL) return;

	if(head->end) {
		cout << "-> " << binary << head->bit << endl;
	}

	traverseTrie(head->left, binary + head->bit);
	traverseTrie(head->right, binary + head->bit);
}

int maximumXOR(Trie*head, vector<char>& binary, int index) {
	if(head == NULL) return 0;

	// This is the optimal number to maximize XOR
	if(head->end) return head->value;

	// If next bit is 0, try to go 1 (right), else 0 (left)
	if(binary[index+1] == '0')
		return (head->right)? maximumXOR(head->right, binary, index+1) :
				maximumXOR(head->left, binary, index+1);
	else
	// If next bit is 1, try to go 0 (left), else 1 (right)
		return (head->left)? maximumXOR(head->left, binary, index+1) :
				maximumXOR(head->right, binary, index+1);
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = NULL;
        
        for(int x : nums) {
            vector<char> binary = IntToBinary(x, 32);
            root = construct(root, binary, 0, x);
        }

        int maxim = 0;
        for(int x1 : nums) { // get the optimal other number for each number
            vector<char> binary = IntToBinary(x1, 32);
            int x2 = maximumXOR(root, binary, 0);

            maxim = max(maxim, x1 ^ x2);
        }
        return maxim;
    }
};
