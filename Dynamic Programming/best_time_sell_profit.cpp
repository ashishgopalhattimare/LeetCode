// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0) return 0;
        
        int n = prices.size()-1;
        
        vector<int>minArr(prices.size());
        vector<int>maxArr(prices.size());

        // Since we need to find only once.. find the minValue i can take at each index from 0 to i --> BUYING COST ARRAY
        // max then maximum i can take from n-1 to i --> SELLING COST ARRAY
        
        int minVal = minArr[0] = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            
            minVal = min(minVal, prices[i]);
            minArr[i] = minVal;
        }
        
        int maxVal = maxArr[n] = prices[n];
        for(int i = n-1; i >= 0; i--) {
            
            maxVal = max(maxVal, prices[i]);
            maxArr[i] = maxVal;
        }
        
        maxVal = INT_MIN;
        for(int i = 0; i < prices.size(); i++) {

            // if the buy is less than sell
            if(minArr[i] <= maxArr[i]) {
                maxVal = max(maxVal, maxArr[i] - minArr[i]);
            }
        }
        
        return maxVal;
    }
};