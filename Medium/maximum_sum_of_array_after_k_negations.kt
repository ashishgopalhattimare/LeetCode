// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

import java.util.*

class Solution {
    fun largestSumAfterKNegations(A: IntArray, K: Int) : Int {
        
        var priorityQueue = PriorityQueue<Int>()
        var result : Int = 0
        var value : Int

        priorityQueue.addAll(A.toList())

        for(x in 0 until K) {
            value = priorityQueue.poll()
            priorityQueue.add(-value)
        }

        while(!priorityQueue.isEmpty()) {
            result += priorityQueue.poll()
        }

        return result
    }
}
