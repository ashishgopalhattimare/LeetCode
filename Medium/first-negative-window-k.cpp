#include <bits/stdc++.h>
using namespace std;

void algorithm(vector<int>& nums, int k) {
    
    list<int>ll;

    for(int i = 0; i < k && i < nums.size(); i++) {
        if(nums[i] < 0) {
            while(!ll.empty() && nums[ll.back()] >= nums[i]) {
                ll.pop_back();
            }
            ll.push_back(i);
        }
    }
    printf("%d ", (ll.size() == 0) ? 0 : nums[ll.front()]);

    int start = 0;
    for(int i = k; i < nums.size(); i++) {
        while(!ll.empty() && ll.front() <= start) {
            ll.pop_front();
        }

        if(nums[i] < 0) {
            while(!ll.empty() && nums[ll.back()] >= nums[i]) {
                ll.pop_back();
            }
            ll.push_back(i);
        }

        printf("%d ", (ll.size() == 0) ? 0 : nums[ll.front()]);
    }
    
    printf("\n");
}

int main()
{
    vector<int>nums = {1,3,2,2,4,-2,4,-6,3};

    // Most Negative number in the array
    algorithm(nums, 3);
    return 0;
}