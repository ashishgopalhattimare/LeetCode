#include <bits/stdc++.h> 

using namespace std;

void rotateArray(vector<char>& arr, int k)
{
    char temp;
    for(int i = 0; i < k; i++) {
        temp = arr[arr.size()-1];
        
        for(int i = arr.size()-2; i >= 0; i--) {
            arr[i+1] = arr[i];
        }
        arr[0] = temp;
    }
    return;
}

int main(int argc, char* argv[])
{
    int t;
    int n, q, x, k, totalRotate;
    
    bool rotateQuery;
    
    string str;
    
    cin >> t;
    while(t--) {
        cin >> n >> q;
        
        cin >> str;
        
        vector<char>arr;
        for(int i = 0; i < n; i++) {
            arr.push_back(str[i]);
        }
        
        totalRotate = 0;
        
        while(q--) {
            cin >> x >> k;
            
            if(x == 1) {
                totalRotate = (totalRotate + k) % n;
            }
            else {
                // find the k index with respect to the totalRotation which changes the starting index --> greedy algorithm
                printf("%c\n", arr[ ((n - totalRotate)%n + (k % n)) % n]);
            }
        }
    }

    return 0;
}