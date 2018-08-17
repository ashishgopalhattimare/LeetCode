// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    
    bool binarySearch(vector<int>& nums, int start, int end, int num, int diff)
    {
        if(start > end) return false;
        
        if(end == start + 1) {
            if(abs(nums[start] - num) == diff) {
                return true;
            }
            if(abs(nums[end] - num) == diff) {
                return true;
            }
            
            return false;
        }
        else if(end == start) {
            if(abs(nums[start] - num) == diff) {
                return true;
            }
            return false;
        }
        
        int mid = start + (end - start)/2;
        int tempDiff = abs(nums[mid] - num);
        if(tempDiff == diff) {
            return true;
        }
        
        if(diff < tempDiff) {
            return binarySearch(nums, start, mid, num, diff);
        }
        return binarySearch(nums, mid, end, num, diff);
    }
    
    int findPairs(vector<int>& nums, int k) {
        
        vector<int>v;
        unordered_map<int, int>hash;
        
        for(int i = 0; i < nums.size(); i++) {
            if(hash.find(nums[i]) == hash.end()) {
                v.push_back(nums[i]);
                hash[nums[i]] = 1;
            }
            else {
                hash[nums[i]]+=1;
            }
        }
        
        int count = 0;
        
        if(nums.size() < 2) return 0;
        if(k == 0) {
            for(auto itr = hash.begin(); itr != hash.end(); itr++) {
                if(itr->second > 1) count++;
            }
            return count;
        }
        
        sort(v.begin(), v.end());
        
        for(int i = 0; i < v.size()-1; i++) {
            if(binarySearch(v, i+1, v.size()-1, v[i], k)) {
                count++;
            }
        }
        
        return count;
    }
};

// 3 1 4 1 5
// 3 1 4 5
// 1 3 4 5
// 1-3 3-5
