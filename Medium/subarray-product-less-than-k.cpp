class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1) return 0;
        
        long long totalComb = 0, product = 1;
        int start = 0, i;
        for(i = 0; i < nums.size(); i++) {
            
            // if product * current value is greater than limit
            while(start < i && product * nums[i] >= k) {
                // add to totalCombination only if the product is valid 
                if(product < k) totalComb += (i-start);
                
                product /= nums[start++]; // remove start element
            }
            product *= nums[i]; // add current element to the product
        }
        
        while(start <= i && product >= k) { // remove until the remaining product is less than 
                                            // limit
            product /= nums[start++];
        }
        
        long long size = nums.size()-start;
        totalComb += (size*(size+1))/2;
        
        return totalComb;
    }
};
