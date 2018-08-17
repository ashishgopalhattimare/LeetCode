#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
	int n, data;
	vector<int>ar;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> data;
		ar.push_back(data);
	}

	bool midElement = true;
	int midValue = ar[0];

	for(int i = 1; i < n; i++) {
		if(midElement == false && midValue < ar[i]) {
			midElement = true;
			midValue = ar[i];
		}
		else if(midValue > ar[i]) {
			midElement = false;
		}
	}

	if(midElement) {
		printf("%d\n", midValue);
	}
	else {
		printf("-1\n");
	}

	return 0;
}