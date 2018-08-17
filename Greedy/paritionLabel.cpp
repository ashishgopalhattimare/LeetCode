#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/partition-labels/description/

vector<int> partitionLabels(const string S)
{
	vector<int> V;

	
}

int main(int argc, char* argv[])
{
	string str;

	cin >> str;

	vector<int> result = partitionLabels(str);

	for(int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}