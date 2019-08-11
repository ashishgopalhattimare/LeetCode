// TLE : DP : Egg Dropping Problem

class Solution {
public:
    
    int DP[103][10003];
    
    void reset() {
        for(int i = 0; i < 103; i++) {
            for(int j = 0; j < 10003; j++) {
                if(i == 0 || j == 0) {
                    DP[i][j] = 0;
                }
                else if(j == 1) DP[i][j] = 1;
                else if(i == 1) DP[i][j] = j;
                else 
                    DP[i][j] = INT_MAX;
            }
        }
    }
    
    void print(int K, int N) {
        for(int i = 0; i <= K; i++) {
            for(int j = 0; j <= N; j++) {
                printf("%d ", DP[i][j]);
            }
            printf("\n");
        }
    }
    
    int simulation(int totalEggs, int totalFloor) {
        
        for(int i = 2; i <= totalEggs; i++) {
            for(int j = 2; j <= totalFloor; j++) {
                
                // try all possible combination
                for(int k = 1; k <= j; k++) {
                    int worst = max(DP[i-1][k-1], DP[i][j-k]);
                    DP[i][j] = min(DP[i][j], worst+1);
                }
            }
        }
        return DP[totalEggs][totalFloor];
    }
    
    int superEggDrop(int K, int N) {
        
        reset();
        
        // base cases
        // n floor and 1 egg = n tries
        // 1 floor and n eggs= 1 try
        // 0 floor and n eggs= 0 try
        
        return simulation(K, N);
    }
};
