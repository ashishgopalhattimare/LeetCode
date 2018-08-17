#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/alternate-vowel-and-consonant-string/0

using namespace std;

struct Node {
	char c;
	int freq;

	Node(char x, int f) : c(x), freq(f) {}

	bool operator < (const Node &temp) const {
		return c > temp.c;
	}
};

bool isVowel(char c)
{
	switch(c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': return true;
	}

	return false;
}

void printString(priority_queue<Node> &first, priority_queue<Node> &second)
{
	int ff, fs;
	char cf, cs;
	bool firstpq = true;

	ff = first.top().freq;
	fs = second.top().freq;
	while(!first.empty() || !second.empty())
	{
		if(firstpq) {
			printf("%c", first.top().c);
			ff--;

			if(ff == 0) {
				first.pop();
				if(!first.empty()) {
					ff = first.top().freq;
				}
			}
		}
		else {
			printf("%c", second.top().c);
			fs--;

			if(fs == 0) {
				second.pop();
				if(!second.empty()) {
					fs = second.top().freq;
				}
			}
		}

		firstpq = !(firstpq);
	}

	printf("\n");
	return;
}

int main(int argc, char* argv[])
{
	int t, n;
	string str;
	int noVowel, noConsonant;

	cin >> t;
	while(t--) {
		cin >> n >> str;

		unordered_map<char, int> alphabet;

		priority_queue <Node> vowel;
		priority_queue <Node> consonant;

		for(int i = 0; i < n; i++) {
			if(alphabet.find(str[i]) != alphabet.end()) {
				alphabet[str[i]]++;
			}
			else {
				alphabet[str[i]]=1;
			}
		}

		noVowel = noConsonant = 0;
		for (auto itr = alphabet.begin(); itr != alphabet.end(); itr++)
		{	
			Node item(itr->first, itr->second);

			if(!isVowel(itr->first)) {
				noConsonant += itr->second;
				consonant.push(item);
			}
			else {
				noVowel += itr->second;
				vowel.push(item);	
			}
		}

		if(noVowel == noConsonant) {
			if(vowel.top().c < consonant.top().c) {
				printString(vowel, consonant);
			}
			else {
				printString(consonant, vowel);
			}
		}
		else if(noVowel == noConsonant + 1) { // more vowels

			if(noVowel == 1) {
				printf("%c\n", vowel.top().c);
			}
			else {
				printString(vowel, consonant);
			}
		}
		else if(noConsonant == noVowel + 1) { // more consonants
			
			if(noConsonant == 1) {
				printf("%c\n", consonant.top().c);
			}
			else {
				printString(consonant, vowel);
			}
		}
		else {
			printf("-1\n");
		}
	}

	return 0;
}