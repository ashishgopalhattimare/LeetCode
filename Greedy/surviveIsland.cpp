#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
	int t;
	int s, n, m;

	int stock, lambda;
	int count, dayDone;

	cin >> t;
	while(t--) {
		cin >> s >> n >> m;

		if(n < m) {
			printf("-1\n");
			continue;
		}
		else if(n == m)
		{
			if(s > 6) printf("-1\n");
			else printf("%d\n", s);

			continue;
		}

		// n - maximum i can buy each day
		// s - no. of days
		// m - food required each day

		// n > m
		else {
			
		}
	}

	return 0;
}