// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Medium

class Solution {
private:
    int minDiff = INT_MAX;
    int result = -1;

public:
    Solution() {}

    // We can use prefix sum and do binary Search to find this {sum, index} pair
    // in O(n) for prefix computation and
    // O(logn) for findIndex()
    pair<int,int> findIndex(vector<int>& arr, int x) {
        
        int sum = 0, index = 0;

        for( ; index < arr.size(); index++) {
            if(arr[index] <= x) sum += arr[index];
            else break;
        }

        return {sum, index};
    }

    void binary_search(int low, int high, vector<int>& arr, int target, bool cont)
    {
        int mid = low + (high-low)/2;

        pair<int,int> x = findIndex(arr, mid);

        int Y = x.first + mid * (arr.size()-x.second);
        
        if(minDiff > abs(Y-target)) {
            minDiff = abs(Y-target);
            result = mid;
        }
        else if(minDiff == abs(Y-target)) {
            result = min(result, mid);
        }

        if(cont == false) return;

        if(low == high || low == high-1) {
            binary_search(high, high, arr, target, false);
        }
        else {
            if(Y-target < 0) {
                binary_search(mid, high, arr, target, true);
            }
            else binary_search(low, mid, arr, target, true);
        }
    }

    int findBestValue(vector<int>& arr, int target) {
        
        sort(arr.begin(), arr.end());

        int low = 0, high = INT_MIN;
        for(int x : arr) high = max(high, x);

        binary_search(low, high, arr, target, true);
        
        return result;
    }
};