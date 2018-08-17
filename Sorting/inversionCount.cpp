#include <bits/stdc++.h>

using namespace std;

void countInversion(vector<int> &ar, int start, int end, int *count)
{
	if(start == end) return;

	int mid = start + (end - start)/2;

	countInversion(ar, start, mid, count);
	countInversion(ar, mid+1, end, count);

	int i = start;
	int j = mid+1;

	vector<int>v;
	while(i <= mid && j <= end) {
		if(ar[i] > ar[j]) {
			*count = *count + (mid - i + 1);
			v.push_back(ar[j++]);
		}
		else {
			v.push_back(ar[i++]);
		}
	}

	while(i <= mid) v.push_back(ar[i++]);
	while(j <= end) v.push_back(ar[j++]);

	j = 0;
	for(int i = start; i <= end; i++) {
		ar[i] = v[j++];
	}
	return;
}

int main(int argc, char* argv[])
{
	int n, d;
	vector<int> ar;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		ar.push_back(d);
	}

	int count = 0;
	countInversion(ar, 0, ar.size()-1, &count);

	cout << count << endl;

	return 0;
}