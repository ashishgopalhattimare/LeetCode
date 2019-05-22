// https://leetcode.com/problems/last-stone-weight/

class Solution {
    public int lastStoneWeight(int[] stones) {
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return b-a;
            }
        });
        
        for(int x : stones)
            pq.add(x);
        
        Integer a, b;
        while(pq.size() > 1) {
            a = pq.poll();
            b = pq.poll();
            if(Math.abs(a-b) == 0) continue;
            pq.add(Math.abs(a-b));
        }
        
        return (pq.size() == 0) ? 0 : pq.peek();
    }
}
