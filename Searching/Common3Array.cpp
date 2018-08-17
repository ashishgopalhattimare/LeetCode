#include <bits/stdc++.h>

using namespace std;

vector<int> computeCommon(vector<int>& A, vector<int>& B)
{
	int i = 0, j = 0;
	vector<int> V;
	while(i < A.size() && j < B.size())
	{
		if(A[i] == B[j]) {
			V.push_back(A[i]);
			i++; j++;
		}
		if(A[i] < B[j]) i++;
		else j++;
	}

	return V;
}

int main(int argc, char* argv[])
{
	int t, d;
	int a, b, c;
	vector<int> A, B, C;

	cin >> a >> b >> c;
	for(int i = 0; i < a; i++) {
		cin >> d;
		A.push_back(d);
	}
	for(int i = 0; i < a; i++) {
		cin >> d;
		B.push_back(d);
	}
	for(int i = 0; i < a; i++) {
		cin >> d;
		C.push_back(d);
	}


	vector<int>V = computeCommon(A, B);
	V = computeCommon(V, C);

	for (int i = 0; i < V.size(); ++i) {
		printf("%d ", V[i]);
	}
	printf("\n");

	return 0;
}