// Given a two numbers n and k. Can ‘n’ be broken down
// using ‘k’ powers of 2 ? If yes, return a possible set.

#include <bits/stdc++.h>

using namespace std;

bool combinatorics(int n, int level, int k, vector<int>& result)
{
    if(n == 0 && level == k) {
        for(int x : result) printf("%d ", x);
        printf("\n");

        return true;
    }
    else if(level > k || n == 0) return false;

    int maxPower = floor(log(n)/log(2));
    int value;
    for(int i = maxPower; i >= 0; i--) {
        
        value = static_cast<int>(pow(2,i));
        result.push_back(value);
        if(combinatorics(n-value, level+1, k, result)) {
            return true;
        }
        result.pop_back();
    }

    return false;
}

bool algorithm(int n, int k)
{
    vector<int>result;
    
    return combinatorics(n, 0, k, result);
}

int main()
{
    int n = 4, k = 3;

    cout << algorithm(n, k) << endl;
}