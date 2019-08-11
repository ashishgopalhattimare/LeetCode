// https://leetcode.com/problems/largest-values-from-labels/
// Medium, Weekly Contest 141

// Approach
// Priority_Queue for maxHeap of values
// Map for maintaining not to take same label value more than use_limit

struct Node {
    int value, label;
    Node (int val, int lab) : value(val), label(lab) {}

    bool operator<(const Node& other) const {
        return value < other.value;
    }
};

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {

        unordered_map<int,int>map;
        priority_queue<Node>pq;

        for(int i = 0; i < values.size(); i++)
            pq.push( {values[i], labels[i]} );

        int result = 0;
        while(num_wanted && !pq.empty()) {
            Node curr = pq.top();
            pq.pop();
            if(map[curr.label] != use_limit) {
            	result += curr.value;
            	map[curr.label]++;
            	num_wanted--;
            }
        }
        return result;
    }
};
