// https://practice.geeksforgeeks.org/problems/find-the-closest-prime-number-to-a-given-number/0

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& nums, int k, int start, int end)
{
    if(start > end) return -1;
    
    if(end == start+1) {
        if(abs(k-nums[start]) <= abs(k-nums[end])) {
            return nums[start];
        }
        return nums[end];
    } 
    
    int mid = start + (end - start)/2;
    if(nums[mid] < k) {
        return binarySearch(nums, k, mid, end);
    }
    return binarySearch(nums, k, start, mid);
}

int main(int argc, char* argv[])
{
    vector<bool>prime(1000007, true);
    
    prime[0] = false;
    prime[1] = false;
    
    vector<int>nums;
    
    for(int i = 2; i <= 1000006; i++) {
        if(prime[i]) {
            nums.push_back(i);
            for(int j = i+i; j <= 1000006; j+=i) {
                prime[j] = false;
            }
        }
    }
    
    int t;
    int n;
    
    cin >> t;
    while(t--) {
        cin >> n;
        
        if(prime[n] == true) {
            cout << n << endl;
            continue;
        }
        cout << binarySearch(nums, n, 0, nums.size()-1) << endl;
    }

    return 0;
}
