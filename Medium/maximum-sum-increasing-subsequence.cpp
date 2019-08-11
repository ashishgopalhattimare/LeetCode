#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char* argv[])
{
    int t;
    int n;
    
    cin >> t;
    while(t--) {
        cin >> n;
        
        vector<int> longest(n, 0);
        vector<int> nums(n);
        int maxim = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            
            longest[i] = nums[i];
            maxim = max(maxim, longest[i]);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                
                if(nums[i] < nums[j]) {
                    longest[j] = max(longest[j], longest[i] + nums[j]);
                
                    maxim = max(maxim, longest[j]);
                }
            }
        }
        cout << maxim << endl;
    }

    return 0;
}