// https://www.interviewbit.com/problems/longest-consecutive-sequence/
// Amazon, Google
// O(n) time complexity

int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int>set;
    
    for(int x : A) set.insert(x);
    
    int maximLength = INT_MIN;
    int tempLen, low, high;
    for(int x : A) {
        if(set.find(x) != set.end()) {
            set.erase(x);
            
            tempLen = 1;
            low = x-1; high = x+1;
            while(set.find(low) != set.end()) {
                set.erase(low--);
                tempLen++;
            }
            while(set.find(high) != set.end()) {
                set.erase(high++);
                tempLen++;
            }
            
            maximLength = max(maximLength, tempLen);
        }
    }
    
    return maximLength;
}

