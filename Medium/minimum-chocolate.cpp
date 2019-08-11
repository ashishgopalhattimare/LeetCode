#include <bits/stdc++.h>
using namespace std;

struct Class
{
	int strength;
	int cakes;
	int index;

	bool operator<(const Class& other) const {
		if(cakes == 0 && cakes == other.cakes) {
			return strength < other.strength;
		}
		if(cakes == 0 && other.cakes) true;
		return strength * other.cakes < other.strength * cakes;
	}
};

void iteratePQ(priority_queue<Class> pq)
{
	while(!pq.empty()) {
		printf("[%d,%d,%d] ", pq.top().index, pq.top().cakes, pq.top().strength);
		pq.pop();
	}
	printf("\n");
}

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {

	int N, B, strength;

	cin >> N >> B;

	priority_queue<Class>pq;

	for(int i = 0; i < N; i++) {
		cin >> strength;
		pq.push({strength, 0, i});
	}

	Class curr;
	for(int i = 0; i < B; i++) {
		curr = pq.top();
		pq.pop();

		curr.cakes++;
		pq.push(curr);
	}

	int maxim = INT_MIN;
	while(!pq.empty()){
		curr = pq.top();
		maxim = max(maxim, ceil(curr.strength/(curr.cakes*1.0)));
		pq.pop();
	}

	cout << maxim << endl;

	return 0;
}

