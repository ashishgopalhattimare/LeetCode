// https://leetcode.com/problems/letter-tile-possibilities/
// Medium
// DFS + Backtrack

class Solution {
public:
    
    vector<char>result;
    int count = 0;
    void bfs(vector<int>& tiles) {
        if(result.size()) {
            // for(char x : result) printf("%c ", x);
            // printf("\n");
            count++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(tiles[i] > 0) {
                tiles[i] = tiles[i] - 1;
                result.push_back('A'+i);
                bfs(tiles);
                
                tiles[i] = tiles[i] + 1;
                result.pop_back();
            }
        }
    }
    
    int numTilePossibilities(string tile) {
        
        vector<int>tiles(26, 0);
        for(char x : tile) {
            tiles[x-'A']++;
        }
        
        bfs(tiles);
        
        return count;
    }
};
