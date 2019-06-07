// https://leetcode.com/problems/binary-watch/
// Easy, Combinatorics

class Solution {
public:
    vector<pair<int,int>>hrmin;
    vector<string>result;
    
    void minutes(int hrs, int x, int index, int limit, int sum) {
        if(x > 6 || index > 6 || sum > 59) return;
        
        if(index == limit) { // minute bits are all used, store the hrs:minutes in vector 
            hrmin.push_back(make_pair(hrs, sum));
            return;
        }
        minutes(hrs, x+1, index+1, limit, sum + pow(2, x)); // use this bit for min
        minutes(hrs, x+1, index, limit, sum); // move to next bit for min
    }
    
    void hours(int x, int index, int limit, int sum, int num) {
        if(x > 4 || index > 4 || sum >= 12) return; // exceeded maxim hours is 11
        
        if(index == limit) { // all the bits are used
            minutes(sum, 0, 0, num-limit, 0); // bits that will be used by minutes
            return;
        }
        hours(x+1, index+1, limit, sum + pow(2, x), num); // use this bit
        hours(x+1, index, limit, sum, num); // dont use this bit, move to next bit
    }
    
    vector<string> readBinaryWatch(int num) {
        
        for(int i = 0; i <= num; i++)
        hours(0, 0, i, 0, num);
        
        sort(hrmin.begin(), hrmin.end(), [](pair<int,int>& a, pair<int,int>& b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        
        for(pair<int,int> x : hrmin) {
            string time = to_string(x.first);
            time.push_back(':');
            if(x.second < 10)
                time.push_back('0');
            time.append(to_string(x.second));
            
            result.push_back(time);
        }
        
        return result;
    }
};
