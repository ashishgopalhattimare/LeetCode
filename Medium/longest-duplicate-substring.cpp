// https://leetcode.com/problems/longest-duplicate-substring/
// Binary Search + Rabin_Karp

class Solution {
public:
    
    bool duplicateFound(string& input, int k, string& result)
    {
        unordered_set<long long>set;
        
        // find the first k character hash
        long long hash = 0;
        int power = k-1;
        for(int i = 0; i < k; i++) {
            hash += ((input[i]-'a'+1)*pow(10, power--));
        }
        
        set.insert(hash);
        
        int start = 0;
        for(int i = k; i < input.length(); i++) {
            hash -= ((input[start++]-'a'+1)*pow(10, k-1));
            hash = hash*10 + (input[i]-'a'+1);
            
            if(set.find(hash) != set.end()) { // duplicate found
                result = input.substr(start, i-start+1);
                return true;
            }
            else set.insert(hash);
        }
        
        return false;
    }
    
    string longestDupSubstring(string S) {
        
        string result = "";
        
        int low = 1, high = S.length()-1;
        int mid;
        while(low <= high) {
            mid = low + (high-low)/2;
            if(duplicateFound(S, mid, result)) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        
        return result;
    }
};
