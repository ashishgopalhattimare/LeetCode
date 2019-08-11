// https://leetcode.com/problems/word-ladder/
// Medium, BFS using List and Hash
// O(n^2) complexity

// Once each string taken, dont take it again

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        HashMap<String, List<String>>map = new HashMap<>();
        
        for(String x : wordList) {
            for(int i = 0; i < x.length(); i++) {
                String pattern = x.substring(0,i) + "*" + x.substring(i+1);
                
                if(!map.containsKey(pattern)) {
                    map.put(pattern, new ArrayList<>());
                }
                
                List<String>list = map.get(pattern);
                list.add(x);
            }
        }
        
        Queue<Integer>qint = new LinkedList<Integer>();
        Queue<String> qstr = new LinkedList<String>();
        
        qstr.add(beginWord);
        qint.add(1);
        
        HashSet<String>set = new HashSet<>();
        set.add(beginWord);
        while(qstr.size() > 0)
        {
            String curr = qstr.remove();
            int count = qint.remove();
            
            if(endWord.equals(curr)) return count;
            
            for(int i = 0; i < curr.length(); i++) {
                String pattern = curr.substring(0,i) + "*" + curr.substring(i+1);
                
                if(map.containsKey(pattern)) {
                    List<String>list = map.get(pattern);
                    for(String str : list) {
                        if(!set.contains(str)) {
                            qint.add(count+1);
                            qstr.add(str);

                            set.add(str);
                        }
                    }   
                }
            }
        }
        
        return 0;
    }
}
