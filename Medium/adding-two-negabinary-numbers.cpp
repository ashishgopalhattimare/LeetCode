// https://leetcode.com/contest/weekly-contest-139/problems/adding-two-negabinary-numbers/

class Solution {
public:
    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        for (int i = A.size() - 1, j = B.size() - 1, carry = 0; i >= 0 || j >= 0 || carry; i--, j--) {
            if (i >= 0) carry += A[i];
            if (j >= 0) carry += B[j];
            
            ans.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (ans.size() > 1 && ans.back() == 0) ans.pop_back(); // remove leading zeros
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
