// https://practice.geeksforgeeks.org/problems/palindromic-array/0

#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char* argv[])
{
    int t, n;
    
    cin >> t;
    while(t--) {
        cin >> n;
        
        vector<int>nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        int turns = 0;
        
        int l = 0, r = n-1;
        while(l < r) {
            if(nums[l] < nums[r]) {
                nums[l+1] = nums[l+1] + nums[l];
                turns++;
                l++;
            }
            else if(nums[l] > nums[r]) {
                nums[r-1] = nums[r-1] + nums[r];
                turns++;
                r--;
            }
            else {
                r--;
                l++;
            }
        }
        
        cout << turns << endl;
    }

    return 0;
}
