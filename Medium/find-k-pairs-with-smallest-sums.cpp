// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// Medium
// Priority Queue (Max Heap) NLogK

struct Node {
    int d1, d2;
    
    int value() const {
        return d1 + d2;
    }
    
    // MaxHeap Property
    bool operator<(const Node& o) const {
        return (d1 + d2) < (o.d1 + o.d2);
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<Node>pq;
        int sum;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                sum = nums1[i] + nums2[j];
                
                if(pq.size() < k) pq.push({nums1[i], nums2[j]});
                else {
                    if((pq.top()).value() > sum) {
                        pq.pop();
                        pq.push({nums1[i], nums2[j]});
                    }
                }
            }
        }
        
        vector<vector<int>>result(pq.size());
        Node curr;
        int i = 0;
        while(!pq.empty()) {
            curr = pq.top();
            pq.pop();
            
            result[i++] = {curr.d1, curr.d2};
        }
        
        return result;
    }
};
