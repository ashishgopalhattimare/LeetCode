#include <bits/stdc++.h>

using namespace std;

std::string isMatch(std::string word, std::string pattern)
{
	int slen = word.length(), plen = pattern.length();
	int sIndex = 0, pIndex = 0;
	int starIndex = -1, sTempIndex = -1;

	cout << "s = " << "\"" << word << "\"" << endl;
	cout << "p = " << "\"" << pattern << "\"" << endl;

	// While the word is iterable
	while(sIndex < slen) {
		// if pattern is '?' or pattern char is equal to word char
		if(pIndex < plen && (pattern[pIndex] == '?' || word[sIndex] == pattern[pIndex])) {
			sIndex++;
			pIndex++;
		}
		// if the pattern is '*'
		else if(pIndex < plen && pattern[pIndex] == '*') {
			starIndex  = pIndex; // store pIndex
			sTempIndex = sIndex; // store sIndex

			// when * matches no character
			pIndex++;
		}
		// when if the pattern != word and there are no * character
		// in pattern
		else if(starIndex == -1) {
			return "Output: false\n";
		}
		// There is starIndex previously encountered
		// backtrack to that index
		else {
			pIndex = starIndex +1;
			sIndex = sTempIndex+1;
			sTempIndex++;
		}
	}	

	for(int i = pIndex; i < plen; i++) {
		if(pattern[i] != '*') return "Output: false\n";
	}
	return "Output: true\n";
}

int main(int argc, char const *argv[])
{
	cout << isMatch("abceb","a*b") << endl;
	cout << isMatch("acdcb","a*c?b") << endl;
	return 0;
}