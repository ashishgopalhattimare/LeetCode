#include <bits/stdc++.h>

using namespace std;

void generatePrimes(vector<bool>& nums) {
	for(int i = 0; i < nums.size(); i++){
		nums[i] = true;
	}
	nums[1] = true;
	for(int i = 2; i * i < nums.size(); i++) {
		if(nums[i] == true) {
			for(int j = i+i; j < nums.size(); j+=i) {
				nums[j] = false;
			}
		}
	}
	return;
}

int main()
{
	int n;
	cin >> n;

	vector<bool>nums(n/2 + 1);

	generatePrimes(nums);
	vector<int>primes;
	for(int i = 1; i < nums.size(); i++) {
		if(nums[i]) primes.push_back(i);
	}

	std::vector<pair<int,int>> v;
	for(int i = 0; i < primes.size(); i++) {
		for(int j = i+1; j < primes.size(); j++) {
			if(primes[i] * primes[j] <= n) {
				v.push_back({primes[i], primes[j]});
			}
			else break;
		}
	}

	for(pair<int,int>& x : v) cout << x.first << " " << x.second << endl;

	return 0;
}