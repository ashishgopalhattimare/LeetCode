// https://leetcode.com/problems/count-number-of-nice-subarrays/
// Medium

class Solution {
public:

	int min(int x, int y) { return (x < y) ? x : y; }
	int max(int x, int y) { return (x > y) ? x : y; }

	// Allow low to find next Odd
	// Find nextOdd for right len
	int indexNextOdd(vector<int>& nums, int index) {
        
		while(index < nums.size()) {
			if(nums[index] % 2 == 1)
				return index;
			index++;
		}
		return min(index, nums.size());
	}

	// Find prevOdd for left len
	int indexPrevOdd(vector<int>& nums, int index) {

		while(index >= 0) {
			if(nums[index] % 2 == 1)
				return index+1;
			index--;
		}

		return max(index, 0);
	}

    int numberOfSubarrays(vector<int>& nums, int k) {

        int countOdd = 0, result = 0;
        int prev = 0; // index of the last element after the high element
        int next = 0; // index of the prev element before the low element

        int left, right;

        for(int low = -1, high = 0; high < nums.size(); high++) {

        	// Increment countOdd if the last bit is 1
            if(nums[high] % 2 == 1) {
            	// If the new low end of the sub-array is not set
            	// set it
            	if(low == -1) low = high;
            	countOdd++;
            }

            if(countOdd == k) { // [low, high] is the minimum subarray with K odd elements

            	if(next <= high)// if the highEnd is not updated
            		next = indexNextOdd(nums, high+1);

            	// printf("prev : %d, low : %d, high : %d, next : %d\n", prev, low, high, next);

            	left = abs(prev-low); right = abs(next-high-1);

            	result += (1 + left + right + left*right);

            	low = indexNextOdd(nums, low+1); // next low index calculate
            	prev = indexPrevOdd(nums, low-1);// prev index calculate

            	countOdd--;
            }
        }

        return result;
    }
};