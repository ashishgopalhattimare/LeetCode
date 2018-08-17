#include <bits/stdc++.h>

using namespace std;

struct Node {
    int deadline, profit;
};
    
bool comparator(Node &A, Node &B)
{
    return A.profit > B.profit;
}

int main(int argc, char* argv[])
{
    int t;
    int n;
    int id, deadline, profit;
    
    cin >> t;
    while(t--) {
        cin >> n;
        
        Node *A = new Node[n];
        for(int i = 0; i < n; i++) {
            cin >> id >>  deadline >> profit;
            
            A[id-1].deadline = deadline;
            A[id-1].profit = profit;
        }
        
        sort(A, A+n, comparator);
        
        for(int i = 0; i < n; i++) {
            printf("%d %d\n", A[i].deadline, A[i].profit);
        }
        printf("\n");
    }
    
    
    

    return 0;
}