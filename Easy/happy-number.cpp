// https://leetcode.com/problems/happy-number/
// Easy

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long int>set;
        
        long long int k = n, temp;
        while(true) {
            if(k == 1) return true; // Ends in 1
            if(set.find(k) != set.end()) // Endless Loop
                return false;
            
            set.insert(k);
            temp = 0;
            while(k) {
                temp += pow(k%10, 2);
                k/=10;
            }
            k = temp;
        }
    }
};
