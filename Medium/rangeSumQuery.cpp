// https://leetcode.com/problems/range-sum-query-mutable/description/

class NumArray {
public:
    
    int low, high;
    vector<int>tree;
    
    
    int segmentTree(int start, int end, vector<int>& nums, int index)
    {
        if(start == end) {
            tree[index] = nums[start];
            return tree[index];
        }
        
        int mid = start + (end - start)/2;
        
        tree[index] = segmentTree(start, mid, nums, 2*index+1) + segmentTree(mid+1, end, nums, 2*index+2);
        
        return tree[index];
    }
    
    int sumSegment(int start, int end, int qs, int qe, int index)
    {
        if(qs <= start && end <= qe) {
            return tree[index];
        }
        // !(start <= qe && qs <= end) === (start > qe || qs > end)
        if(start > qe || end < qs) { // out of range
            return 0;
        }
        
        int mid = start  + (end - start)/2;
        
        return sumSegment(start, mid, qs, qe, 2*index+1) + sumSegment(mid+1, end, qs, qe, 2*index+2);
    }
    
    int updateSegment(int start, int end, int i, int val, int index)
    {
        if(start == end && start == i) {
            tree[index] = val;
            return tree[index];
        }
        
        if(start > i || i > end) return tree[index];
        
        int mid = start + (end - start)/2;
        
        tree[index] = updateSegment(start, mid, i, val, 2*index+1) + updateSegment(mid+1, end, i, val, 2*index+2);
        
        return tree[index];
    }
    
    NumArray(vector<int> nums) {
        
        tree = vector<int>(3 * nums.size());
        
        low = 0;
        high = nums.size();
        
        if(high) {
            int sum = segmentTree(low, high-1, nums, 0);
        }
    }
    
    void update(int i, int val) {
        
        if(high == 0) return;
        
        int sum = updateSegment(low, high-1, i, val, 0);
    }
    
    int sumRange(int i, int j) {
        
        if(high == 0) return NULL;
        return sumSegment(low, high-1, i, j, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */