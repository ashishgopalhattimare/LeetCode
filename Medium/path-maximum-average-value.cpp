// https://www.geeksforgeeks.org/path-maximum-average-value/

#include <bits/stdc++.h>

using namespace std;

struct Data {
    long long sum;
    int i, j, n;
};

bool inrange(int x, int l) {
    return x < l;
}

double algorithm(vector<vector<int>>& input)
{
    int N = input.size();
    list<Data>ll;
    Data curr;

    ll.push_back({input[0][0], 0, 0, 1});

    long long maxSum = INT_MIN, n;

    while(!ll.empty()) {
        curr = ll.front();
        ll.pop_front();

        // bottom right element
        if(curr.i == N-1 && curr.j == N-1) {
            if(maxSum == INT_MIN || maxSum * curr.n < curr.sum * n) {
                maxSum = curr.sum;
                n = curr.n;
            }
        }
        else {
            // Down
            if(inrange(curr.i+1, N)) {
                ll.push_back({curr.sum + input[curr.i+1][curr.j], curr.i+1, curr.j, curr.n+1});
            }
            // Right
            if(inrange(curr.j+1, N)) {
                ll.push_back({curr.sum + input[curr.i][curr.j+1], curr.i, curr.j+1, curr.n+1});
            }
        }
    }

    return maxSum / static_cast<double>(n);
}

int main()
{
    vector<vector<int>> input = {{1,2,3},
                                 {4,5,6},
                                 {7,8,9}};

    cout << algorithm(input) << endl;

    return 0;
}