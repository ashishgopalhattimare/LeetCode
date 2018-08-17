#include <bits/stdc++.h>

using namespace std;

void permutation(vector<int> &A, int start, vector<vector<int> > &V)
{
	if(start == A.size() - 1) {
		V.push_back(A);
		return;
	}

	int temp;
	for(int i = start; i < A.size(); i++)
	{
		temp = A[start];
		A[start] = A[i];
		A[i] = temp;

		permutation(A, start+1, V);

		temp = A[start];
		A[start] = A[i];
		A[i] = temp;
	}
	return;
}

void permute(vector<int> &A)
{
	vector<vector<int> > V;

	permutation(A, 0, V);

	for(int i = 0; i < V.size(); i++) {
		for (int j = 0; j < V[i].size(); ++j) {
			printf("%d ", V[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	int n, d;

	vector<int> V;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> d;
		V.push_back(d);
		/* code */
	}

	permute(V);

	return 0;
}