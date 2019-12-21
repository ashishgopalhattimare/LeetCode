// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
// Medium

class Solution {
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> colsum) {

		int n = colsum.size();
		vector<vector<int>> result(2, vector<int>(n, 0));

		vector<bool>filled(n, false);

		for(int i = 0; i < n; i++) {
			switch(colsum[i]) {
				case 2: result[0][i] = result[1][i] = 1;
						upper--; lower--;

				case 0: filled[i] = true;
				case 1: break;

				// Not possible result
				default : return {};
			}
		}

		for(int i = 0; i < n; i++) {
			if(filled[i] == false) { // this index is not decided yet, must have 1 in either row
				if(upper) {
					result[0][i] = 1;
					upper--;
				}
				else if(lower) {
					result[1][i] = 1;
					lower--;
				}

				// Not possible result, as all are full
				else return {};
			}
		}

		// Not possible since result matrix has less 1's than required
		if(upper || lower) return {};

		// Return the valid and possible output
		return result;
	}
};