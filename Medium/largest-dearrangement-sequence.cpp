#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;

    bool operator<(const Node& other) const {
        return data < other.data;
    }
};

vector<int> algorithm(vector<int>& seq)
{
    vector<int>result(seq.size(), INT_MIN);

    priority_queue<Node>pq;
    Node curr;

    int n = seq.size();
    for(int i = 0; i < n; i++) {
        pq.push({seq[i]});
    }

    for(int i = 0; i < n; i++) {
        curr = pq.top();
        pq.pop();

        if(curr.data != seq[i] || i == n-1) {
            result[i] = curr.data;
        }
        else {
            result[i] = pq.top().data;
            pq.pop();
            pq.push({curr.data});
        }
    }

    // Swap the last element with the previous
    // one if the order has not changed
    if(result[n-1] == seq[n-1]) {
        result[n-1] = result[n-2];
        result[n-2] = seq[n-1];
    }

    return result;
}

int main()
{
    vector<int> seq = {92, 3, 52, 13, 2, 31, 1};

    for(int x : algorithm(seq)) {
        cout << x << " ";
    }
    printf("\n");

    return 0;
}