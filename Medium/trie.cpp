//============================================================================
// Name        : template.cpp
// Author      : Ashish Gopal Hattimare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
	vector<Trie*> child;
	char bit, end;

	Trie() {
		child = {NULL, NULL};
		bit = '0';
		end = '-';
	}

	// 0 1 0 1 1 1
	void construct(vector<char>& binary, int index) {
		printf("*");
		if(index == (int) (binary.size())) {
			return;
		}

		bit = binary[index];
		printf("%c", bit);
		if(index == (int) (binary.size()-1)) {
			printf("\n");
			end = '$';
		}
		else {
			Trie **nextNode;
			if(binary[index+1] == '0') { // go left child
				*nextNode = child[0];
			}
			else { // go right child
				*nextNode = child[1];
			}
			if(*nextNode == NULL) *nextNode = new Trie();
			(*nextNode)->construct(binary, index+1);
		}
	}

	void traverse(Trie *head, string str) {
		if(head == NULL) return;

		str.push_back(head->bit);
		if(head->end == '$') {
			cout << str << endl;
			return;
		}

		traverse(head->child[0], str);
		traverse(head->child[1], str);
		return;
	}
};

class Root
{
public:
	vector<Trie*>rootnode;
	vector<int>nums;

	const int MAX_BIT = 3;

	vector<char> getBinary(int num, int bits) {
		vector<char> binary(bits, '0');
		for(int i = bits-1; i >= 0 && num; i--) {
			binary[i] = ('0' + (num&1));
			num >>= 1;
		}
		return binary;
	}

	Root(vector<int> arr) {
		rootnode = {new Trie(), new Trie()};
		nums = arr;
	}

	void contructBinaryTrie() {
		for(int x : nums) {
			vector<char> binary = getBinary(x, MAX_BIT);

			// 0 - left, 1 - right
			int index = binary[0]-'0';
			rootnode[index]->construct(binary, 0);
		}
	}

	void traverseTrie() {
		for(Trie *head : rootnode) {
			cout << head << endl;
		}
	}
};

int main() {

	Root root = Root({1,2,7});

	root.contructBinaryTrie();
	root.traverseTrie();
	return 0;
}

