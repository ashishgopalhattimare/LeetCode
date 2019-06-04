// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	long long int a, b, c;

	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	priority_queue<int>pq;
	for(int i = 0; i < n; i++) {
		pq.push(arr[i]);

		if(pq.size() < 3) printf("-1\n");
		else {
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			c = pq.top(); pq.pop();

			cout << a * b * c << endl;

			pq.push(c); pq.push(b); pq.push(a);
		}
	}

    return 0;
}

