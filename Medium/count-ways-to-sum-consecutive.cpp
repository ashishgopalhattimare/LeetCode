#include <bits/stdc++.h>

using namespace std;

int algorithm(int n)
{
    if(n == 1) return 0;

    int s = 1, e = 1;
    int sum = 0;

    int count = 0;
    while(s < n) {
        while(true) {
            if(sum + e > n) break;
            sum += e;
            e++;
        }
        if(sum == n) count++;
        sum-=(s++);
    }
    return count;
}

int main()
{
    int n = 10;
    cout << algorithm(n) << endl;
    return 0;
}