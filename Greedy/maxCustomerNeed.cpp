#include <bits/stdc++.h>

using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-number-of-customers-that-can-be-satisfied-with-given-quantity/0s

bool compare(pair<int,int> &a, pair<int,int> &b)
{
	return (a.second < b.second);
}

int main()
{
	int t;
	int A, B, capacity;
	int a, b, n, d;

	cin >> t;
	while(t--) {
		cin >> n >> d;
		cin >> A >> B;

		vector<pair<int, int> > V;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			V.push_back(make_pair(i+1, a*A + b*B));
		}

		sort(V.begin(), V.end(), compare);

		vector<int>result;

		for(int i = 0; i < V.size(); i++) {
			if(V[i].second <= d) {
				result.push_back(V[i].first);

				d -= V[i].second;
			}
		}
        
        cout << result.size() << endl;
		for (int i = 0; i < result.size(); ++i) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}

	return 0;
}