// https://leetcode.com/contest/biweekly-contest-2/problems/confusing-number-ii/
// Hard, Intuition Important to Consider

class Solution {
public:
    
    int confusingNumberII(int N) {

        // rotate elmeent and your get its corresponding value        
        unordered_map<int,int>map;
        map[0] = 0;
        map[1] = 1;
        map[6] = 9;
        map[8] = 8;
        map[9] = 6;
        
        // rotation of temp could exceed int limit, thus long long int
        long long int rotated, temp;
        int skipValues = 0; // values to skip for fast processing
        int result = 0;
        bool valid; // check whether the current number is valid or not
        for(int i = 1; i <= N; i++) {
            
            valid = temp = i; rotated = 0;
            while(temp) {

                // If the digit is not in the map, not a valid digit to rotate
                if(map.find(temp%10) == map.end()) {
                    
                    /***********************************************************************
                     * Intuition : Assume number to be 18588 (Game Changer Algorithm)
                     * 
                     * This is invalid because 5 is not valid, thus all the numbers between
                     * 18588 to 18688 are automatically invalid
                     * 
                     * Thus, while forming the rotated digit, this would fail when we are
                     * at 5, thus we need to skipValues to be 10^2 = 100
                     * 
                     * 18588
                     * + 100
                     * -----
                     * 18600
                     * 
                     * We have subtracted 1 because, if the number valid is
                     * 188788 is valid at 7
                     * 
                     * 188788
                     * +  100
                     * ------
                     * 188888
                     * 
                     * This is valid, but next iteration in main forloop would increment
                     * this by 1. Hence, next value to be checked would be 188889, instead of
                     * 188888
                     */
                    i += (pow(10,skipValues)-1);

                    /***********************************************************************/
                    valid = false;
                    break;
                }
                skipValues++; // digits to skips
                rotated = rotated*10 + map[temp%10];
                temp/=10;
            }
            
            // if the number of valid
            if(valid && rotated != i) {
                result++;
            }
            
            // reset to 0;
            skipValues = 0;
        }
        
        return result;
    }
};
