// HashTable - O(n)
// sorting   - O(nlogn)

// algoexpert

#include <bits/stdc++.h>
using namespace std;

vector<int> largestRange(vector<int> array) {
	unordered_map<int,bool>hash;
	
	for(int i : array) hash[i] = true;
	
	int maxRange = INT_MIN, minv = 0, maxv = 0;
	int low, high;
	for(int x : array) {
			
			if(hash[x] == false) continue;
			hash.erase(x);
		
			high = x+1; // start from here
			low = x-1; // start from here
			
			// look for the next element
			while(hash.find(high) != hash.end()) { // erase when once encountered
				hash.erase(high++);
			}
			// look for the prev element
			while(hash.find(low) != hash.end()) { // erase when once encountered
				hash.erase(low--);
			}
		
			low++; high--;
			if(maxRange < (high-low+1)) { // new largest range found
				maxRange = (high-low+1);
				maxv = high;
				minv = low;
			}
	}
	
	return {minv, maxv};
}

