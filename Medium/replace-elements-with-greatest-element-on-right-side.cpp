// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
// Easy

class Solution {
public:
    Solution() {}

    vector<int> replaceElement(vector<int>& arr) {
        
        int temp, maxElement = -1;
        for(int i = arr.size()-1; i >= 0; i--) {
            temp = arr[i];
            arr[i] = maxElement;

            maxElement = max(maxElement, temp);
        }

        return arr;
    }
};