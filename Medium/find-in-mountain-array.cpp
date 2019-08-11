// https://leetcode.com/problems/find-in-mountain-array/
// Hard
// N = 10000
// Maximum iterations : 100
// O(nlogn)

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    
    // Find the peak element using binary search
    int getIndex(int start, int end, MountainArray &mountainArr) {
        if(start == end || end == start+1) return -1;
        
        int mid = start + (end-start)/2;
        
        int before  = mountainArr.get(mid-1);
        int current = mountainArr.get(mid);
        int after   = mountainArr.get(mid+1);
        
        if(before < current && current > after) return mid;
        
        if(before < current && current < after) {
            return getIndex(mid, end, mountainArr);
        }
        return getIndex(start, mid, mountainArr);
    }
    
    // Look for the element index in the array
    int binary_search(int start, int end, int target, int factor, MountainArray &mountainArr) {
        if(start > end) return -1;
        
        int mid = start + (end-start)/2;
        if(target*factor == mountainArr.get(mid)*factor) return mid;
        
        if(target*factor < mountainArr.get(mid)*factor)
            return binary_search(start, mid-1, target, factor, mountainArr);
        return binary_search(mid+1, end, target, factor, mountainArr);
        
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int mountainIndex = getIndex(0, mountainArr.length()-1, mountainArr);
        
        if(mountainIndex == -1) return -1;
        
        int index = binary_search(0, mountainIndex, target, 1, mountainArr);
        if(index != -1) return index;
        
        return binary_search(mountainIndex, mountainArr.length()-1, target, -1, mountainArr);
    }
};
