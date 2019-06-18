struct Node {
    int value, label;
    Node (int val, int lab) : value(val), label(lab) {}

    bool operator<(const Node& other) {
        return value < other.value;
    }
};

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        
        unordered_map<int,int>mapfreq;
        priority_queue<Node>pq;

        for(int i = 0; i < values.size(); i++) {
            mapfreq[labels[i]]++;
            
            Node temp = {values[i], labels[i]};
            pq.push(temp );
        }
        return 0;
    }
};