// https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/
// Kadane Variation

#include <bits/stdc++.h>

using namespace std;

int algorithm(vector<int>& input)
{
    int sum = 0, smallestSum = INT_MAX;
    for(int x : input) {
        sum += x;

        smallestSum = min(smallestSum, sum);
        if(sum > 0) sum = 0;
    }

    return smallestSum;
}

int main()
{
    vector<int> input = {3, -4, 2, -3, -1, 7, -5};
    
    cout << algorithm(input) << endl;

    return 0;
}