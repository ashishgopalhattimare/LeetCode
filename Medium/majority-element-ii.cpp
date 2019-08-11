class Solution {
public:
    
    long long int getValue(vector<int>& nums, int n, long long int exclude)
    {
        long long int e1 = LONG_MIN, e2 = LONG_MIN;
        int c1 = 0, c2 = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(nums[i] == exclude) {
                continue;
            }
            
            if(e1 == nums[i]) {
                c1++;
            }
            else if(e2 == nums[i]) {
                c2++;
            }
            else if(c1 < c2) {
                c1--;
                if(c1 <= 0) {
                    e1 = nums[i];
                    c1 = 1;
                }
            }
            else {
                c2--;
                if(c2 <= 0) {
                    e2 = nums[i];
                    c2 = 1;
                }
            }
        }
        
        c1 = 0;
        for(int i = 0; i < nums.size(); i++) {
            c1 += (e1 == nums[i]);
        }
        if(c1 > n/3) return e1;
        
        c2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            c2 += (e2 == nums[i]);
        }
        if(c2 > n/3) return e2;
        
        return LONG_MIN;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>result;
        
        long long int value = getValue(nums, n, LONG_MIN);
        if(value != LONG_MIN) {
            result.push_back(value);
            value = getValue(nums, n, value);
            if(value != LONG_MIN)
                result.push_back((int)(value));
        }
        
        return result;
    }
};
