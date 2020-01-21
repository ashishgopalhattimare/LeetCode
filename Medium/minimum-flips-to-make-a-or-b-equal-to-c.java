// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
// Medium

class Solution {
    
    String getBinary(int num, int len)
    {
        StringBuilder sb = new StringBuilder();
        while(num > 0) {
            if(num % 2 == 0) sb.append('0');
            else sb.append('1');
            num >>= 1;
        }
        while(sb.length() != len) sb.append('0');
        return sb.reverse().toString();
    }
    
    public int minFlips(int a, int b, int c) {
        
        int maxLen = Integer.toBinaryString(Math.max(a, Math.max(b, c))).length();
        
        String aa = getBinary(a, maxLen);
        String bb = getBinary(b, maxLen);
        String cc = getBinary(c, maxLen);
        
        int flips = 0;
        for(int i = 0; i < maxLen; i++) {
            if(cc.charAt(i) == '0') {
                if(aa.charAt(i) == '1') flips++;
                if(bb.charAt(i) == '1') flips++;
            }
            else { // '1'
                if(aa.charAt(i) == '0' && bb.charAt(i) == '0')
                    flips++;
            }
        }
        
        return flips;
    }
}