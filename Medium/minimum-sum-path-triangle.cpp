// https://www.geeksforgeeks.org/minimum-sum-path-triangle/
#include <bits/stdc++.h>

using namespace std;

int algorithm(vector<vector<int>>& input)
{
    int ROW = input.size();
    list<vector<int>>ll; // sum, i, j
    vector<int>curr;

    for(int j = 0; j < input[ROW-1].size(); j++) {
        ll.push_back({input[ROW-1][j], ROW-1, j});
    }

    int minSum = INT_MAX;
    int r, c, v;
    
    while(!ll.empty()) {
        curr = ll.front();
        ll.pop_front();

        v = curr[0]; r = curr[1];
        c = curr[2];

        if(r == 0) { // head element
            minSum = min(minSum, v);
        }
        else {
            if(c == 0) { // first element of the level
                ll.push_back({v+input[r-1][0], r-1, c});
            }
            else if(c == input[r].size()-1) {// last element of the level
                ll.push_back({v+input[r-1][input[r-1].size()-1], r-1, (int)(input[r-1].size()-1)});
            }
            else { // mid elements
                ll.push_back({v+input[r-1][c-1], r-1, c-1});
                ll.push_back({v+input[r-1][c], r-1, c});
            }
        }
    }

    return minSum;
}

int main()
{
    vector<vector<int>> input = {{3}, 
                                 {6,4},
                                 {5,2,7},
                                 {9,1,8,6}};

    cout << algorithm(input) << endl;

    return 0;
}