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
			lambda = 0;
			stock = 0;
			count = 0;
			dayDone = 1;
			
			do {
				if(dayDone + lambda >= s) {
					break;
				}
				
				printf("Amount = %d\n", stock + n);
				if((dayDone + lambda) % 7 == 0) {
					dayDone += (lambda-1);
					
					stock = n + stock;
					lambda = stock / m;
					stock = stock % m;
				}
				else {
					dayDone += (lambda);
					stock = n + stock;
					lambda = stock / m;
					stock = stock % m;
				}
				
				printf("DayDone = %d\n", dayDone);
				printf("Stock = %d\n", stock);
				printf("lambda = %d\n\n", lambda);

				count++;

			}while(true);
			cout << count << endl;
		}
	}

	return 0;
}