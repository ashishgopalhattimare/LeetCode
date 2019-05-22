// https://www.geeksforgeeks.org/make-all-numbers-of-an-array-equal/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b); 
}

int findlcm(std::vector<int>& arr) {
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        ans = (arr[i] * ans) / (gcd(arr[i], ans);
    }
    return ans; 
} 

bool algorithm(std::vector<int>& nums, int lcm) {
    int temp;
    for(int i = 0; i < nums.size(); i++) {
        temp = lcm / nums[i];
        
        while(temp%2 == 0) temp/=2;
        while(temp%3 == 0) temp/=3;
        if(temp != 1) return false;
    }
    return true;
}

int main()
{
    std::vector<int> nums {10, 14};
    
    if(algorithm(nums, findlcm(nums))) cout << "Yes" << endl; 
    else cout << "No" << endl;
    
    
    return 0;
}
