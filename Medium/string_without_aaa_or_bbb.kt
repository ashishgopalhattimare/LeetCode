// https://leetcode.com/problems/string-without-aaa-or-bbb/

import kotlin.math.abs
import kotlin.math.min

class Solution {
    fun strWithout3a3b(A: Int, B: Int): String {
        
        var result = StringBuilder()
        var minim = 2 * min(A, B)

        var freqArray = mutableListOf<Int>();
        while(minim-- > 0) {
            freqArray.add(1)
        }
        
        var i = 0
        minim = abs(A-B)
        while(i < freqArray.size && minim > 0) {
            freqArray[i]++
            minim--
            i+=2
        }
        if(minim > 0) freqArray.add(minim)
        
        var aturn = (A > B)
        for( x in freqArray) {
            when(aturn) {
                true -> {
                    if(x == 2) result.append("aa")
                    else result.append("a")
                }
                false-> {
                    if(x == 2) result.append("bb")
                    else result.append("b")
                }
            }
            aturn = !aturn
        }

        return result.toString()
    }
}
