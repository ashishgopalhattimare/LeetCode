// https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/shift-and-replace-d96fc236/
// Set 2
// March Circuit '20

// TLE and Brute Force Approach

#include<bits/stdc++.h>
using namespace std;

bool debug = true;

int difference(vector<int> arr, vector<int>& req, int k, int N, int minim, int rotate)
{
	int differ = 0;
	for(int i = 1; i <= N; i++, k++) {
		if(req[i] != arr[k]) differ++;

		if(k == N) k = 0;
	}
	return differ;
}
void rotateLeft(vector<int>& arr) {
	
	for(int i = 1; i < arr.size(); i++) {
		arr[i-1] = arr[i];
	}
	arr[arr.size()-1] = arr[0];
}

vector<int> bruteForce(vector<int> arr, vector<int>& req, int N)
{
	int minim = N, replace, rotate;
	int x, y;
	for(int i = 1; i <= N/2; i++) {

		rotate = i-1;
		replace = difference(arr, req, i, N, minim, rotate);    
		
		if(rotate + replace > minim) break;
		
		x = rotate; y = replace;
		minim = rotate + replace;
	}
	
	return {x, y, minim};
}


int computeDistance(int X, int N, int i) {
	if(X < i) return i-X;
	else if(X > i) return abs(1-i) + 1 + (N-X);

	return 0;
}

void phase1(vector<int>& arr, vector<int>& shifts, int N)
{
	int distance;
	for(int i = 1; i < arr.size(); i++) {

		if(arr[i] <= N) {
			shifts[computeDistance(arr[i], N, i)]++;
		}
	}
	// print(shifts);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);

	ifstream infile;
	infile.open("input.txt");

    int n, q;

    if(debug) infile >> n;
    else cin >> n;

    vector<int>arr(n+1), required(n+1);
    for (int i = 1; i <= n; ++i) {

    	if(debug) infile >> arr[i];
    	else cin >> arr[i];

    	required[i] = i;
    }

	vector<int>shifts(n+1, 0);

	phase1(arr, shifts, n);

    int x, b;

    if(debug) infile >> q;
    else cin >> q;

    while(q--) {

    	if(debug) infile >> x >> b;
    	else cin >> x >> b;
    	
    	if(arr[x] <= n) shifts[computeDistance(arr[x], n, x)]--;
    	arr[x] = b;

		if(arr[x] <= n) shifts[computeDistance(arr[x], n, x)]++;

		int minim = INT_MAX;
		int x, y;
		for(int i = 0; i <= n; i++) {
			if(minim > i + (n-shifts[i])) {
				minim = i + (n-shifts[i]);
				x = i;
				y = shifts[i];
			}
		}
		printf("%d\n", minim);
	}

    return 0;
}