// https://leetcode.com/contest/weekly-contest-176/problems/count-negative-numbers-in-a-sorted-matrix/
// Easy

class Solution {
public:

	int binary_search(vector<int>& arr, int start, int end) {

		if(start > end) return -1;

		if(start == end || start+1 == end) {
			if(arr[start] < 0) return start;
			return (arr[end] < 0)? end : -1;
		}

		int mid = (start+end)/2;

		if(arr[mid] < 0) return binary_search(arr, start, mid);
		return binary_search(arr, mid, end);
	}
	
    int countNegatives(vector<vector<int>>& grid) {
        
    	int countNeg = 0, index;
    	for(vector<int>& arr : grid) {
    		index = binary_search(arr, 0, arr.size()-1);

    		if(index != -1) countNeg += (arr.size() - index);
    	}

    	return countNeg;
    }
};