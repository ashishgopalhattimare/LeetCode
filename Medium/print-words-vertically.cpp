// https://leetcode.com/problems/print-words-vertically/
// Medium

class Solution {
    
    private String regex = "\\s+$";
    
    public List<String> printVertically(String s) {
        
        String[] arr = s.split("[ ]");
        int row, index = -1, col = arr.length;
        
        row = Integer.MIN_VALUE;
        for(int i = 0; i < arr.length; i++) {
            row = Math.max(row, arr[i].length());
        }
        
        char[][] matrix = new char[row][col];
        int j;
        for(int i = 0; i < arr.length; i++) { // read words
            j = 0;
            while(j < arr[i].length()) {
                matrix[j][i] = arr[i].charAt(j);
                j++;
            }
            while(j < row) matrix[j++][i] = ' ';
        }
        
        List<String> result = new ArrayList<>();
        
        for(int i = 0; i < row; i++) {
            StringBuilder sb = new StringBuilder();
            for(j = 0; j < col; j++) {
                sb.append(matrix[i][j]);
            }
            result.add(sb.toString().replaceAll(this.regex, ""));
        }
        
        return result;
    }
}