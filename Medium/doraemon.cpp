// https://www.codechef.com/JAN20B/problems/CHFDORA
// Easy

#include <bits/stdc++.h>

using namespace std;

static int N, M;

bool inrange(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

int doraemon()
{
	vector<vector<int>> matrix(N, vector<int>(M));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}

	int result = 0;
	int k;

	// subMatrix calculation
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			k = 0;
			while(inrange(i-k,j) && inrange(i+k,j) && inrange(i,j-k) && inrange(i,j+k))  {
				if(matrix[i-k][j] == matrix[i+k][j] && matrix[i][j-k] == matrix[i][j+k]) {
					result++;
				}
				else break;
				
				k++;
			}
		}
	}

	return result;
}

int main()
{
	int t;

	cin >> t;
	while(t--) {
		cin >> N >> M;

		cout << doraemon() << endl;
	}

	return 0;
}