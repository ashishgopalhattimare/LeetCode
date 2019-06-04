// https://leetcode.com/contest/biweekly-contest-1/problems/fixed-point/
// Easy

class Solution {
public:
    
    void binarySearch(int start, int end, vector<int>& A, int &result) {
        if(start > end) return;
        
        if(end == start || end == start+1) {
            if(A[start] == start) {
                result = min(result, start);
            }
            else if(A[end] == end) {
                result = min(result, end);
            }
            return;
        }
        
        int mid = start + (end-start)/2;
        if(A[mid] == mid) result = min(result, mid);
        
        if(A[mid] >= mid) binarySearch(start, mid, A, result);
        else binarySearch(mid, end, A, result);
    }
    
    int fixedPoint(vector<int>& A) {
        int result = INT_MAX;
        binarySearch(0, A.size()-1, A, result);
        
        return (result == INT_MAX) ? -1 : result;
    }
};
