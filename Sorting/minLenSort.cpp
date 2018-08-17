#include <bits/stdc++.h>

using namespace std;

// Find the minimum length unsorted subarray, sorting which makes the complete array sorted

int minLengthSort(vector<int> &ar)
{
	// subarray sort
	int start, end = ar.size() - 1;

	for(start = 0; start != end; start++) { // find the unorder from the left
		if(ar[start] > ar[start+1]) break;
	}
	if(start == end) return -1; // if the start becomes end --> sorted

	for( ; end != start; end--) { // find the unorder from the right
		if(ar[end-1] > ar[end]) break;
	}

	int minim = INT_MAX, maxim = INT_MIN;
	for(int i = start; i <= end; i++) { // find the min and max between start and end O(n)
		minim = min(minim, ar[i]);
		maxim = max(maxim, ar[i]);
	}

	for( ; start > 0; start--) { // find the element [0-start] which is smaller than min
		if(ar[start-1] <= minim) break;
	}
	for( ; end < ar.size()-2; end++) { // find the element [end-(n-1)] which is larger than max
		if(ar[end+1] >= maxim) break;
	}

	printf("%d %d\n", start, end);
	return (end-start+1);
}

int main(int argc, char* argv[])
{
	int n, data;
	vector<int>ar;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		ar.push_back(data);
	}
	cout << minLengthSort(ar) << endl;

	return 0;
}