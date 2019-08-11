#include <bits/stdc++.h>

using namespace std;

bool needToCompress(string& input)
{
	int originalLen = input.length();
	int resultLen = 0;

	char prev = input[0];
	int count = 1;
	for(int i = 1; i < input.length(); i++) {
		if(prev == input[i]) count++;
		else {
			resultLen += (log10(count)+2);
			count = 1;
		}
		prev = input[i];
	}
	resultLen += (log10(count)+2);

	return originalLen > resultLen;
}

int main(int argc, char const *argv[])
{
	string input, result = "";
	char prev;
	int count;

	cin >> input;

	if(needToCompress(input)) {
		prev = input[0];
		count = 1;
		for(int i = 1; i < input.length(); i++) {
			if(prev == input[i]) count++;
			else {
				result.push_back(prev);
				result.append(to_string(count));
				count = 1;
			}
			prev = input[i];
		}

		result.push_back(prev);
		result.append(to_string(count));
	}
	else {
		result = input;
	}

	cout << result << endl;

	return 0;
}