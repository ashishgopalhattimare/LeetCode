#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> & ar, int start, int end, int val)
{
	if(start > end) return -1;

	// two elements in the range
	if(end == start+1) {
		if(ar[start] == val) return start;
		else if(ar[end] == val) return end;

		return -2;
	}

	// only one element in the range
	if(start == end) {
		if(ar[start] == val) return start;
		return -4;
	}

	// minimum 3 elements in the range
	int mid = start + (end - start)/2;

	if(ar[mid] == val) {
		if(ar[mid-1] == val) {
			return binarySearch(ar, start, mid-1, val);
		}
		return binarySearch(ar, mid, end, val);
	}
	else if(ar[mid] > val) {
		return binarySearch(ar, start, mid-1, val);
	}
	return binarySearch(ar, mid+1, end, val);
}

int countDistinctK(vector<int> & ar, int k)
{
	unordered_map<int,int> hash;
	sort(ar.begin(), ar.end());

	int maxElement = ar[ar.size()-1];

	int count = 0, tempCount = 0;
	for(int i = 0; i < ar.size(); i++) {
		
		if(hash.find(ar[i]) != hash.end())
		{
			if(hash[ar[i]] == -1) continue;
			count += hash[ar[i]];

			continue;
		}


		if(ar[i] + k > maxElement) { break; }
		else {
			int index = binarySearch(ar, i, ar.size()-1, ar[i] + k);
			// printf("%d -> %d = %d\n", ar[i], index, ar[i] + k);

			if(index == -1) {
				hash[ar[i]] = -1;
			}
			else {
				tempCount = 1;
				for(index = index + 1; index < ar.size(); index++) {
					if(ar[index] == ar[i] + k) tempCount++;
					else break;
				}

				count+=tempCount;

				hash[ar[i]] = tempCount;
			}
		}
	}

	return count;
}

int main(int argc, char* argv[])
{
	int n, k, data;
	vector<int> ar;

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> data;
		ar.push_back(data);
	}

	cout << countDistinctK(ar, k) << endl;

	return 0;
}