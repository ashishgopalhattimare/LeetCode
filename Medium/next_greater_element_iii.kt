// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
    fun nextGreaterElement(n: Int): Int {

        if(n in 0..9) return -1

        var nums = (n.toString()).toCharArray()
        var change : Boolean = false;

        for(i in nums.size-2 downTo 0) {
            if(nums[i] < nums[i+1]) {
                
                for(j in nums.size-1 downTo i+1) {
                    if(nums[i] < nums[j]) {
                        with(nums[i]) {
                            nums[i] = nums[j]
                            nums[j] = this
                        }
                        nums.sort(i+1, nums.size)
                        break;
                    }
                }
                change = true
                break;
            }
        }

        if(change) {
            try {
                return nums.joinToString("").toInt()
            }catch (e : Exception) { return -1}
        }

        return -1
    }
}
