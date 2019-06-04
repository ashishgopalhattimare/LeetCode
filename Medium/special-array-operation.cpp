// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/pk-and-special-array-operation-1-7bd52ad1/
// Easy, Sorted Map, Iterator (Front, Reverse), element counter, erase()
// Tough

#include <bits/stdc++.h>
using namespace std;

int main() {

	long long int sum = 0;
	long long int n, q, d;

	cin >> n >> q;
	map<long long int, int> mymap;
	for(int i = 0; i < n; i++) {
		cin >> d;
		sum+=d;
		mymap[d]++;
	}

	vector<long long int>result(q);
	int queryno;
	vector<pair<int,int>>arr(q);
	for(int i = 0; i < q; i++) {
		cin >> queryno;
		arr[i] = make_pair(queryno, i);
	}

	// pair<int,int> == pair<seudo position, actual position>
	// Encounter queries in sorted order
	sort(arr.begin(), arr.end(), [](pair<int,int>& a, pair<int,int>& b) {
	    return a.first < b.first;
	});

	int query = 0;
	for(int i = 0; i < n && query < q; i++) {

		// while query is current index : insert sum to respective index
		// in resultant query vector
		while(query < q && arr[query].first == i) { // print sum
        	result[arr[query].second] = sum;
			query++;
		}

		auto itr1 = mymap.begin(); // smallest element iterator
		auto itr2 = mymap.rbegin();// largest element iterator

		// Get values at iterator position
		long long int small = itr1->first, large = itr2->first;

		// Decrement the largest element, if its cout is 1, remove it
		if(mymap[small] == 1) {
			mymap.erase(small);
		}
		else mymap[small]--; // decrement it

		// Decrement the largest element, if its cout is 1, remove it
		if(mymap[large] == 1) {
			mymap.erase(large);
		}
		else mymap[large]--; // decrement it

		// push new element into the sorted map
		long long int newelement = large - small;

		sum = sum - (large + small) + newelement;
		mymap[newelement]++;
	}

	// Output the result
	for(long long int s : result) {
		cout << s << endl;
	}

    return 0;
}

