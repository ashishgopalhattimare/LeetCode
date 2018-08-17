#include <bits/stdc++.h>

// what if only new word are not present.. but the surrounding words are valid

using namespace std;

void wordBreak(int index, string str, unordered_set<string>& dictionary, vector<string>& v, vector<vector<string> >& result)
{
	if(index == str.length()) {
		if(find(result.begin(), result.end(), v) == result.end()) {
			result.push_back(v);
			return;
		}
	}

	string currentWord = "";
	for(int i = index; i < str.length(); i++) {
		currentWord += str[i];
		
		if(dictionary.find(currentWord) != dictionary.end()) {
			v.push_back(currentWord);
			wordBreak(i+1, str, dictionary, v, result);
			v.pop_back();
		}
	}
}

int main(int argc, char* argv[])
{
	int n;
	string str;

	vector<vector<string> > result;
	unordered_set <string> dictionary;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> str;
		dictionary.insert(str);
	}

	cin >> str;

	vector<string> v;
	wordBreak(0, str, dictionary, v, result);

	return 0;
}

// i like sam sung samsung mobile ice cream icecream man go mango