// https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/dislikes-and-party-567b9605/
// Set 1
// March Circuit '20

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    LL N;
    cin >> N;

    LL handshakes = (N*(N-1)) >> 1;
    
    unordered_map<int, unordered_set<int>> mapi;

    int person, other, a, b;
    for(int i = 1; i <= 10; ++i) {
    	cin >> person;

    	mapi[person].insert(-1); // default
    	for(int j = 1; j <= 9; ++j) {
    		cin >> other;

    		mapi[other].insert(-1); // default
    		
    		a = person; b = other;
    		if(a > b) swap(a, b);
            
    		if(mapi[a].find(b) == mapi[a].end()) {
    			mapi[a].insert(b);
    			handshakes--;
    		}
    	}
    }

    cout << handshakes << endl;
    
    return 0;
}
