// https://www.geeksforgeeks.org/maximum-weight-path-ending-element-last-row-matrix/
// Easy

#include <bits/stdc++.h>

using namespace std;

int algorithm(vector<vector<int>>& input)
{
    int maxSum = 0, COL = input[0].size(), ROW = input.size();

    list<vector<int>>ll;
    vector<int>curr;

    ll.push_back({input[0][0], 0, 0}); // sum, i, j

    while(!ll.empty()) {

        curr = ll.front();
        ll.pop_front();

        if(curr[1] == ROW-1) { // last row
            maxSum = max(maxSum, curr[0]);
        }
        else { // not in the last row

            // Diagonal (i+1, j+1)
            if(curr[2] + 1 < COL) {
                ll.push_back({curr[0]+input[curr[1]+1][curr[2]+1], curr[1]+1, curr[2]+1});
            }

            // Down (i+1, j)
            ll.push_back({curr[0]+input[curr[1]+1][curr[2]], curr[1]+1, curr[2]});
        }
    }

    return maxSum;
}

int main()
{
    vector<vector<int>>input = {{4,2,3,4,1},
                                {2,9,1,10,5},
                                {15,1,3,0,20},
                                {16,92,41,44,1},
                                {8,142,6,4,8}};

    cout << algorithm(input) << endl;

    return 0;
}