#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    int n, p;
    
    cin >> t;
    while(t--) {
        cin >> n >> p;

        if(p >= n) {
            p = n;
        }
        
        vector<int>milk(n);
        vector<int>apple(n);
        
        for(int i = 0; i < n; i++) {
            cin >> milk[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> apple[i];
        }
        
        static int dp[1001][1001];
        
        dp[0][n-1] = 0;
        
        for(int i = 1; i <= n; i++) {
            dp[i][n-1] = apple[n-1];
        }
        
        for(int i = n-2; i >= 0; i--) {
            dp[0][i] = 0;
            for(int j = 1; j <= n; j++) {
                int temp = j + milk[i] - 1;
                if(temp >= n) {
                    temp = n;
                }
                dp[j][i] = max(apple[i] + dp[j-1][i+1], dp[temp][i+1]);
            }
        }
        
        cout << dp[p][0] << endl;
    }
    return 0;
}