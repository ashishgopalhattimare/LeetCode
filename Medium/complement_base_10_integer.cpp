class Solution {
public :
    int bitwiseComplement(int N) {

        if(N == 0) return 1;

        int result = 0;
        for(int i = 0; N; i++, N/=2) {
            result = result + (1 << i) * (N%2 == 0);
        }
        return result;
    }
};