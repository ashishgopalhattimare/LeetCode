// https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Easy

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // minHeap
    int maxSize; // minHeap size
public:    
    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for(int x : nums) add(x);
    }
    
    int add(int val) {
        if(pq.size() < maxSize) pq.push(val);
        else {
            if(val > pq.top()) {
                pq.pop(); pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// 2 4 4 5 5 8