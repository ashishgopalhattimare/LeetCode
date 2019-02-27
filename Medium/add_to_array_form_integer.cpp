// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    int max(int x, int y) {
        
        return (x > y) ? x : y;
    }
    vector<int> addToArrayForm(vector<int>& A, int K) {
        
        vector<int> result( max(A.size(), static_cast<int>(log(K)/log(10))) + 2, 0);
        
        for(int i = result.size()-1, j = A.size()-1; i >= 0 && j >= 0; i--, j--) {
            result[i] = A[j];
        }
        
        int carry = 0;
        int sum = 0, index = result.size()-1;
        for( ; index && K; ) {
            
            sum = (K%10) + result[index] + carry;
            
            result[index--] = sum % 10;
            carry = sum/10;
            
            K/=10;
        }
        
        while(index >= 0 && (carry || K)) {
            sum = (K%10) + result[index] + carry;
            
            result[index--] = sum % 10;
            
            carry=sum/10;
            K/=10;
        }
        
        while(result.size() != 1 && result[0] == 0) {
            result.erase(result.begin());
        }
        
        return result;
    }
};
