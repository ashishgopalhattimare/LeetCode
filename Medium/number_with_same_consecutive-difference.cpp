// https://leetcode.com/contest/weekly-contest-117/problems/numbers-with-same-consecutive-differences/

class Solution {
public:
    
    void backtrack(int value, int number, int count, int N, int K, vector<int>& result)
    {
        if(value < 0 || value > 9) return;
        
        if(count == N) {
            if(N == int(log10(number)) + 1 || (number == 0 && N == 1))
                result.push_back(number);
            return;
        }
        
        backtrack(value-K, number*10+(value-K), count+1, N, K, result);
        backtrack(value+K, number*10+(value+K), count+1, N, K, result);
        
        return;
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        
        vector<int> result;
        
        if(N == 0) return result;
        
        int number;
        
        if(K == 0 || (N == 1)) {
            int i;
            if(N == 1) i = 0;
            else i = 1;
            
            for( ; i != 10; i++) {
                number = 0;
                for(int j = 0; j != N; j++) {
                    number = number*10+i;
                }
                result.push_back(number);
            }
        }
        else {
            for(int i = 1; i != 10; i++) {
                backtrack(i, i, 1, N, K, result);
            }
        }
        
        return result;
    }
};
