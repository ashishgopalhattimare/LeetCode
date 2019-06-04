// https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/traffic-signal/
// Medium, Queue

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	unordered_map<char, int>map;
	map['R'] = 0;
	map['Y'] = 1;
	map['G'] = 2;

	vector<int>shifts(n, 0), tshift(n, 0);
	vector<char>color(n);

	for(int i = 0; i < n; i++) {
		cin >> color[i];
	}

	int curPos, needShift, result = 0;
	int totalShift = 0;

	for(int i = 0; i < n; i++) {

		totalShift += tshift[i]; // appends shifts from previous required rotations (hackerrank concept)

		int curPos = totalShift + map[color[i]] + shifts[i]; // current pos after rotations
		int needShift = map['G'] - curPos%3; // how far from 'G'

		result += needShift; // add needed to shifts to result

		// HackerRank Ceoncept ('Algorithmic Crush')
		if(i+1 < n) tshift[i+1] += needShift; // increment next by currShift
		if(i+k < n) { // decrement totalshifts from the next kth+1 by currShift
		    tshift[i+k] -= needShift;
		}
	}

	cout << result << endl;
	return 0;
}

