
// https://www.geeksforgeeks.org/maximum-sum-2-x-n-grid-no-two-elements-adjacent/
// Variation of House Robber 1, 2, 3

#include <bits/stdc++.h>

using namespace std;

static unordered_map<int,int>mapi;
int algorithm(vector<vector<int>>& input, int index)
{
    if(index >= input[0].size()) return 0;

    if(mapi.find(index) != mapi.end()) {
        return mapi[index];
    }

    int sum = max(input[0][index], input[1][index]);

    sum += algorithm(input, index + 2);

    mapi[index] = max(sum, algorithm(input, index+1));

    return mapi[index];
}

int main()
{
    vector<vector<int>> input1 = {{1,2,3,4,5},
                                 {6,7,8,9,10}};

    vector<vector<int>> input2 = {{1,4,5},
                                 {2,0,0}};

    cout << algorithm(input1, 0) << endl;
    // cout << algorithm(input2, 0) << endl;
    return 0;
}