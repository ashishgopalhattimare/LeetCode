// https://leetcode.com/problems/count-largest-group/
// Easy

class Solution {
public:
    int countLargestGroup(int n) {
        
        map<int,int>mapi;
        int result = 0, temp, sum;
        
        for(int i = 1; i <= n; i++) {
            temp = i; sum = 0;
            while(temp) {
                sum += temp%10;
                temp/=10;
            }
            mapi[sum]++;
            result = max(result, mapi[sum]);
        }
        
        int count = 0;
        for(auto itr = mapi.begin(); itr != mapi.end(); itr++) {
            if(itr->second == result) count++;
        }
        
        return count;
    }
};