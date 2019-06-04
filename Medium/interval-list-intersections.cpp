// https://leetcode.com/problems/interval-list-intersections/submissions/
// Medium, Facebook Interview

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int i0 = 0, a0, a1;
        int i1 = 0, b0, b1;
        
        vector<vector<int>> result;
        while(i0 < A.size() && i1 < B.size()) {
            
            a0 = A[i0][0]; /*start*/ a1 = A[i0][1]; /*end*/
            b0 = B[i1][0]; /*start*/ b1 = B[i1][1]; /*end*/
            
            if(a1 == b0/*end == start*/) {
                result.push_back({a1, a1});
                i0++;
            }
            else if(a0 == b1/*start == end*/) {
                result.push_back({a0, a0});
                i1++;
            }
            else if(a1/*end*/ < b0/*start*/) {
                i0++;
            }
            else if(b1/*end*/ < a0/*start*/) {
                i1++;
            }
            else {
                int start = max(a0, b0);
                int end = min(a1, b1);
                
                result.push_back({start, end});
                
                if(a0 <= b0) {
                    if(a1 >= b1) i1++;  // case 1
                    else i0++;          // case 2
                }
                else {
                    if(a1 >= b1) i1++;  // case 3
                    else i0++;          // case 4
                }
            }
        }
        
        return result;
    }
};
