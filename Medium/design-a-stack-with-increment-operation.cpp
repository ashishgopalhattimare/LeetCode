// https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Medium

class CustomStack {
public:
    
    vector<int>arr, incArr;
    int index;
    
    CustomStack(int maxSize) { // O(1)
        
        incArr = vector<int>(maxSize, 0);
        arr = vector<int>(maxSize, 0);
        
        index = 0;
    }
    
    void push(int x) { // O(1)
        
        if(index != arr.size()) {
            incArr[index] = 0; // Safety reset
            arr[index++] = x;
        }
    }
    
    int pop() { // O(1)
        
        // Empty Stack
        if(index == 0) return -1;
        
        // Get the accumulative sum
        int result = arr[index-1] + incArr[index-1];
        
        // increment shift to lower index;
        // if index > 1
        if(index > 1) {
            incArr[index-2] += incArr[index-1];
        }
        
        incArr[--index] == 0; // pop index is assigned 0 value
        
        return result;
    }
    
    void increment(int k, int val) { // O(1)
        
        // Empty Stack
        if(index == 0) return;
        
        // Can be concised to single line, if working
        incArr[min(k, index)-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */