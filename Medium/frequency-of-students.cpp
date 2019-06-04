// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/frequency-of-students/
// Easy, HashTables

#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string, int> hash;
	
	string c;
	int n;
	cin >> n;
	
	while(n--) {
		cin >> c;
		hash[c]++;
	}
	
	for(auto itr = hash.begin(); itr != hash.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}
	
	return 0;
}
