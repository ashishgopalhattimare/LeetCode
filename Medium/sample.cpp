#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int>nums, int x)
{
    int low = 0, high = 0;
    int maxLen = 0;
    double sum = 0;

    for(int i = 0; i < nums.size(); i++) {
        sum = 0;
        for(int j = i; j < nums.size(); j++) {
            sum += nums[j];
            
            if(sum/(j-i+1) >= x) {
                if(maxLen < (j-i+1)) {
                    maxLen = (j-i+1);
                    low = i; high = j;
                }
            }
        }
    }

    return {low, high};
}

void print(vector<int> nums)
{
    for(int x : nums) cout << x << " ";
    printf("\n");
}

int main()
{
    print(solution({2,-3,3,2,1}, 3));

    return 0;
}