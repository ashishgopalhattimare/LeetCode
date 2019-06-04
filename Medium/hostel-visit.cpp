// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/hostel-visit/
// Easy, Max Heap PQ

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct Hostel
{
	ll distance;
	Hostel(ll x, ll y) {
		distance = x*x + y*y;
	}
	
	// Max Heap
	bool operator<(const Hostel& other) const {
		return distance < other.distance;
	}
};

int main()
{

	priority_queue<Hostel>pq;

	int n, k, type;
	ll x, y;
	cin >> n >> k;

	while(n--) {
		cin >> type;
		if(type == 1) {
			cin >> x >> y;

			pq.push( {x, y} );
			
			// Keep Atmost K hostel
			if(pq.size() > k) pq.pop();
		}
		else {
			cout << pq.top().distance << endl;
		}
	}

	return 0;
}

