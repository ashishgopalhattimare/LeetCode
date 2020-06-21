// https://codeforces.com/contest/1337/problem/C
// Depth Analysis, Tree Traversal

#include <bits/stdc++.h>
using namespace std;
 
#define LLI long long int
#define SUBTREE 1
#define DEPTH 2
 
struct City
{
    LLI id, depth;
    LLI subtree;
 
    vector<int>edges;
    City(int id) : id(id) {
        depth = 0;
        subtree = 0;
    }
};
 
void levelOrder(int prev, int src, vector<City*>& cities, int level, vector<vector<LLI>>& arr, int& ind, int& maxl)
{
    arr[ind++] = {src, cities[src]->subtree, level};
    cities[src]->depth = level;
 
    maxl = max(maxl, level);
 
    for(int child : cities[src]->edges) {
        if(child != prev) {
            levelOrder(src, child, cities, level+1, arr, ind, maxl);
        }
    }
}
 
LLI preorder(int prev, int src, vector<City*>& cities)
{
    LLI count = 0;
    for(int child : cities[src]->edges) {
        if(child != prev) {
            count += preorder(src, child, cities);
        }
    }
    cities[src]->subtree = count;
    return count + 1;
}
 
int main()
{
    int n, k;
    int u, v;
 
    cin >> n >> k;
 
    vector<City*>cities(n+1);
    for(int i = 1; i <= n; i++) {
        cities[i] = new City(i);
    }
 
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
 
        cities[u]->edges.push_back(v);
        cities[v]->edges.push_back(u);
    }
 
    preorder(-1, 1, cities);
 
    vector<vector<LLI>>arr(n);
    
    int index = 0, maxLevel = 0;
    levelOrder(-1, 1, cities, 0, arr, index, maxLevel);
 
    // index, total childs in the subtree
    sort(arr.begin(), arr.end(), [](vector<LLI>& a, vector<LLI>& b) {
        
        return (a[DEPTH] - a[SUBTREE]) > (b[DEPTH] - b[SUBTREE]);
    });
 
    LLI totalHappiness = 0;
    for(int i = 0; i < k; i++) {
        totalHappiness += (arr[i][DEPTH] - arr[i][SUBTREE]);
    }
    cout << totalHappiness << endl;
 
    return 0;
}