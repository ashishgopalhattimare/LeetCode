// https://leetcode.com/problems/sort-the-matrix-diagonally/
// Medium

class Solution {
public:

    bool inrange(int x, int limit) {
        return x >= 0 && x < limit;
    }
    
	void recursive(int gi, int gj, vector<vector<int>>& mat) {

		vector<int>arr;
		int i = gi, j = gj, size = 0;
		while(inrange(i, mat.size()) && inrange(j, mat[i].size())) {
			arr.push_back(mat[i][j]);
			i++; j++;
            size++;
		}
        
    	sort(arr.begin(), arr.end());
        
        for(int i = gi, j = gj, tempi = 0; size; i++, j++, tempi++, size--) {
            mat[i][j] = arr[tempi];
		}
        
        if(gi == 0) {
            if(gj != mat[0].size()) {
                recursive(gi, gj+1, mat); // recursive forward
            }
        }
        else recursive(gi-1, gj, mat); // recursive upward
	}

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        if(mat.size() > 1 && mat[0].size() > 1) // not an array
    	    recursive(mat.size()-1, 0, mat);
        
        return mat;
    }
};