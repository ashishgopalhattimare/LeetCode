// https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/weird-planet-2000a170/
// Medium, Queue, TLE

#include <bits/stdc++.h>

using namespace std;

struct Crew
{
	int s, e, h;
	Crew(int s, int e, int h) : s(s),e(e),h(h)
	{}

	bool operator<(const Crew& other) const {
	    return h < other.h;
	}
};

struct People
{
	int h, i, t;
	People(int h, int t, int i):h(h),t(t),i(i)
	{}
};

int main()
{
	int H, C, Q;
	int h, S, E;

	cin >> H >> C >> Q;

	vector<Crew>crew;
	vector<People>people;

	for(int i = 0; i < C; i++) {
		cin >> h >> S >> E;
		crew.push_back({S, E, h});
	}
	for(int i = 0; i < Q; i++) {
		cin >> h >> S;
		people.push_back({h, S, i});
	}

	std::sort(crew.begin(), crew.end(), [](Crew& a, Crew& b) {
		return a.s < b.s;
	});

	std::sort(people.begin(), people.end(), [](People& a, People& b) {
		return a.t < b.t;
	});

	vector<string>output(Q, "YES");

	int ic=0, ip=0;

	priority_queue<Crew>pq;
	                              /* Crew Priority is not empty or some are left */
	for(int i = 0; i <= H && (ic < crew.size() || !pq.empty()) && ip < people.size(); i++) {

		// Push all the Members whose time has come to enter
		while(ic < crew.size() && crew[ic].s == i) {
			pq.push(crew[ic++]);
		}

		// While people arrival time is equal to curr time
		while(ip < people.size() && people[ip].t == i) {
			// If no crew available, they are allowed, else
			// if any available crew's height is greater than people height
			// dont allow them
			if(!pq.empty() && pq.top().h >= people[ip].h) {
				output[people[ip].i] = "NO";
			}
			ip++;
		}

		// Release Crew whose time is up
		while(!pq.empty() && pq.top().e <= i) {
			pq.pop();
		}
	}

	for(string x : output) {
		cout << x << endl;
	}
	return 0;
}
