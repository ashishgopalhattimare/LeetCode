// https://leetcode.com/problems/reduce-array-size-to-the-half/
// Medium

class Solution {
public:
    int minSetSize(vector<int>& nums) {
        
        unordered_map<int,int>mapi;
        for(int x : nums) mapi[x]++;
        
        vector<int>arr(mapi.size());
        int i = 0;
        for(auto itr = mapi.begin(); itr != mapi.end(); itr++) {
            arr[i] = itr->second;
            i++;
        }
        
        sort(arr.begin(), arr.end()); // sort the frequency in ascending order
        
        int size = 0;
        for(int j = arr.size()-1, k = 0; j >= 0; j--) {
            size += arr[j];
            k++;
            if((nums.size()-size) <= nums.size()/2)
                return k;
        }
        return 0;
    }
};