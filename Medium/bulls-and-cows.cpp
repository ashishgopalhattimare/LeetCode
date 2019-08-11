// https://leetcode.com/problems/bulls-and-cows/
// Medium
// Tricky
// Solve for same and then solve for different if possible
// Complexity : O(n)

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>map;
        
        for(char x : secret) map[x]++
        
        int bulls = 0, cows = 0;
        
        // Mark all bulls that are placed correctly
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                map[secret[i]]--;
                bulls++;
            }
        }
        
        // Now check if guess are still placed anywhere, except the places
        // taken by the bull places
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] != guess[i] && map[guess[i]]) {
                map[guess[i]]--;
                cows++;
            }
        }
        
        string result = "";
        result += to_string(bulls) + "A";
        result += to_string(cows) + "B";
        
        return result;
    }
};
