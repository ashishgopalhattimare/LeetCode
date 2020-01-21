// https://leetcode.com/problems/maximum-69-number/
// Easy

class Solution {
    public int maximum69Number (int num) {
        
        char[] arr = Integer.toString(num).toCharArray();
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == '6') {
                arr[i] = '9';
                break;
            }
        }
        return Integer.parseInt(String.valueOf(arr));
    }
}