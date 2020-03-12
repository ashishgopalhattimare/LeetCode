// https://leetcode.com/problems/jump-game-v/
// Hard

class Solution {
public:
    
    bool inrange(int x, int limit) {
        return x >= 0 && x < limit;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        
        vector<int>disArr(arr.size(), 1);
        int n = arr.size();
        
        vector<pair<int,int>>tp(n);
        for(int i = 0; i < arr.size(); i++) { // O(nlogn)
            tp[i] = {arr[i], i};
        }
        
        sort(tp.begin(), tp.end()); // O(nlogn)
        
        bool goleft, goright;
        int i, val;
        for(int j = n-1; j >= 0; j--) { // O(n^2)
            
            i = tp[j].second;
            
            goleft = goright = true;
            for(int k = 1; k <= d; k++) { // O(n)
                
                if(inrange(i-k, n) && goleft) { // go LHS
                    if(arr[i-k] < arr[i])
                        disArr[i-k] = max(disArr[i-k], disArr[i] + 1);
                    else
                        goleft = false;
                }
                
                if(inrange(i+k, n) && goright) { // go RHS
                    if(arr[i+k] < arr[i])
                        disArr[i+k] = max(disArr[i+k], disArr[i] + 1);
                    else
                        goright = false;
                }
            }
        }
        
        int result = 1;
        for(int x : disArr) result = max(result, x);
        
        return result;
    }
};