#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<int>arr;
    
    Node(int value) : val(value) {}
};

void bfs(int source, vector<Node*>& vertices, vector<vector<int>>& sortMatrix, int currLevel) {
    
    sortMatrix[currLevel].push_back(vertices[source]->val);
    
    for(int i = 0; i < vertices[source]->arr.size(); i++) {
        bfs(vertices[source]->arr[i], vertices, sortMatrix, currLevel+1);
    }
    
    return;
}

void dfs(int source, vector<Node*>& vertices, int *maxLevel, int level) {
    
    *maxLevel = max(*maxLevel, level);
    
    for(int i = 0; i < vertices[source]->arr.size(); i++) {
        dfs(vertices[source]->arr[i], vertices, maxLevel, level+1);
    }
    return;
}

vector<int> GreaterEqual (vector<int> A, vector<int> X, vector<int> u, vector<int> L, vector<int> v) {
    // Write your code here
    
    vector<int>point(A.size()+1);
   
    vector<Node*>vertices(A.size()+1);
    for(int i = 0; i < A.size(); i++) {
        vertices[i+1] = new Node(A[i]);
        point[i+1] = A[i];
    }
    
    for(int i = 1; i < u.size(); i++) {
        vertices[u[i]]->arr.push_back(v[i]); // u->v;
    }
   
    int maxLevel = 0;
    dfs(1, vertices, &maxLevel, 0);
    
    vector<vector<int>>sortLevel(maxLevel+1);
   
    bfs(1, vertices, sortLevel, 0);
    
    int lvel = 0;
    for(vector<int> x : sortLevel) {
        sort(x.begin(), x.end());
    
        // printf("\nlevel %d : ", lvel++);
        // for(int i : x) printf("%d ", i);
    }
    
   
    int l, x;
    vector<int> result(L.size(), -1);
    for(int i = 0; i < L.size(); i++) {
        l = L[i] % (maxLevel+1);
        x = X[i];
        
        for(int xx : sortLevel[l]) {
            if(xx >= x) {
                result[i] = xx;
                break;
            }
        }
    }
    
    return result;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }
    vector<int> u(N), v(N);
    for(int i_u=1; i_u<N; i_u++)
    {
    	cin >> u[i_u] >> v[i_u];
    }
    vector<int> L(Q), X(Q);
    for(int i_L=0; i_L<Q; i_L++)
    {
    	cin >> L[i_L] >> X[i_L];
    }
    vector<int> out_;
    out_ = GreaterEqual(A, X, u, L, v);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << "\n" << out_[i_out_];
    }
}
