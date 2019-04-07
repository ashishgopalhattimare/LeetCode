// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0

#include <bits/stdc++.h> 

using namespace std;

void recursive(int i, int j, int l, int r, int k, vector<int>& nums, vector<vector<int>>& result)
{
	if(l >= r) return;

	int sum = nums[i] + nums[j] + nums[l] + nums[r];
	
	if(sum == k) {
		vector<int>arr{nums[i], nums[j], nums[l], nums[r]};

		if(find(result.begin(), result.end(), arr) == result.end()) {
			result.push_back(arr);
		}

		recursive(i, j, l+1, r, k, nums, result);
		recursive(i, j, l, r-1, k, nums, result);
	}
	else if(sum > k) {
		recursive(i, j, l, r-1, k, nums, result);
	}
	else {
	    recursive(i, j, l+1, r, k, nums, result);
	}

	return;
}

int main(int argc, char* argv[])
{
    int t, n, k;
    int sum;
    
    cin >> t;
    while(t--) {
        cin >> n >> k;
        
        vector<int>nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        bool found = false;
        
        int l, r;

        vector<vector<int>>result;

        for(int i = 0; i < nums.size(); i++) {
            
            for(int j = i+1; j < nums.size(); j++) {
                
                l = j+1; r = nums.size()-1;
                
                recursive(i, j, l, r, k, nums, result);
            }
        }
        
        if(result.size()) {
            for(int i = 0; i < result.size(); i++) {
                printf("%d %d %d %d $", result[i][0], result[i][1], result[i][2], result[i][3]);
            }
        }
        else printf("-1");
        printf("\n");
    }

    return 0;
}
