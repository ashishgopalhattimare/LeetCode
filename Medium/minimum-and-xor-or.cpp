// https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/minimum-and-xor-or-6a05bbd4/
// Set 2
// March Circuit '20

/**
 * You are given an array  of  integers. Determine the minimum 
 * value of the following expression for all valid i,j:
 * (A[i] and A[j]) xor (A[i] or A[j]), where i != j.
 *
 * Note : Sum of N overall testcases does not exceed 10^6
 **/

#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector<int>& A)
{
	int minim = INT_MAX;
	for(int i = 0; i < A.size(); i++) {
		for(int j = i+1; j < A.size(); j++) {
			minim = min(minim, (A[i] & A[j]) ^ (A[i] | A[j]));
		}
	}

	return minim;
}

int optimal(vector<int>& A)
{
	int minim = INT_MAX;

	sort(A.begin(), A.end());
	for(int i = 0, j = 1; j < A.size(); i++, j++) {
		minim = min(minim, (A[i] & A[j]) ^ (A[i] | A[j]));
	}

	return minim;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;

    cin >> t;
    while(t--)
    {
    	cin >> n;
    	vector<int>arr(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> arr[i];
    	}

    	cout << optimal(arr) << endl;
    }

    return 0;
}