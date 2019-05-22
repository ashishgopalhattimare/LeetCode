// https://leetcode.com/problems/trapping-rain-water-ii/
// Hard : MinHeap
// https://www.youtube.com/watch?time_continue=350&v=cJayBq38VYw

class Solution {
public:
    
    int X[4] = {-1,1,0,0};
    int Y[4] = {0,0,-1,1};
    
    bool valid(int x, int limit) {
        return x >= 0 && x < limit;
    }
    
    void setup1(vector<vector<int>>& heightMap, vector<vector<int>>& height, int row, int start, int end, int factor) {
        int maxim = INT_MIN;
        for(int i = start; i != end; i+=factor) {
            maxim = max(maxim, heightMap[row][i]);
            height[row][i] = maxim;
        }
    }
    
    void setup2(vector<vector<int>>& heightMap, vector<vector<int>>& height, int col, int start, int end, int factor) {
        int maxim = INT_MIN;
        for(int i = start; i != end; i+=factor) {
            maxim = max(maxim, heightMap[i][col]);
            height[i][col] = maxim;
        }
    }
    
    int minima(int a, int b, int c, int d) {
        return min(a, min(b, min(c, d)));
    }
    
    void print(vector<vector<int>>& m) {
        for(vector<int> a : m) {
            for(int x : a) printf("%d ", x);
            printf("\n");
        }
        printf("\n");
    }
    
    void traverseHeight(int i, int j, vector<vector<bool>>& updated, vector<vector<int>>& matrix, int *minHeight, stack<pair<int,int>>& st, vector<vector<int>>& visited, int count)
    {
        if(matrix[i][j] > *minHeight || visited[i][j] == count) return;
        
        *minHeight = min(*minHeight, matrix[i][j]);
        if(!updated[i][j]) return;
        
        st.push(make_pair(i, j));
        updated[i][j] = false;
        
        visited[i][j] = count;
        
        for(int k = 0; k < 4; k++) {
            if(valid(i+Y[k], updated.size()) && valid(j+X[k], updated[0].size())) {
                traverseHeight(i+Y[k], j+X[k], updated, matrix, minHeight, st, visited, count);
            }
        }
        return;
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        if(heightMap.size() <= 2 || heightMap[0].size() <= 2) return 0;
        
        // Left to Right
        vector<vector<int>> lheight = heightMap; // left to right
        vector<vector<int>> rheight = heightMap; // right to left
        
        // Top to Down
        vector<vector<int>> theight = heightMap; // top to down
        vector<vector<int>> dheight = heightMap; // down to top
        
        // lheight and rheight setup
        for(int i = 0; i < heightMap.size(); i++) {
            setup1(heightMap, lheight, i, 0, heightMap[i].size(), 1);
            setup1(heightMap, rheight,i,heightMap[i].size()-1,-1,-1);
        }
        
        // theight and dheight setup
        for(int i = 0; i < heightMap[0].size(); i++) {
            setup2(heightMap, theight, i, 0, heightMap.size(), 1);
            setup2(heightMap, dheight,i,heightMap.size()-1,-1,-1);
        }
        
        // print(heightMap); print(lheight); print(rheight); print(theight); print(dheight);
        
        int result = 0, minim;
        vector<vector<int>>matrix = heightMap;
        vector<vector<bool>>update;
        vector<vector<int>>visited;
        
        for(int i = 0; i < matrix.size(); i++) {
            vector<bool>row(matrix[i].size(), false);
            update.push_back(row);
            
            vector<int>row1(matrix[i].size(), 0);
            visited.push_back(row1);
        }
        
        for(int i = 0; i < heightMap.size()-1; i++) {
            for(int j = 0; j < heightMap[i].size()-1; j++) {
                
                minim = minima(lheight[i][j], rheight[i][j], theight[i][j], dheight[i][j]);
                update[i][j] = abs(minim - heightMap[i][j]);
                matrix[i][j] = minim;
            }
        }
        
        // print(heightMap);
        // for(vector<bool>a : update) {
        //     for(bool x : a) printf("%d ", x); printf("\n");
        // }printf("\n");
        // print(matrix);
        
        // Remove any unwanted additional height due to other connected updated heights
        // [[12,13,1,12],[13,4,13,12],[13,8,10,12],[12,13,12,12],[13,13,13,13]]
        // [[14,17,18,16,14,16],[17,3,10,2,3,8],[11,10,4,7,1,7],[13,7,2,9,8,10],[13,1,3,4,8,6],[20,3,3,9,10,8]]
        // [[78,16,94,36],[87,93,50,22],[63,28,91,60],[64,27,41,27],[73,37,12,69],[68,30,83,31],[63,24,68,36]]
        // [[14,20,11,19,19,16],[11,10,7,4,9,6],[17,2,2,6,10,9],[15,9,2,1,4,1],[15,5,5,5,8,7],[14,2,8,6,10,7]]
        // [[9,9,9,9,9,9,8,9,9,9,9],[9,0,0,0,0,0,1,0,0,0,9],[9,0,0,0,0,0,0,0,0,0,9],[9,0,0,0,0,0,0,0,0,0,9],[9,9,9,9,9,9,9,9,9,9,9]]
        
        stack<pair<int,int>>st;
        pair<int,int>ptr;
        int minHeight;
        
        int count = 1;
        for(int i = 1; i < update.size()-1; i++) {
            for(int j = 1; j < update[i].size()-1; j++) {
                if(update[i][j]) {
                    minHeight = INT_MAX;
                    traverseHeight(i, j, update, matrix, &minHeight, st, visited, count);
                    
                    while(!st.empty()) {
                        ptr = st.top();
                        st.pop();
                        
                        matrix[ptr.first][ptr.second] = max(heightMap[ptr.first][ptr.second], minHeight);
                    }
                    count++;
                }
            }
        }
        
        // print(matrix);
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++)
                result += abs(heightMap[i][j]-matrix[i][j]);
        
        return result;
    }
};
