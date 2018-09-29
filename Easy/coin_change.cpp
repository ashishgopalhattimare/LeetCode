// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // let initially needed to make each amount is infinity
        vector<int>coinNeeded(amount+1,INT_MAX-1); // INT_MAX -1 because INT_MAX + 1 would become INT_MIN
        
        sort(coins.begin(), coins.end());
        coinNeeded[0] = 0; // coin needed to make 0 amount
        
        for(int i = 0; i < coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                
                // if the coin in have is same as coin in need to make the same amount
                if(j == coins[i]) {
                    coinNeeded[j] = 1;
                }
                
                // if the coin is minimizing the coin needed to make the amount, then
                // use it
                else if(j > coins[i]) {
                    coinNeeded[j] = min(coinNeeded[j], (coinNeeded[j-coins[i]])+1);
                }
            }
        }
        
        if(coinNeeded[amount] == INT_MAX-1) {
            return -1;
        }
        return coinNeeded[amount];
    }
};