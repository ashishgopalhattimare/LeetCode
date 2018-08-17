// https://leetcode.com/problems/task-scheduler/description/

// CPUtask1.cpp -> in sorting using sorting method

class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        
        if(tasks.size() == 0) return 0;
        
        int intervals, taskCount, counter;
        int hash[26];
        for(int i = 0; i < 26; i++) hash[i] = 0;
        
        for(int i = 0; i < tasks.size(); i++) { // O(n) insertion in the hash table
            hash[tasks[i]-'A']++;
        }
        
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++) { // O(nlogn)
            if(hash[i]) {
                pq.push(hash[i]);
            }
        }
        
        taskCount = intervals = 0;
        list<int> v;
        while(!pq.empty()) {
            
            counter = 0;
            while(!pq.empty() && counter <= n) {
                counter++;
                taskCount++;
                intervals++;
                
                if(pq.top() > 1) {
                    v.push_back(pq.top());
                }
                pq.pop();
            }
            
            if(taskCount < tasks.size() && counter <= n) {
                intervals += (n - counter + 1);
            }
            
            while(v.size()) {
                pq.push(v.front() - 1);
                v.pop_front();
            }
        }
        
        return intervals;
    }
};
