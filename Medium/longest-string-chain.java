// https://leetcode.com/problems/longest-string-chain/

class Solution {
    int maxim;
    public void algorithm(String[] words, HashMap<String, Integer> set, int count, int index) {
        
        if(index < 0 && maxim > count) return;
        String word = words[index];
        
        for(int i = 0; i < word.length(); i++) {
            String temp = word.substring(0, i) + word.substring(i+1);
            if(temp.length() != 0) {
                if(set.containsKey(temp)) {
                    if(maxim < count) maxim = count;
                    algorithm(words, set, count+1, set.get(temp));
                }
            }
        }
        
        return;
    }
    
    public int longestStrChain(String[] words) {
        
        HashMap<String, Integer>set = new HashMap<String, Integer>();
        
        for(int i = 0; i < words.length; i++) {
            set.put(words[i], i);
        }
        
        maxim = 1;
        for(int i = words.length-1; i >= 0; i--) {
            algorithm(words, set, 2, i);
        }
        
        return maxim;
    }
}
