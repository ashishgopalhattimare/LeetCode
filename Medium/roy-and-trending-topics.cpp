// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/
// Easy, Priority Queue (Max Heap)

#include <bits/stdc++.h>
using namespace std;

#define POST 50
#define LIKE 5
#define COMMENT 10
#define SHARE 20

#define ll long long int

struct Topic
{
	int id;
	long long int Z, change;
	Topic(int id, ll z, ll p, ll l, ll c, ll s) : id(id) {
		Z = (POST * p) + (LIKE * l) + (COMMENT * c) + (SHARE * s);
		change = abs(Z - z);
	}
	
	// < : max heap || > : min heap
	bool operator<(const Topic& other) const {
		if(change == other.change) return id < other.id;
		return change < other.change;
	}
};

int main()
{

	priority_queue<Topic>pq;

	int ID, Z, P, L, C, S;
	int n;

	cin >> n;
	while(n--) {
		cin >> ID >> Z >> P >> L >> C >> S;
		pq.push( {ID, Z, P, L, C, S} );
	}

	for(int i = 0; i != 5 && !pq.empty(); i++) {
		printf("%d %lld\n", pq.top().id, pq.top().Z);
		pq.pop();
	}

	return 0;
}

