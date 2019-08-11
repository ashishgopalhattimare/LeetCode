// https://practice.geeksforgeeks.org/problems/knight-walk/0/?ref=self
// Medium
// BFS

#include <bits/stdc++.h> 

using namespace std;

int X[8] = {1,2,2,1,-1,-2,-2,-1};
int Y[8] = {-2,-1,1,2,2,1,-1,-2};

bool inrange(int x, int limit) {
    return x >= 1 && x <= limit;
}


int algorithm(int n, int m, int x1, int y1, int x2, int y2)
{
    // make all unvisited
    vector<vector<bool>>matrix(n+1, vector<bool>(m+1, 0));

    list<vector<int>>ll;
    vector<int>curr;
    
    ll.push_back({x1,y1,0});
    matrix[x1][y1] = true;
    
    int result = -1;
    
    while(!ll.empty()) {
        
        curr = ll.front();
        ll.pop_front();
        
        
        if(curr[0] == x2 && curr[1] == y2) {
            result = curr[2];
            break;
        }
        
        for(int k = 0; k < 8; k++) {
            x1 = curr[0] + X[k];
            y1 = curr[1] + Y[k];
            if(inrange(x1, n) && inrange(y1, m) && !matrix[x1][y1]) {
                ll.push_back({x1,y1,curr[2]+1});
                matrix[x1][y1] = true;
            }
        }
    }
    
    while(!ll.empty()) ll.pop_back();
    
    return result;
}

int main(int argc, char* argv[])
{
    int t;
    int n, m;
    int x1, y1, x2, y2;
    
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << algorithm(n, m, x1, y1, x2, y2) << endl;
    }

    return 0;
}
