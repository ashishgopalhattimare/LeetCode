// Medium
// List Data structure, BFS using list and visited

class Solution {
public:
    
    int X[4] = {-1,0,0,1};
    int Y[4] = {0,-1,1,0};
    
    bool inrange(int x, int l) {
        return x >= 0 && x < l;
    }
    
    int traverse(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& temp, int counter)
    {
        list<vector<int>> st;
        
        temp[i][j] = counter;
        int c;
        
        vector<int> ptr;
        
        st.push_back({i,j,0});
        while(!st.empty()) {
            ptr = st.front();
            st.pop_front();
            
            i = ptr[0]; j = ptr[1]; c = ptr[2];
            
            if(matrix[i][j] == 0) return c;
            else {
                for(int k = 0; k < 4; k++) {
                    if(inrange(i+Y[k], matrix.size()) && inrange(j+X[k], matrix[0].size()) && temp[i+Y[k]][j+X[k]] < counter) {
                        temp[i+Y[k]][j+X[k]] = counter;
                        st.push_back({i+Y[k],j+X[k],c+1});
                    }
                }
            }
        }
        return 1;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        vector<vector<int>>temp = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                temp[i][j] = 0;
            }
        }
        
        int counter = 1;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j]) {
                    matrix[i][j] = traverse(i, j, matrix, temp, counter);
                    counter++;
                }
            }
        }
        
        return matrix;
    }
};
