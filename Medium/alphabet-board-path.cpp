// https://leetcode.com/contest/weekly-contest-147/problems/alphabet-board-path/
// Medium
// O(26n) time

class Solution {
public:
    
    string result = "";
    void printDir(int start, int end, char x, int factor) {
        
        // printf("%d %d %c %d\n", start, end, x, factor);
        while(start != end){
            result.push_back(x);
            start += factor;
        }
    }
    
    vector<int> getCoordinate(char x) {
        return {(x-'a')/5, (x-'a')%5};
    }
    
    string alphabetBoardPath(string target) {

        char start = 'a';
        for(char x : target) {
            if(start != x) {
                vector<int> source = getCoordinate(start);
                vector<int> destin = getCoordinate(x);
                
                if(source[1] < destin[1]) { // source is left of destination
                    if(source[0] < destin[0]) { // source is above destination
                        printDir(source[0], destin[0], 'D', 1);
                    }
                    else {
                        printDir(source[0], destin[0], 'U', -1);
                    }
                    printDir(source[1], destin[1], 'R', 1);
                }
                else { // source is right of destination
                    printDir(source[1], destin[1], 'L', -1);
                    if(source[0] < destin[0]) { // source is above destination
                        printDir(source[0], destin[0], 'D', 1);
                    }
                    else {
                        printDir(source[0], destin[0], 'U', -1);
                    }
                }
            }
            
            result.push_back('!');
            start = x;
        }
        
        return result;
    }
};