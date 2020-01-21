#include <bits/stdc++.h>

using namespace std;

static int matrix[2007][2007];

void constructMatrix(int r1, int r2, int c1, int c2, int v1, int v2)
{
	if(r1 == r2) { // matrix of size 1x1
		matrix[r1][c1] = 1;
		return;
	}

	int R = r2-r1+1, C = c2-c1+1;
	int V = v2-v1+1;

	if(R == 2) {
		matrix[r1][c1] = v1;
		matrix[r2][c2] = v1;
		if(V % 2 == 1) {
			matrix[r1][c2] = v1+1;
			matrix[r2][c1] = v2;
		}
		else {
			matrix[r1][c2] = v2;
			matrix[r2][c1] = v2;
		}
		return;
	}

	int midI = R/2; // 4 2
	int midV1 = V/2; // 1-15 (1-7 8-15)

	constructMatrix(r1, r1+midI-1, c1, c1+midI-1, v1, v1+midV1-1); // top-left
	constructMatrix(r1, r1+midI-1, c1+midI, c2, v1+midV1, v1+midV1+((V-midV1)/2)-1); // top-right
	constructMatrix(r1+midI, r2, c1, c1+midI-1, v1+midV1+((V-midV1)/2), v2); // bottom-left

	for(int r = r1+midI, i = 0; r <= r2; r++, i++) {
		for(int c = c1+midI, j = 0; c <=c2; c++, j++) {
			matrix[r][c] = matrix[r1+i][c1+j];
		}
	}
}

void printMatrix(int n)
{
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int t;
	int n;

	cin >> t;
	while(t--) {
		cin >> n;

        
		if(n == 1 || n % 2 == 0) {
			constructMatrix(1, n, 1, n, 1, 2*n-1);
			printf("Hooray\n");
			printMatrix(n);
		}
		else {
			printf("Boo\n");
		}
	}

	return 0;
}