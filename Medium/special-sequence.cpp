#include <bits/stdc++.h>

using namespace std;

bool explore1(vector<int>& sol, int gap)
{
	if(gap == 0) return true; // all gaps are filled

	for(int i = sol.size()-1; i >= 0; i--) {
		if(i-gap-1 < 0) return false;
		if(sol[i] == 0 && sol[i-gap-1] == 0) {
			sol[i] = sol[i-gap-1] = gap;

			if(explore1(sol, gap-1)) {
				return true;
			}
			else {
				sol[i] = sol[i-gap-1] = 0;
			}
		}
	}
	return false;
}

void optimalSol(int n) {
	vector<int> solution(n+n);

	if(explore1(solution, n)) {
		for(int x : solution) cout << x << " ";
		printf("\n");
	}
	return;
}

int main()
{
	int n;
	cin >> n;

	optimalSol(n);

	return 0;
}