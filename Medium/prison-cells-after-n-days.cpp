// https://leetcode.com/problems/prison-cells-after-n-days/submissions/

class Solution {
public:
    
    // Generate the value from the binary vector
    int value(vector<int>& cells) {
        int value = 0;
        for(int i = cells.size()-1; i >= 0; i--) {
            if(cells[i])
                value += pow(2, 7-i);
        }
        return value;
    }
    
    // Generate the binary vector from the value
    vector<int> generateResult(vector<int>& result, int value) {
        for(int i = 0; i < result.size(); i++) result[i] = 0;
        for(int i = result.size()-1; i >= 0; i--) {
            result[i] = value%2;
            value/=2;
        }
        return result;
    }
    
    vector<int> prisonAfterNDays(vector<int> cells, int N) {
        vector<int>result = cells;
        
        int currValue = value(cells); // current Value
        int nextValue;                // next value
        vector<int>hashMap(260, 0);   // Maximum 256 possibilities : 2^8 (used to look for circular loop)
        vector<int>arr;               // Append values into the vector if no loop created;
        
        // Push the initial value into the arr vector
        arr.push_back(currValue);
        
        bool loop = false;
        for(int i = 0; i < 256 && i < N; i++) {
            for(int i = 1; i != cells.size()-1; i++) {
                result[i] = (cells[i-1] == cells[i+1]);
            }
            result[0] = result[cells.size()-1] = 0;
            
            // Get the next value to be checked
            nextValue = value(result);
            
            // Push the next value into the arr vector
            arr.push_back(nextValue);
            
            // Map the curr value to nextValue
            // currvalue is generating nextValue
            hashMap[currValue] = nextValue;
            
            // Next Iteration Values
            currValue = nextValue;
            cells = result;
            
            // Look for any loop created
            if(hashMap[currValue]) {loop = true; break; }
        }
        
        // If no loop created, the nextValue is the possible resultant binary vector
        if(!loop) {
            // printf("%d %d\n", currValue, nextValue);
            return generateResult(result, nextValue);
        }
        
        // If loop created, pop the last value to remove the loop
        arr.pop_back();
        int loopstart = -1;
        
        // Find the next of the first encounter with the circular looping element
        for(int i = 0; i < arr.size() && loopstart == -1; i++) {
            if(arr[i] == currValue) loopstart = i;
        }
        // new array size created
        int newSize = arr.size()-loopstart;
        
        return generateResult(result, arr[(N-loopstart)%newSize+loopstart]);
    }
};
