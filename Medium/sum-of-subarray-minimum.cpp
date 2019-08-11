// https://leetcode.com/problems/sum-of-subarray-minimums/
// Medium
// Stack : Good Question

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        
        long long totalSum = 0;
        long long mod = 1e9+7;
        
        stack<pair<long long,long long>>st; // <value,before>
        pair<long long,long long>curr;
        
        long long product;
        for(int x : A) {
            if(st.empty() || (st.top()).first <= x) {
                // printf("push : {%lld,%lld}\n", x, 0);
                st.push({x, 0});
            }
            else {
                long long c = 0, index = 1, popCount = 0;
                long long prevCount = 0;
                while(!st.empty() && (st.top()).first > x){
                    
                    curr = st.top(); st.pop();
                    
                    product = (curr.first * (index + c%mod))%mod;
                    totalSum = totalSum + product + (product * curr.second)%mod;
                    
                    // printf("- %lld\n", product + product * curr.second);
                    
                    totalSum %= mod;
                    
                    c += curr.second;
                    popCount = popCount + (1 + curr.second);
                    index++;
                }
                
                // printf("push : {%lld,%lld}\n", x, popCount);
                st.push({x%mod, popCount%mod});
            }
        }
        
        long long c = 0, index = 1;
        while(!st.empty()) {
            curr = st.top(); st.pop();
            
            product = (curr.first * (index + c%mod))%mod;
            totalSum = totalSum + product + (product * curr.second)%mod;
            // printf("- %lld\n", product + product * curr.second);
            
            totalSum %= mod;
            
            c += curr.second;
            index++;
        }
        
        return totalSum;
    }
};
