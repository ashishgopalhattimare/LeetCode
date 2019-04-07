// https://practice.geeksforgeeks.org/problems/next-smallest-palindrome/0

#include <bits/stdc++.h> 

using namespace std;

bool simpleIncrement(int mid1, int mid2, vector<int>& nums)
{
    for(int i = mid1, j = mid2; i >= 0 && j < nums.size(); i--, j++) {
        // 9 5 1 8 7 9 7 8 1 2 2
        if(nums[i] > nums[j]) {
            return true;
        }
        // 9 4 1 8 7 9 7 8 3 2 2
        else if(nums[i] < nums[j]) {
            return false;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    int t, n;
    
    cin >> t;
    while(t--) {
        
        cin >> n;
        vector<int>nums(n);
        
        bool allNine = true;
        
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            
            if(nums[i] != 9) allNine = false;
        }
        
        int mid1, mid2;
        
        if(n % 2 == 1) {
            mid1 = mid2 = n/2;
        }
        else {
            mid1 = n/2-1;
            mid2 = mid1 + 1;
        }
        
        bool carry = false;
        if(!simpleIncrement(mid1, mid2, nums)) {
            carry = true;
            for(int i = mid1; i >= 0; i--) {
                nums[i] = nums[i] + carry;
                    
                carry = nums[i]/10;
                nums[i]%=10;
            }
        }
        for(int i = mid1, j = mid2; i >= 0 && j < nums.size(); i--, j++) {
            nums[j] = nums[i];
        }
        
        if(carry) printf("1 ");
        
        // 9 9 9 9 -> 1 0 0 0 1
        for(int i = 0; i < nums.size() - allNine; i++) {
            printf("%d ", nums[i]);
        }
        if(carry) printf("1");
        
        printf("\n");
    }

    return 0;
}
