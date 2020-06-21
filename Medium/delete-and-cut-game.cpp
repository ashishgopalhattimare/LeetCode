// https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/delete-and-cut-game-91969de1/
// Set 3
// March Circuit '20

/**
Algorithm and Technique:

Use Time to Detect the Circular Loop in undirected Graph

**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define X 1000000005
#define Y 1000000007

struct TreeNode {
    LL val; // Node value
    LL counter; // bruteForce usage only

    // No need to use sets, since we are traversing all the child nodes
    set<int>edge; // Can use vector<int>
 
    int time; // time of visit
 
    TreeNode(int val) : val(val) {
        counter = -1;   // initial counter is -1 as unique id
        time = INT_MAX; // initial time is INFINITY
    }
};
 
void countVertex(int source, unordered_map<int, TreeNode*>& mapi, LL &visitCount, LL k)
{
    visitCount = visitCount + 1;
    mapi[source]->counter = k;
 
    for(auto itr = mapi[source]->edge.begin(); itr != mapi[source]->edge.end(); itr++) {
        if(mapi[*itr]->counter != k) {
            countVertex(*itr, mapi, visitCount, k);
        }
    }
}

// Power Exponentiation using modulo (GeeksForGeeks)
LL modulo(LL a, LL b, LL n){
    LL x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

// Brute Force to check the output
vector<LL> bruteForce(int N, int M, vector<vector<int>>& edgeArr, unordered_map<int, TreeNode*>& mapi)
{
    LL uu, vv, visitCount = 0;
    LL counter = 1;
 
    int u, v;
 
    LL A = 0, B = 0;

    // Remove each edgde at a time
    // to Count the nodes in each component
    for(int i = 0; i < edgeArr.size(); i++) {
 
        u = edgeArr[i][0]; v = edgeArr[i][1];

        // Remove the edge from the undirected graph
        mapi[u]->edge.erase(v); mapi[v]->edge.erase(u); 

        // Nodes can be visited from the U node
        visitCount = 0; countVertex(u, mapi, visitCount, ++counter);
        uu = visitCount;

        // Nodes can be visited from the V node
        visitCount = 0; countVertex(v, mapi, visitCount, ++counter);
        vv = visitCount;
        
        // Append the Edge into the undirected graph
        mapi[u]->edge.insert(v); mapi[v]->edge.insert(u);
 
        if(uu == N || vv == N) continue; // edge was a part of Circular Loop

        // Two Components generated, decide which player wins
        if(uu % 2 == 0 && v % 2 == 0) {
            A++;
        }
        else B++;
    }

    // One of the player is 0.. then the other has to be 1 or 0 only
    if(A == 0 || B == 0) {
        // Both are 0
        if(A == 0 && B == 0) return {0, 0};
        else {
            // Only is certainly zero, the other is 1
            return {A/(A+B), B/(A+B)};
        }
    }

    // printf("< %lld %lld >\n", A, B);
    
    // Make the two numbers co-prime by dividing each by their gcd
    LL gcd = __gcd(A, B);
    A /= gcd; B /= gcd;
 
    return {A*modulo(A+B, X, Y), B*modulo(A+B, X, Y)};
}
 
vector<int> postOrder(int source, unordered_map<int, TreeNode*>& mapi, int root, long long int& A, long long int& B, int N, int time)
{
    // printf("source : %d\n", source);

    mapi[source]->time = time; // update my time
    int next;
 
    int loopDistance = 0, count = 0;
    for(auto itr = mapi[source]->edge.begin(); itr != mapi[source]->edge.end(); itr++) {

        next = *itr; // index of child node
    
        // If parent node
        if(mapi[next]->time == time - 1) continue;
 
        // If the child is not visited before
        if(mapi[next]->time == INT_MAX) {
            vector<int> temp = postOrder(next, mapi, root, A, B, N, time+1);
            loopDistance = max(loopDistance, temp[1]-1);

            count += temp[0];
        }
        
        // Not parent, but previously encountered node, generates a Circular Loop
        // Consider the maximum loopDistance so far
        // [myTime - childTime] = backtracks required to be out of circular loop
        else {
            loopDistance = max(loopDistance, time - mapi[next]->time);
        }
    }
 
    // printf("source : %d, loopDistance : %d\n", source, loopDistance);

    // If the LoopDistance is not 0, then that means the node is path so far
    // is under a circular loop, and not using this edge
    // would not separate the graph into 2 components

    // If loopDistance == 0 : This node is not a part of Circular Loop
    // If loopDistance != 0 : This node is a part of Circular Loop
    if(loopDistance == 0)
    {
        int left = count + 1; // Left Component
        int right = N - left; // Right Component
 
        if(left != N && right != N) { // If No component is a complete Graph
 
            // printf("[source : %d] >> left : %d, right : %d, N : %d\n", source, left, right, N);
            
            // Increment Player's Win
            if(left % 2 == 0 && right % 2 == 0) {
                A++;
            }
            else B++;
        }
    }

    // count + 1    : number of nodes, traversed so far
    // loopDistance : How backtrack I would need to do to next the circular loop
    return {count + 1, loopDistance};
}
 
vector<LL> optimal(unordered_map<int, TreeNode*>& mapi, int N)
{
    auto itr = mapi.begin();
 
    int root = itr->first;
 
    LL AA = 0, BB = 0;
    postOrder(root, mapi, root, AA, BB, N, 1);
 
    LL A = AA, B = BB;

    // One of the player is 0.. then the other has to be 1 or 0 only
    if(A == 0 || B == 0) {
        // Both are 0
        if(A == 0 && B == 0) return {0, 0};
        else {
            // Only is certainly zero, the other is 1
            return {A/(A+B), B/(A+B)};
        }
    }
    
    // printf("< %lld %lld >\n", A, B);
    
    // Make the two numbers co-prime by dividing each by their gcd
    LL gcd = __gcd(A, B);
    A /= gcd; B /= gcd; // Make A and B co-prime to each other

    return {A*modulo(A+B, X, Y), B*modulo(A+B, X, Y)};
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    ifstream infile; infile.open("input.txt");
    
    unordered_map<int, TreeNode*> mapi;
    
    int N, M;
    int u, v;
 
    cin >> N >> M;
 
    vector<vector<int>> edgeArr(M);
    for(int i = 0; i < M; ++i)
    {
        cin >> u >> v;
 
        if(u == v) continue;
 
        edgeArr[i] = {u, v}; // store the edge
 
        if(mapi.find(u) == mapi.end()) mapi[u] = new TreeNode(u);
        if(mapi.find(v) == mapi.end()) mapi[v] = new TreeNode(v);
 
        mapi[u]->edge.insert(v);
        mapi[v]->edge.insert(u);
    }

    vector<LL> x = optimal(mapi, N);

    for(LL i : x) printf("%lld ", i % Y); printf("\n"); // MOD again to keep the value in MOD range

    return 0;
}