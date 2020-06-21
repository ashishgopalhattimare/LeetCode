// https://leetcode.com/problems/cinema-seat-allocation/
// Medium

class Solution {
public:
    
    unordered_map<int,unordered_set<int>>mapi;
    
    bool seatsAvailable(int start, int end, int i)
    {
        for(int j = start; j <= end; ++j) {
            if(mapi[i].find(j) != mapi[i].end()) {
                return false;
            }
        }
        return true;
    }
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        for(vector<int>& x : reservedSeats) {
            mapi[x[0]].insert(x[1]); 
        }
        
        int count, FAMILY = 4;
        int result = 0;
        for(int i = 1; i <= n; ++i) {
            if(mapi.find(i) == mapi.end()) { // row not found
                result += 2;
                continue;
            }
            
            if(seatsAvailable(2, 5, i)) {
                result++;
                result += seatsAvailable(6, 9, i);
            }
            else {
                if(seatsAvailable(4, 7, i)) result++;
                else {
                    result += seatsAvailable(6, 9, i);
                }
            }
        }
        return result;
    }
};