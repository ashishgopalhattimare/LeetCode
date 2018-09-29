// https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    
    int eitherEnds(int start, int end) {
        int blocks = end-start+1;
        
        if(blocks >= 3) {
            return blocks/2;
        }
        return 0;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n == 0) return true;
        
        if(flowerbed.size() == 1) {
            return (flowerbed[0] == 0 && n == 1);
        }
        
        int start, end;
        int blocks;
        int newFlowers = 0;
        
        start = end = -1;
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 1) {
                if(start == -1) {
                    if(i != 0) {
                        newFlowers += eitherEnds(0, i);
                    }
                    start = i;
                }
                else {
                    end = i;
                    
                    blocks = (end-start+1) - 2;
                    if(blocks>=3) {
                        newFlowers += (blocks-1)/2;
                    }
                    start = end;
                }
            }
        }
        
        newFlowers += eitherEnds(start, flowerbed.size()-1);
        
        cout << newFlowers << endl;
        return (newFlowers >= n);
    }
};