// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/maximum-subarray-sum-of-subarrays-7f33aefa/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int maxim, sum;
	int n;

	cin >> n;

	vector<int>nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	unordered_set<long long int> set;

	for(int i = 0; i < n; i++) {
		maxim = INT_MIN;
		sum = 0;
		for(int j = i; j < n; j++) {
			sum += nums[j];

			maxim = max(maxim, sum);
			set.insert(maxim);
			
			if(sum < 0) sum = 0;
		}
	}

	sum = 0;
	for(auto itr = set.begin(); itr != set.end(); itr++) {
		sum = sum + *itr;
	}
	cout << sum << endl;

	return 0;
}

