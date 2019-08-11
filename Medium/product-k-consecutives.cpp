#include <bits/stdc++.h>

using namespace std;

int min(int x, int y) { return x < y ? x : y; }

vector<int> bruteForce(vector<int>& nums, int k) {
    vector<int>result(nums.size());
    int product = 1;
    for(int i = 0; i < k && i < nums.size(); i++) {
        product *= nums[i];
        result[i] = product;
    }
    for(int i = k; i < nums.size(); i++) {
        product = 1;
        for(int j = i-k+1; j <= i; j++) {
            product *= nums[j];
        }
        result[i] = product;
    }

    return result;
}

vector<int> optimal(vector<int>& nums, int k) {
    vector<bool>zeroProduct(nums.size(), false);

    // Setup
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) { // make next k zeroProduct set to true
            for(int j = min(nums.size()-1, i+k-1); j >= i; j--) {
                if(zeroProduct[j] == true) break;
                zeroProduct[j] = true;
            }
        }
    }

    vector<int>result(nums.size(), 0);

    int product = 1;
    int start = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i]) product *= nums[i];

        if(i-start == k) { // remove start element if out of bound
            if(nums[start]) product /= nums[start]; // only if element is non-zero
            start++;
        }

        if(!zeroProduct[i]) result[i] = product; // if the result supposed to return in zero
    }

    return result;
}

int main() {

    vector<int>nums = {1, 3, 3, 6, 5, 7, 0, -3]};
    int k = 3;

    for(int x : bruteForce(nums, k)) {
        printf("%d ", x);
    }
    printf("\n");

    for(int x : optimal(nums, k)) {
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}