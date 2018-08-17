#include <bits/stdc++.h>

using namespace std;

// Find whether an array is subset of another array

bool subsetArray(vector<int> &a1, vector<int> a2)
{
	unordered_map<int, int>hash;

	// a2 is a subset of a1 vector array

	for(int i = 0; i < a2.size(); i++) {
		if(hash.find(a2[i]) == hash.end()) { // element not in the hash
			hash[a2[i]] = i;
			a2[i] = 1;
		}
		else {
			a2[hash[a2[i]]]++;
			a2[i] = 0;
		}
	}

	for(int i = 0; i < a1.size(); i++) {
		if(hash.find(a1[i]) != hash.end()) {
			a2[hash[a1[i]]]--;
		}
	}

	for(int i = 0; i < a2.size(); i++) {
		if(a2[i] > 0) return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	int n, m, data;
	vector<int>a1, a2;

	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		cin >> data;
		a1.push_back(data);
	}
	for (int i = 0; i < m; ++i) {
		cin >> data;
		a2.push_back(data);
	}

	if(subsetArray(a1, a2)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	return 0;
}