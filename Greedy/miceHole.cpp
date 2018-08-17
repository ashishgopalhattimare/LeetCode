#include <bits/stdc++.h> 
#include <unordered_map> 
#include <map>
#include <iostream> 
#include <vector> 
#include <algorithm>
#include <cstdlib> 
#include <cstdio> 
#include <string>
#include <stack> 
#include <deque> 
#include <queue>
#include <cctype> 
#include <cmath> 

// https://practice.geeksforgeeks.org/problems/assign-mice-holes/0

using namespace std;

int main(int argc, char* argv[])
{
    int t;
    int n;
    int maxDis;
    
    cin >> t;
    while(t--) {
        cin >> n;
        
        int *A = new int[n];
        int *B = new int[n];
        
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> B[i];
        }
        
        sort(A, A+n);
        sort(B, B+n);
        
        maxDis = abs(B[0]-A[0]);
        for(int i = 1; i < n; i++) {
            if(maxDis < abs(B[i]-A[i])) {
                maxDis = abs(B[i]-A[i]);
            }
        }
        
        cout << maxDis << endl;
    }

    return 0;
}