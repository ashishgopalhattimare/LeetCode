#include <bits/stdc++.h>

using namespace std;

long long int generator(int n)
{
	list<long long int>ll;
	ll.push_back(9);

	long long int curr, result;
	while(true) {
		curr = ll.front();
		ll.pop_front();

		if(curr % n == 0) return curr;
		ele {
			ll.push_back(curr*10+0);
			ll.push_back(curr*10+9);
		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	cout << generator(n) << endl;

	return 0;
}