// https://www.hackerrank.com/contests/codesprint5/challenges/is-fibo/problem
// Easy

#include <bits/stdc++.h>

using namespace std;

// O(logn) to find nth Fibonacci number from 0 1 1 2 3 5 series
vector<long> fib(long n)
{
    if(n == 0) return {0,1};
    
    vector<long> p = fib(n >> 1);
    
    long c = p[0] * (2 * p[1] - p[0]);
    long d = p[0]*p[0] + p[1]*p[1];
    
    if(n&1) return {d, c+d};
    return {c, d};
}

// Complete the solve function below.
string solve(long n) {

    long low = 1, high = 50;
    
    if(n == 0 || n == 1) return "IsFibo";
    
    // Binary Search
    while(low <= high) {
        
        long mid = low + (high-low)/2;
        vector<long> res = fib(mid);
        
        // cout << mid << " " << res[0] << endl;
        if(res[0] == n) return "IsFibo";
        else if(res[0] > n) {
            high = mid-1;
        }
        else low = mid+1;
    }
    
    return "IsNotFibo";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}