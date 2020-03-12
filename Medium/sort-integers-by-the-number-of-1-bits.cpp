// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Easy

class Solution {
public:
    
    int getCount(int num)
    {
        int count = 0;
        while(num) {
            if(num % 2 == 1) count++;
            num/=2;
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int,int>> temp(arr.size());
        for(int i = 0; i < arr.size(); i++) {
        	temp[i] = {getCount(arr[i]), arr[i]};
        }

        sort(temp.begin(), temp.end());

        vector<int>result(arr.size());
        for(int i = 0; i < arr.size(); i++) {
        	result[i] = temp[i].second;
        }

        return result;
    }
};