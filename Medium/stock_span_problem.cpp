// https://practice.geeksforgeeks.org/problems/stock-span-problem/0

#include <bits/stdc++.h> 

using namespace std;

// complexity - O(n^2)
vector<int> stockSpanI(vector<int>& nums)
{
    vector<int>result(nums.size(), 1);
    
    int currentHeight;
    bool change;
    for(int i = 1; i != nums.size(); i++) {
        // currentHeight = nums[i];
        // change = false;
        for(int j = i-1; j >= 0; j--) {
            if(nums[j] <= nums[i]) { // price is smaller just before the current day
                result[i]++;
            }
            else break;
        }
    }
    
    return result;
}

// complexity - O(n), space O(2n)
vector<int> stockSpan(vector<int>& nums)
{
    vector<int>result(nums.size(), 1);
    
    stack<pair<int,int>>st;
    
    int count;
    for(int i = 0; i < nums.size(); i++) {
        
        count = 1;
        while(!st.empty() && st.top().first <= nums[i]) {
            
            count += st.top().second;
            st.pop();
        }
        st.push(make_pair(nums[i], count));
    
        result[i] = count;
    }
    
    return result;
}

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
        
        vector<int>result = stockSpan(nums);
        
        for(int x : result) {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}
